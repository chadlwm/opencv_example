#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  Mat grayim(600, 800, CV_8UC1);
  Mat colorim(600, 800, CV_8UC3);

  //遍历所有像素,并设置像素值
  for (int i = 0; i < grayim.rows; ++i)
    for (int j = 0; j < grayim.cols; ++j)
      grayim.at<uchar>(i, j) = (i + j) % 255;

  //遍历所有像素,并设置像素值
  for (int i = 0; i < colorim.rows; ++i)
    for (int j = 0; j < colorim.cols; ++j) {
      Vec3b pixel;
      pixel[0] = i % 255; // Blue
      pixel[1] = j % 255; // Green
      pixel[2] = 0;
      // Red
      colorim.at<Vec3b>(i, j) = pixel;
    }

  //显示结果
  imshow("grayim", grayim);
  imshow("colorim", colorim);

  waitKey(0);
  return 0;
}