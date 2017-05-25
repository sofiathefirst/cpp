
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/legacy/legacy.hpp>
using namespace cv;
using namespace std;
int showimg(string imagename = "d:/img/lena.jpg")
{
	 
	Mat img = imread(imagename);
	//如果读入图像失败
	if (img.empty())
	{
		cout << "no this img!\n";
		return -1;
	}
	namedWindow("image", 1);
	imshow("image", img);
	waitKey();
	return 0;

}


void binaryImg(cv::Mat &image, int th)
{
	Mat img1;
	if (image.channels() == 3)
	{
		//创建目标图像  
		cvtColor(image, img1, CV_BGR2GRAY);
		image = img1;
		cout << img1.channels() << image.channels();
		cout << img1.rows << image.rows;
		cout << img1.cols << image.cols;
		imwrite("d:/bi2.png", image);
	}

	int i = 0, j = 0;
	for (i = 0; i < image.rows; i++)
		for (j = 0; j < image.cols; j++)
		{
		if (image.at<uchar>(i, j)>th)
			image.at<uchar>(i, j) = 255;
		else
			image.at<uchar>(i, j) = 0;
		}
}
int binaryImgtest()
{
	Mat image = cv::imread("d:/img/lena.jpg");
	binaryImg(image, 100);
	namedWindow("binaryImgtest");
	imshow("binaryImgtest", image);

	waitKey(0);
	return 0;
}
int createImg()
{
	Mat img(500, 1000, CV_8UC3, Scalar(255, 0, 0)); //create an image ( 3 channels, 8 bit image depth, 500 high, 1000 wide, (0, 0, 100) assigned for Blue, Green and Red plane respectively. )

	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		//system("pause"); //wait for a key press
		return -1;
	}

	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

	waitKey(0);  //wait infinite time for a keypress

	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}

int showvideofile(string videofile = "d:/img/a.avi")
{
	VideoCapture cap(videofile); // open the video file for reading

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	cout << "Frame per seconds : " << fps << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		imshow("MyVideoFram", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}

int showvideoCamera()
{
	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		imshow("MyVideocam", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}

int writeImg2File()
{
	Mat img(650, 600, CV_16UC3, Scalar(0, 50000, 50000));
	//create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "ERROR : Image cannot be loaded..!!" << endl;
		//system("pause"); //wait for a key press
		return -1;
	}

	vector<int> compression_params; //vector that stores the compression parameters of the image

	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

	compression_params.push_back(98); //specify the compression quality
	bool bSuccess = imwrite("D:/img/TestImage.jpg", img, compression_params); //write the image to file
	if (!bSuccess)
	{
		cout << "ERROR : Failed to save the image" << endl;
		//system("pause"); //wait for a key press
	}
	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window
	waitKey(0);  //wait for a keypress
	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
	return 0;
}
int writeVideo2File(string videofile = "d:/img/a.avi",string outvideofile="d:/img/b.avi")
{
	VideoCapture cap(videofile); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "ERROR: Cannot open the video file" << endl;
		return -1;
	}

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

	VideoWriter oVideoWriter(outvideofile, CV_FOURCC('P', 'I', 'M', '1'), 30, frameSize, true); //initialize the VideoWriter object 

	if (!oVideoWriter.isOpened()) //if not initialize the VideoWriter successfully, exit the program
	{
		cout << "ERROR: Failed to write the video" << endl;
		return -1;
	}

	while (1)
	{

		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "ERROR: Cannot read a frame from video file" << endl;
			break;
		}

		oVideoWriter.write(frame); //writer the frame into the file

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		if (waitKey(10) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;
}

int changeImgBrightness(string filename = "d:/img/lena.jpg")
{
	Mat img = imread(filename, CV_LOAD_IMAGE_COLOR);

	if (img.empty())
	{
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	Mat imgH = img + Scalar(75, 75, 75); //increase the brightness by 75 units
	//img.convertTo(imgH, -1, 1, 75);

	Mat imgL = img + Scalar(-75, -75, -75); //decrease the brightness by 75 units
	//img.convertTo(imgL, -1, 1, -75);

	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	namedWindow("High Brightness", CV_WINDOW_AUTOSIZE);
	namedWindow("Low Brightness", CV_WINDOW_AUTOSIZE);

	imshow("Original Image", img);
	imshow("High Brightness", imgH);
	imshow("Low Brightness", imgL);

	waitKey(0);

	destroyAllWindows(); //destroy all open windows

	return 0;
}

int changeVideoBrightness(string filename="d:/img/a.avi")
{
	VideoCapture cap(filename); // open the video file for reading

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	namedWindow("Original Video", CV_WINDOW_AUTOSIZE); //create a window called "Original Video"
	namedWindow("Brightness Increased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Increased"
	namedWindow("Brightness Decreased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Decreased"

	while (1)
	{
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		Mat imgH = frame + Scalar(50, 50, 50); //increase the brightness by 75 units

		Mat imgL = frame + Scalar(-50, -50, -50); //decrease the brightness by 75 units

		imshow("Original Video", frame); //show the frame in "Original Video" window
		imshow("Brightness Increased", imgH); //show the frame of which brightness increased
		imshow("Brightness Decreased", imgL); //show the frame of which brightness decreased

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;
}


int changeImgContrast(string filename = "d:/img/lena.jpg")
{
	Mat img = imread(filename, CV_LOAD_IMAGE_COLOR);

	if (img.empty())
	{
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	Mat imgH ; //increase the brightness by 75 units
	//img.convertTo(imgH, -1, 1, 75);
	img.convertTo(imgH, -1, 2, 0);
	Mat imgL; //decrease the brightness by 75 units
	//img.convertTo(imgL, -1, 1, -75);
	img.convertTo(imgL, -1, 0.5, 0);
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	namedWindow("High Contrast", CV_WINDOW_AUTOSIZE);
	namedWindow("Low Contrast", CV_WINDOW_AUTOSIZE);

	imshow("Original Image", img);
	imshow("HighContrast", imgH);
	imshow("Low Contrast", imgL);

	waitKey(0);

	destroyAllWindows(); //destroy all open windows

	return 0;
}

int changeVideoContrast(string filename = "d:/img/a.avi")
{
	VideoCapture cap(filename); // open the video file for reading

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	namedWindow("Original Video", CV_WINDOW_AUTOSIZE); //create a window called "Original Video"
	namedWindow("Contrast Increased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Increased"
	namedWindow("Contrast Decreased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Decreased"

	while (1)
	{
		Mat img;

		bool bSuccess = cap.read(img); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		Mat imgH; //increase the brightness by 75 units

		Mat imgL;  //decrease the brightness by 75 units
		img.convertTo(imgH, -1, 2, 0);
	
		//img.convertTo(imgL, -1, 1, -75);
		img.convertTo(imgL, -1, 0.5, 0);
		imshow("Original Video", img); //show the frame in "Original Video" window
		imshow("Contrast Increased", imgH); //show the frame of which brightness increased
		imshow("Contrast Decreased", imgL); //show the frame of which brightness decreased

		if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;
}

int histogramEqualizationOfColorImg(string filename = "d:/img/histoColor.png")
{
	Mat img = imread(filename, CV_LOAD_IMAGE_COLOR); //open and read the image
	
	if (img.empty()) //if unsuccessful, exit the program
	{
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	vector<Mat> channels;
	Mat img_hist_equalized;

	cvtColor(img, img_hist_equalized, CV_BGR2YCrCb); //change the color image from BGR to YCrCb format

	split(img_hist_equalized, channels); //split the image into channels

	equalizeHist(channels[0], channels[0]); //equalize histogram on the 1st channel (Y)

	merge(channels, img_hist_equalized); //merge 3 channels including the modified 1st channel into one image

	cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)

	//create windows
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	namedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);

	//show the image
	imshow("Original Image", img);
	imshow("Histogram Equalized", img_hist_equalized);

	waitKey(0); //wait for key press

	destroyAllWindows(); //destroy all open windows

	return 0;
}
int histogramEqualizationOfGrayImg(string filename = "d:/img/histo.png")
{
	Mat img = imread(filename, CV_LOAD_IMAGE_COLOR); //open and read the image

	if (img.empty())
	{
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	cvtColor(img, img, CV_BGR2GRAY); //change the color image to grayscale image

	Mat img_hist_equalized;
	equalizeHist(img, img_hist_equalized); //equalize the histogram

	//create windows
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	namedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);

	//show the image
	imshow("Original Image", img);
	imshow("Histogram Equalized", img_hist_equalized);

	waitKey(0); //wait for key press

	destroyAllWindows(); //destroy all open windows

	return 0;
}

int erodedilate(string filename = "d:/img/erod.jpg")
{
	Mat image = imread(filename);
	Mat erodedimg;
	//Mat element(7,7,CV_8U,Scalar(1));
	erode(image, erodedimg, Mat());
	Mat dilatedimg;
	dilate(image, dilatedimg, Mat());
	erode(image, erodedimg, Mat());
	namedWindow("original img");
	imshow("original img", image);
	namedWindow("eroded img");
	imshow("eroded img", erodedimg);
	namedWindow("dilate  img");
	imshow("dilate  img", dilatedimg);
	waitKey(0); //wait for key press

	destroyAllWindows();
	return 0;
}
