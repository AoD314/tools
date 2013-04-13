
#ifndef __save_image_hpp__
#define __save_image_hpp__

#include <opencv2/core.hpp>

enum IMAGE_TYPE
{
    PNG, JPEG, WEBP
};

class Saver
{
    public:
        Saver(std::string name, IMAGE_TYPE type = PNG);

        void save(cv::Mat img, int compress = 100, size_t index = -1);

    private:
        IMAGE_TYPE t;
        std::string filename;
        size_t idx;

        std::string get_full_name();
};

void save_image(std::string name, cv::Mat img, int compress = 100);

#endif
