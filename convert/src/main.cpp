
#include <opencv2/opencv.hpp>
#include <string>
#include "settings.hpp"
#include "get_stat.hpp"

int main(int argc, char ** argv)
{
    Settings settings(argc, argv);
    if (settings.is_exit) return 0;

    std::string input  = settings.input;
    std::string output = "";

    for(int q = 0; q < 10; q++)
    {
        output = input + cv::format(".compress_.%d.png", q);
        get_stat(input, output, q);
    }

    for(int q = 50; q <= 100; q+=5)
    {
        output = input + cv::format(".quality_.%03d.jpg", q);
        get_stat(input, output, q);
    }

    /*
    for(int q = 50; q <= 100; q+=5)
    {
        output = input + cv::format(".quality_.%03d.jp2", q);
        get_stat(input, output, q);
    }
    */

    for(int q = 50; q <= 105; q+=5)
    {
        output = input + cv::format(".quality_.%03d.webp", q);
        if (q > 100)
        {
            output = input + ".lossless.webp";
        }

        get_stat(input, output, q);
    }

    return 0;
}
