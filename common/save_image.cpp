
#include "save_image.hpp"

Saver::Saver(std::string name, IMAGE_TYPE type):
    t(type), filename(name), idx(0) { }

std::string Saver::get_full_name()
{
	std::string ext;

	if (t == PNG)  ext = "png";
	if (t == JPEG) ext = "jpeg";
	if (t == WEBP) ext = "webp";

    return cv::format("%s_%08d.%s", filename.c_str(), idx++, ext.c_str());
}

void save_image(std::string name, cv::Mat img, int compress)
{
    std::string ext = name.substr(name.find_last_of(".") + 1);
    if (ext.compare("png") == 0)
    {
        std::vector<int> compression_params;
        compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
        compression_params.push_back(9);
        cv::imwrite(name, img, compression_params);
    }
    else if (ext.compare("jpg") == 0 || ext.compare("jpeg") == 0)
    {
        std::vector<int> compression_params;
        compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
        compression_params.push_back(compress);
        cv::imwrite(name, img, compression_params);
    }
    else if (ext.compare("webp") == 0)
    {        
        std::vector<int> compression_params;
        compression_params.push_back(CV_IMWRITE_WEBP_QUALITY);
        compression_params.push_back(compress);

        if (compress == -1)
        {
            cv::imwrite(name, img);
        }
        else
        {
            cv::imwrite(name, img, compression_params);
        }

    }
}

void Saver::save(cv::Mat img, int compress, size_t index)
{
    if (index != -1)
    {
        idx = index;
    }

	if (t == PNG)
	{
		std::vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(9);
		cv::imwrite(get_full_name(), img, compression_params);
	}
	else if (t == JPEG)
	{
		std::vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
        compression_params.push_back(compress);
		cv::imwrite(get_full_name(), img, compression_params);
	}
	else if (t == WEBP)
	{
        std::vector<int> compression_params;
        compression_params.push_back(CV_IMWRITE_WEBP_QUALITY);
        compression_params.push_back(compress);

        if (compress == -1)
        {
            cv::imwrite(get_full_name(), img);
        }
        else
        {
            cv::imwrite(get_full_name(), img, compression_params);
        }
	}
}

