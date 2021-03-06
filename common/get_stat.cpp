
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

#include "get_stat.hpp"
#include "save_image.hpp"

void get_stat(std::string orig, std::string save, int compress)
{
    cv::Mat mat_save;
    cv::Mat mat_orig = cv::imread(orig);
    double time_enc, time_dec;

    double timer = (double)cv::getTickCount();

    for(int i = 0; i < count_repeat; ++i)
    {
        save_image(save, mat_orig, compress);
    }

    double freq = cv::getTickFrequency();

    time_enc = (((double)cv::getTickCount() - timer)/freq) / static_cast<double>(count_repeat);


    timer = (double)cv::getTickCount();

    for(int i = 0; i < count_repeat; ++i)
    {
        mat_save = cv::imread(save);
    }

    time_dec = (((double)cv::getTickCount() - timer)/freq) / static_cast<double>(count_repeat);

    double psnr = cv::PSNR(mat_orig, mat_save);

    double save_size = static_cast<double>(get_filesize(save)) / (1024.0);

    save_image(save + ".bmp", mat_orig);

    double orig_size = static_cast<double>(get_filesize(save + ".bmp")) / (1024.0);

    std::cout << "{" << std::endl;

    std::cout << std::string(cv::format("format        :%s;\n",   save.substr(save.find_last_of('.')).c_str()));
    std::cout << std::string(cv::format("params        :%d;\n",   compress));
    std::cout << std::string(cv::format("cmpr size(Kb) :%.8f;\n", save_size));
    std::cout << std::string(cv::format("orig size(Kb) :%.8f;\n", orig_size));
    std::cout << std::string(cv::format("enc  time(ms) :%.8f;\n", time_enc));
    std::cout << std::string(cv::format("dec  time(ms) :%.8f;\n", time_dec));
    std::cout << std::string(cv::format("PSNR          :%.8f;\n", psnr));
    std::cout << std::string(cv::format("width         :%d;\n", mat_orig.cols));
    std::cout << std::string(cv::format("heigth        :%d;\n", mat_orig.rows));

    std::cout << "}\n";

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
