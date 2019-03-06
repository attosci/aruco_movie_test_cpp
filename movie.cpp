#include "aruco.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
int main(int argc, char **argv) {
  cv::VideoCapture cap(0);
  cv::Size size(
    (int)cap.get(CV_CAP_PROP_FRAME_WIDTH),
    (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)
  );
  std::cout << "size: " << size << std::endl;
  cv::VideoWriter writer;
  writer.open(argv[1], CV_FOURCC('M', 'J', 'P', 'G'), 5, size);
  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty()) {
      std::cout << "no frame, exit" << std::endl;
      break;
    }
    aruco::MarkerDetector MDetector;
    std::vector<aruco::Marker> markers=MDetector.detect(frame);
    for (size_t i = 0; i < markers.size(); i++) {
      std::cout << markers[i] << std::endl;
      markers[i].draw(frame);
    }
    writer << frame;

    for (size_t i = 0; i < 5; i++) {
      cap >> frame;
    }
  }
  cap.release();
  writer.release();
}
