#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("./VideoWrite <VideoPath>\n");
    return -1;
  }

  Size s(320, 240);
  VideoWriter writer =
      VideoWriter(argv[1], CV_FOURCC('M', 'J', 'P', 'G'), 25, s, true);
  if (!writer.isOpened()) {
    cerr << "Cannot create video file." << endl;
    return -1;
  }

  Mat frame(s, CV_8UC3);
  for (int i = 0; i < 25 * 10; i++) {
    frame = Scalar::all(0);
    char text[128];
    snprintf(text, sizeof(text), "%d", i);
    putText(frame, text, Point(s.width / 2 - 50, s.height / 2),
            FONT_HERSHEY_SCRIPT_SIMPLEX, 3, Scalar(0, 0, 255), 3, 8);
    writer << frame;
  }

  // auto relase resources when exit
  return 0;
}