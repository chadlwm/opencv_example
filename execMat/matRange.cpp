#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  //创建一个单位阵
  Mat A = Mat::eye(10, 10, CV_32S);
  //提取第 1 到 3 列(不包括 3)
  Mat B = A(Range::all(), Range(1, 3));
  //提取 B 的第 5 至 9 行(不包括 9)
  //其实等价于 C = A(Range(5, 9), Range(1, 3))
  Mat C = B(Range(5, 9), Range::all());

  cout << "A=" << endl << A << endl;
  cout << "B=" << endl << B << endl;
  cout << "C=" << endl << C << endl;

  //创建宽度为 320,高度为 240 的 3 通道图像
  Mat img(Size(320, 240), CV_8UC3);
  // roi 是表示 img 中 Rect(10,10,100,100)区域的对象
  Mat roi(img, Rect(10, 10, 100, 100));

  if (argc != 2) {
    printf("usage: ./MatRange <ImagePath>\n");
    return -1;
  }

  Mat image;
  image = cv::imread(argv[1]);
  if (!image.data) {
    printf("No image data.\n");
    return -1;
  }
  Mat subImage = image(Rect(100, 100, 500, 500));

  namedWindow("Raw Image", cv::WINDOW_AUTOSIZE);
  namedWindow("Sub Image", cv::WINDOW_AUTOSIZE);
  imshow("Raw Image", image);
  imshow("Sub Image", subImage);

  waitKey(0);
  return 0;
}