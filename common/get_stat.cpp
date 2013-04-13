
#include <iostream>
#include <fstream>

#include "opencv2/highgui.hpp"
#include "opencv2/contrib.hpp"

#include "get_stat.hpp"
#include "save_image.hpp"

void get_stat(std::string orig, std::string save, int compress)
{
    cv::Mat mat_save;
    cv::Mat mat_orig = cv::imread(orig);
    double time_enc, time_dec;
    cv::TickMeter timer;

    timer.start();

    for(int i = 0; i < count_repeat; ++i)
    {
        save_image(save, mat_orig, compress);
    }

    timer.stop();


    time_enc = timer.getTimeMilli() / static_cast<double>(count_repeat);
    timer.reset();


    timer.start();

    for(int i = 0; i < count_repeat; ++i)
    {
        mat_save = cv::imread(save);
    }

    timer.stop();

    time_dec = timer.getTimeMilli() / static_cast<double>(count_repeat);

    double psnr = cv::PSNR(mat_orig, mat_save);

    double save_size = static_cast<double>(get_filesize(save)) / (1024.0);

    save_image(save + ".bmp", mat_orig);

    double orig_size = static_cast<double>(get_filesize(save + ".bmp")) / (1024.0);

    std::cout << "{" << std::endl;

    std::cout << cv::format("format        :%s;\n",   save.substr(save.find_last_of('.')).c_str());
    std::cout << cv::format("params        :%d;\n",   compress);
    std::cout << cv::format("cmpr size(Kb) :%.8f;\n", save_size);
    std::cout << cv::format("orig size(Kb) :%.8f;\n", orig_size);
    std::cout << cv::format("enc  time(ms) :%.8f;\n", time_enc);
    std::cout << cv::format("dec  time(ms) :%.8f;\n", time_dec);
    std::cout << cv::format("PSNR          :%.8f;\n", psnr);
    std::cout << cv::format("width         :%d;\n", mat_orig.cols);
    std::cout << cv::format("heigth        :%d;\n", mat_orig.rows);

    std::cout << "}" << std::endl;

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
