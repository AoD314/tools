
#ifndef __settings_hpp__
#define __settings_hpp__

#include <string>

class Settings
{
    public:
        Settings(int argc, char ** argv);

        bool is_exit;

        std::string input;
        std::string output;

        int count;
        int start;
        int width;
        int height;
        unsigned int bitrate;

        float fps;
        int frame_count;
        int threads;



};

void print_progress(int i, int count);

#endif
