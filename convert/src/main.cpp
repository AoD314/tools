
#include <opencv2/opencv.hpp>
#include <string>
#include "settings.hpp"
#include "get_stat.hpp"

int main(int argc, char ** argv)
{
    Settings settings(argc, argv);
    if (settings.is_exit) return 0;

    get_stat("img_00000000.png", "img_00000000.png.png");

    get_stat("img_00000000.png", "img_00000000.png.100.jpg", 100);
    get_stat("img_00000000.png", "img_00000000.png.90.jpg" ,  90);
    get_stat("img_00000000.png", "img_00000000.png.80.jpg" ,  80);
    get_stat("img_00000000.png", "img_00000000.png.70.jpg" ,  70);
    get_stat("img_00000000.png", "img_00000000.png.60.jpg" ,  60);
    get_stat("img_00000000.png", "img_00000000.png.50.jpg" ,  50);
    get_stat("img_00000000.png", "img_00000000.png.40.jpg" ,  40);
    get_stat("img_00000000.png", "img_00000000.png.30.jpg" ,  30);
    get_stat("img_00000000.png", "img_00000000.png.20.jpg" ,  20);
    get_stat("img_00000000.png", "img_00000000.png.10.jpg" ,  10);

    return 0;
}
