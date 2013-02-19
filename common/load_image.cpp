
#include "load_image.hpp"

Loader::Loader(std::string name, int start_index)
{
    filename = name;
    idx = start_index;
}

std::string Loader::get_full_name()
{
    return cv::format(filename.c_str(), idx++);
}

cv::Mat Loader::load(size_t index)
{
    if (index != -1)
    {
        idx = index;
    }

    return cv::imread(get_full_name());
}
