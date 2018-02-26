#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./Candy <ImagePath>\n");
    return -1;
  }

  Mat image = imread(argv[1]);
  if (image.empty()) {
    printf("Cannot load image\n");
    return -1;
  }

  Mat result;
  Canny(image, result, 50, 100);
  imwrite("canny.png", result);

  return 0;
}