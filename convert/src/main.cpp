
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

    std::string bmp = "test_orig.bmp";
    cv::Mat img = cv::imread(input);
    cv::imwrite(bmp, img);
    size_t s = get_filesize(bmp);
    double uncompess_k = static_cast<double>(s) / (1024.0);

    std::cout << cv::format("\norig size(Kb) : %.2f\n\n", uncompess_k);

    /*
    for(int q = 0; q < 10; q++)
    {
        output = input + cv::format(".compress_.%d.png", q);
        get_stat(input, output, q);
    }
    */

    //*/
    for(int q = 50; q <= 100; q+=10)
    {
        output = input + cv::format(".quality_.%03d.jpeg", q);
        get_stat(input, output, q);
    }
    //*/

    for(int q = 50; q <= 101; q+=10)
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
