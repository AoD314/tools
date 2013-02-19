
#ifndef __matrix_resize_hpp__
#define __matrix_resize_hpp__

#include <opencv2/opencv.hpp>

cv::Mat matrix_resize(cv::Mat orig, int w, int h);

/*
for (int i = 1000; i < 1000 + c; i+=2)
{
    cv::imwrite(cv::format("png/output_%dx%d_%04d.png", w, h, j), read_and_resize(cv::format("/work/projects/bbb/big_buck_bunny_0%d.png", i), w, h));
    std::cout << "frame : " << j + 1 << std::endl;
    j++;
}
*/
#endif
