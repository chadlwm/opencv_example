#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  Mat A = Mat::eye(4, 4, CV_32SC1);
  Mat B = A * 3 + 1;
  Mat C = B.diag(0) + B.col(1);

  cout << "A = " << A << endl << endl;
  cout << "B = " << B << endl << endl;
  cout << "C = " << C << endl << endl;
  cout << "C .* diag(B) = " << C.dot(B.diag(0)) << endl;

  return 0;
}