#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  Mat grayim(600, 800, CV_8UC1);
  Mat colorim(600, 800, CV_8UC3);

  //遍历所有像素,并设置像素值
  for (int i = 0; i < grayim.rows; ++i) {
    //获取第 i 行首像素指针
    uchar *p = grayim.ptr<uchar>(i);
    //对第 i 行的每个像素(byte)操作
    for (int j = 0; j < grayim.cols; ++j)
      p[j] = (i + j) % 255;
  }

  //遍历所有像素,并设置像素值
  for (int i = 0; i < colorim.rows; ++i) {
    //获取第 i 行首像素指针
    Vec3b *p = colorim.ptr<Vec3b>(i);
    for (int j = 0; j < colorim.cols; ++j) {
      p[j][0] = i % 255; // Blue
      p[j][1] = j % 255; // Green
      p[j][2] = 0;
      // Red
    }
  }

  //显示结果
  imshow("grayim", grayim);
  imshow("colorim", colorim);

  waitKey(0);
  return 0;
}