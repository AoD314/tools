
#include "matrix_resize.hpp"

cv::Mat matrix_resize(cv::Mat orig, int w, int h)
{
	int c_w, c_h;
	c_w = (w / orig.cols) + 1;
	c_h = (h / orig.rows) + 1;

	cv::Mat mat(orig.rows * c_h, orig.cols * c_w, CV_8UC3);

	for (int x = 0; x < c_w; x++)
	{
		for (int y = 0; y < c_h; y++)
		{
			cv::Mat t = mat(cv::Rect(orig.cols * x, orig.rows * y, orig.cols, orig.rows));
			orig.copyTo(t);
		}
	}

	return mat(cv::Rect(0, 0, w, h));
}
