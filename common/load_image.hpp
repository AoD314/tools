
#ifndef __load_image_hpp__
#define __load_image_hpp__

#include <opencv2/opencv.hpp>

class Loader
{
    public:
        Loader(std::string name, int start_index = 0);

        cv::Mat load(size_t index = -1);

    private:
        std::string filename;
        size_t idx;

        std::string get_full_name();
};

#endif
