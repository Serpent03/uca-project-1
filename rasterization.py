import cv2
from os import listdir

# read imgs, resize to
# definition sizes

rw, rh = 80, 30

imgPath = './img/'
outPath = './out/'

inPath = listdir(imgPath)
ctr = 1


for i in range(len(inPath)-1):
    file = i + 1
    im = cv2.imread(f'{imgPath}{file}.png')
    grayImage = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
  
    (thresh, blackAndWhiteImage) = cv2.threshold(grayImage, 127, 255, cv2.THRESH_BINARY)
    goodRes = cv2.resize(blackAndWhiteImage, (rw, rh), interpolation=cv2.INTER_LINEAR)

    with open(f'{outPath}{ctr}.txt', 'w+') as f:
        for height in goodRes:
            for width in height:
                num = 1 if width == 255 else 0
                f.write(f"{num}")
    ctr += 1

print("finished")