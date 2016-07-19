
#include <iostream>
#include "settings.hpp"
#include <opencv2/opencv.hpp>

const std::string keys =
{
    "{     help    |  false      |  help info           }"
    "{  i  input   | 0005.png    |  input               }"
    "{  o  output  | img         |  output              }"
    "{  c  count   |      1      |  count               }"
    "{  s  start   |      0      |  start               }"
    "{  w  width   |   4096      |  width               }"
    "{  h  height  |   4096      |  height              }"
    "{  b  bitrate |     -1      |  bitrate             }"
    "{  t  threads |      6      |  threads count       }"
    "{  f  fps     |   30.0      |  fps                 }"
};

Settings::Settings(int argc, char ** argv)
{
    is_exit = false;

    cv::CommandLineParser parser(argc, argv, keys);

    fps      = parser.get<float>("f");

    width    = parser.get<int>("w");
    height   = parser.get<int>("h");

    threads  = parser.get<int>("t");

    input    = parser.get<std::string>("i");
    output   = parser.get<std::string>("o");
    count    = parser.get<int>("c");
    start    = parser.get<int>("s");

    bitrate = static_cast<int64_t>(parser.get<unsigned int>("b"));
    if (bitrate == -1)
    {
        bitrate = static_cast<int64_t>(
                    static_cast<double>(width) / 3.0 *
                    static_cast<double>(height) * 2.0 / 1024.0 * static_cast<double>(fps) );
    }

    // check error
    if (parser.get<bool>("help"))
    {
        is_exit = true;
        parser.printMessage();
    }
    else
    {
        // print stat
        //*/
        std::cout << "STAT:" << std::endl;
        std::cout << "\tinput     : " << input   << std::endl;
        std::cout << "\toutput    : " << output  << std::endl;
        std::cout << "\twidth     : " << width   << std::endl;
        std::cout << "\theight    : " << height  << std::endl;
        std::cout << "\tbitrate   : " << bitrate << std::endl;
        std::cout << "\tthreads   : " << threads << std::endl;
        std::cout << "\tfps       : " << fps     << std::endl;
        //*/
    }

}

void print_progress(int i, int count)
{
    i++;
    float pr = 100.0f * static_cast<float>(i) / static_cast<float>(count);
    std::cout << cv::format("progress : %6.2f", pr) << "%        ";
    std::cout << cv::format("[%6d / %6d]    (%6d)", i, count, count - i);
    std::cout << std::endl;
}
