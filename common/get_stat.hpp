
#ifndef __get_stat_hpp__
#define __get_stat_hpp__

#include <string>
#include <opencv2/opencv.hpp>

const int count_repeat = 15;

void get_stat(std::string orig, std::string save, int compress = 100);

double get_psnr(cv::Mat img1, cv::Mat img2);

size_t get_filesize(std::string name);

#endif
