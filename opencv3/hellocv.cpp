#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
	Mat srcImage = imread("/home/a/workspace1/opencv3/a.jpg");
	imshow("img",srcImage);
	Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	erode(srcImage,dstImage,element);
	imshow("erode img",dstImage);
	waitKey(0);
	//imwrite("a.bmp",img);

	return 0;
}
