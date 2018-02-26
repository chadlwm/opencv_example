#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  Mat grayim(600, 800, CV_8UC1);
  Mat colorim(600, 800, CV_8UC3);

  //遍历所有像素,并设置像素值
  MatIterator_<uchar> grayit, grayend;
  for (grayit = grayim.begin<uchar>(), grayend = grayim.end<uchar>();
       grayit != grayend; ++grayit)
    *grayit = rand() % 255;

  //遍历所有像素,并设置像素值
  MatIterator_<Vec3b> colorit, colorend;
  for (colorit = colorim.begin<Vec3b>(), colorend = colorim.end<Vec3b>();
       colorit != colorend; ++colorit) {
    (*colorit)[0] = rand() % 255; // Blue
    (*colorit)[1] = rand() % 255; // Green
    (*colorit)[2] = rand() % 255; // Red
  }

  //显示结果
  imshow("grayim", grayim);
  imshow("colorim", colorim);

  waitKey(0);
  return 0;
}