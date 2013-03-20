
#ifndef __get_stat_hpp__
#define __get_stat_hpp__

#include <string>
#include <opencv2/opencv.hpp>

const int count_repeat = 25;

void get_stat(std::string orig, std::string save, int compress = 100);

size_t get_filesize(std::string name);

#endif
