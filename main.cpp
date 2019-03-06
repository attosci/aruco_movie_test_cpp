#include "aruco.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
int main(int argc, char **argv) {
  cv::Mat image;
  if (argc != 2) {
    cv::VideoCapture cap(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    if (!cap.isOpened()) {
      return -1;
    }
    cap >> image;
  } else {
    image = cv::imread(argv[1]);
  }
  aruco::MarkerDetector MDetector;
  // detect
  std::vector<aruco::Marker> markers=MDetector.detect(image);
  // print info to console
  for (size_t i = 0; i < markers.size(); i++) {
    std::cout << markers[i] << std::endl;
    // draw in the image
    markers[i].draw(image);
  }
  cv::imwrite("marked.jpg", image);
}
