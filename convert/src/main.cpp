
#include <opencv2/opencv.hpp>
#include <string>
#include "settings.hpp"
#include "get_stat.hpp"

int main(int argc, char ** argv)
{
    Settings settings(argc, argv);
    if (settings.is_exit) return 0;

    std::string input  = settings.input;

    get_stat(input, input + ".png");

    for(int q = 100; q >= 10; q-=10)
    {
        get_stat(input, input + "." + cv::format("%d", q) + ".jpg", q);
    }

    for(int q = 100; q >= 10; q-=10)
    {
        get_stat(input, input + "." + cv::format("%d", q) + ".webp", q);
    }

    return 0;
}
