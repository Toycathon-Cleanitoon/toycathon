

import cv2
import torchvision.transforms as transforms
from pathlib import Path
from PIL import Image
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision.models as models


class ImageClassificationBase(nn.Module):
    def training_step(self, batch):
        images, labels = batch
        out = self(images)                  # Generate predictions
        loss = F.cross_entropy(out, labels)  # Calculate loss
        return loss


class ResNet(ImageClassificationBase):
    def __init__(self):
        super().__init__()
        # Use a pretrained model
        self.network = models.resnet50(pretrained=False)
        # Replace last layer
        num_ftrs = self.network.fc.in_features
        self.network.fc = nn.Linear(num_ftrs, 6)

    def forward(self, xb):
        return torch.sigmoid(self.network(xb))


model = ResNet()

model.load_state_dict(torch.load(
    'model.pth', map_location=torch.device('cpu')))

classes = ['metal', 'paper', 'glass', 'trash', 'plastic', 'cardboard']


def predict_image(img, model):
    xb = img.unsqueeze(0)
    yb = model(xb)
    prob, preds = torch.max(yb, dim=1)
    return classes[preds[0].item()]


transformations = transforms.Compose(
    [transforms.Resize((256, 256)), transforms.ToTensor()])


def predict_external_image(image_name):
    image = Image.open(Path('./' + image_name))

    example_image = transformations(image)
    plt.imshow(example_image.permute(1, 2, 0))
    print("The image resembles", predict_image(example_image, model) + ".")

if __name__ == "__main__":
    cap = cv2.VideoCapture(0)
    while(True):
        _, frame = cap.read()
        predict_external_image(frame)
