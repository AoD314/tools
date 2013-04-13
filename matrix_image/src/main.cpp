
#include <opencv2/core.hpp>

#include "load_image.hpp"
#include "save_image.hpp"
#include "settings.hpp"
#include "matrix_resize.hpp"

int main(int argc, char ** argv)
{
    Settings settings(argc, argv);
    if (settings.is_exit) return 0;

    int N = settings.count;
    int start = settings.start;

    Loader l(settings.input, start);
    Saver  s(settings.output, PNG);

    for (int i = 0; i < N; i++)
    {
        cv::Mat mat = matrix_resize(l.load(), settings.width, settings.height);
        s.save(mat);
        print_progress(i, N);
    }

    return 0;
}
