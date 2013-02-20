
#include "settings.hpp"
#include <opencv2/opencv.hpp>

const char * keys =
{
    "{      |  help  |  false      |  help info                                }"
    "{   i  |        | img_%8d.png |  input                                    }"
    "{   o  |        | img         |  output                                   }"
    "{   c  |        |      1      |  count                                    }"
    "{   s  |        |      0      |  start                                    }"
    "{   w  |        |   4096      |  width                                    }"
    "{   h  |        |   4096      |  height                                   }"
    "{   b  |        |     -1      |  bitrate                                  }"
    "{   t  |        |      4      |  threads count                            }"
    "{   f  |        |   30.0      |  fps                                      }"
};

Settings::Settings(int argc, char ** argv)
{
    is_exit = false;

    cv::CommandLineParser parser(argc, argv, keys);

    width   = parser.get<int>("w");
    height  = parser.get<int>("h");
    bitrate = parser.get<unsigned int>("b");
    if (bitrate == -1)
    {
        bitrate = static_cast<unsigned int>(
                    static_cast<float>(width) / 3.0 *
                    static_cast<float>(height) * 2.0 / 1024.0 * fps );
    }

    threads  = parser.get<int>("t");
    fps      = parser.get<float>("f");

    input    = parser.get<std::string>("i");
    output   = parser.get<std::string>("o");
    count    = parser.get<int>("c");
    start    = parser.get<int>("s");

    // check error
    if (parser.get<bool>("help"))
    {
        is_exit = true;
        parser.printParams();
    }
    else
    {
        // print stat
        std::cout << "STAT:" << std::endl;
        std::cout << "input     : " << input   << std::endl;
        std::cout << "output    : " << output  << std::endl;
        std::cout << "width     : " << width   << std::endl;
        std::cout << "height    : " << height  << std::endl;
        std::cout << "bitrate   : " << bitrate << std::endl;
        std::cout << "threads   : " << threads << std::endl;
        std::cout << "fps       : " << fps     << std::endl;
    }

}

void print_progress(int i, int count)
{
    i++;
    float pr = 100.0f * i / static_cast<float>(count);
    std::cout << cv::format("progress : %6.2f", pr) << "%";
    std::cout << cv::format("[%5d/%5d] (%5d)", i, count, count - i);
    std::cout << std::endl;
}






