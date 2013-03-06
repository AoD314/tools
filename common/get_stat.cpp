
#include <iostream>
#include <fstream>

#include "get_stat.hpp"
#include "save_image.hpp"

void get_stat(std::string orig, std::string save, int compress)
{
    cv::Mat mat_save;
    cv::Mat mat_orig = cv::imread(orig);
    cv::TickMeter timer;

    std::cout << cv::format("image orig: %s", orig.c_str()) << std::endl;
    std::cout << cv::format("image save: %s(%d)", save.c_str(), compress) << std::endl;

    timer.start();

    for(int i = 0; i < count_repeat; ++i)
    {
        save_image(save, mat_orig, compress);
    }

    timer.stop();

    float t = timer.getTimeSec() / static_cast<float>(count_repeat);
    std::cout << cv::format("time encode(sec): %8.5f", t) << std::endl;
    timer.reset();


    timer.start();

    for(int i = 0; i < count_repeat; ++i)
    {
        mat_save = cv::imread(save);
    }

    timer.stop();

    t = timer.getTimeSec() / static_cast<float>(count_repeat);
    std::cout << cv::format("time decode(sec): %8.5f", t) << std::endl;

    double psnr = get_psnr(mat_orig, mat_save);
    std::cout << cv::format("PSNR            : %8.5f", psnr) << std::endl;

    size_t or_b = get_filesize(orig);
    float  or_k = static_cast<float>(or_b) / (1024.0);
    size_t sv_b = get_filesize(save);
    float  sv_k = static_cast<float>(sv_b) / (1024.0);

    std::cout << cv::format("size orig       : %10d bytes ~ %10.2f Kb", or_b, or_k) << std::endl;
    std::cout << cv::format("size save       : %10d bytes ~ %10.2f Kb", sv_b, sv_k) << std::endl;
    std::cout << cv::format("save/orig       : %6.2f times", or_k/sv_k) << std::endl << std::endl;;

}

double get_psnr(cv::Mat img1, cv::Mat img2)
{
    return cv::PSNR(img1, img2);
}

size_t get_filesize(std::string name)
{
    size_t begin, end;
    std::ifstream file(name.c_str());
    begin = file.tellg();
    file.seekg (0, std::ios::end);
    end = file.tellg();
    file.close();
    return (end - begin);
}
