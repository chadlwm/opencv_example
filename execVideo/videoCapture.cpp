#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
  // open first video devise
  // VideoCapture cap(0);

  // open video file
  if (argc != 2) {
    printf("./VideoCapture <VideoPath>\n");
    return -1;
  }

  VideoCapture cap(argv[1]);
  if (!cap.isOpened()) {
    cerr << "Cannot open a camera or file" << endl;
    return -1;
  }

  Mat edges;
  // create window
  namedWindow("RAW", WINDOW_AUTOSIZE);
  namedWindow("Edges", WINDOW_AUTOSIZE);

  for (;;) {
    Mat frame;
    // read one frame from cap
    cap >> frame;
    if (frame.empty())
      break;
    cvtColor(frame, edges, CV_BGR2GRAY);
    Canny(edges, edges, 10, 40, 3);
    imshow("RAW", frame);
    imshow("Edges", edges);
    if (waitKey(41) >= 0)
      break;
  }

  // auto relase resources when exit
  return 0;
}