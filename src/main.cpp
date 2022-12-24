// Acceder a cada pixel de una imagen 
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

cv::Mat customGray(cv::Mat image);

int main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./gray <Image> \n";
		return -1;
	}
	cv::Mat image;
	image = imread(argv[1], cv::IMREAD_COLOR);
	if (!image.data)
	{
		std::cout<< "No image data \n";
		return -1;
	}
	cv::Mat gray;
	gray = customGray(image);
	namedWindow("Display Window", cv::WINDOW_AUTOSIZE);
	imshow("Display Window", gray);
	cv::waitKey(0);
	return 0;
}


cv::Mat customGray(cv::Mat image)
{
	int height = image.rows;
	int width = image.cols;
	int channels = image.channels();

	std::cout << "(" << width << "," <<height<< "," << channels << "";

	int rows = image.rows;
	int cols = image.cols;

	cv::Mat gray(image.rows, image.cols, CV_8UC1);

	// ------------
	// SAFE MODE 
	// ------------
	// for(int irows = 0; irows < rows; irows ++)
	// {
	// 	for(int icols = 0; icols < cols; icols ++)
	// 	{
	// 		cv::Vec3b colors = image.at<cv::Vec3b>(irows, icols);
	// 		uchar blue = colors.val[0];
	// 		uchar green = colors.val[1];
	// 		uchar red = colors.val[2];

	// 		// Magnitud
	// 		// double gray = sqrt(blue*blue + green*green + red*red);
	// 		// double gray = 0.33*blue + 0.33*green + 0.33*red;
	// 		double gray_value = 0.2*blue + 0.7*green + 0.1*red;
	// 		gray.at<uchar>(irows, icols) = char (gray_value);
	// 	}
	// }
	// std::cout << "(" << width << "," <<height<< "," << channels << "";
	// return gray;

	// ---------------
	// FAST MODE 
	// ----------------
	
	uchar *pixelPtr = (uchar*)image.data;
	uchar *pixelPtrGray = (uchar*)gray.data;
	for(int irows = 0; irows < rows; irows ++)
	{
		for(int icols = 0; icols < cols; icols ++)
		{
			uchar blue = pixelPtr[irows*cols*channels + icols*channels + 0];
			uchar green = pixelPtr[irows*cols*channels + icols*channels + 1];
			uchar red = pixelPtr[irows*cols*channels + icols*channels + 2];
			double gray_value = 0.2*blue + 0.7*green + 0.1*red;
			pixelPtrGray[irows*cols + icols] = gray_value;
		}
	}
	return gray;
}


