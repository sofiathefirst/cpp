#include"showImg.h"

void bi(Mat &image, int i,int j)
{
int oj = j,oi = i;
	for (i ; i < oi+1000; i++)
	{
		for (j=oj ; j < oj+150; j++)	
			{
				image.at<uchar>(j, i) = 0;	
				if((i-oi)%200 ==0)
					image.at<uchar>(j, i) = 100;	
					

			}
	}


}

void bi2(Mat &image, int i,int j)
{
int oj = j,oi = i;
	for (i ; i < oi+1200; i++)
	{
		for (j=oj ; j < oj+150; j++)	
			{
				image.at<uchar>(j, i) = 0;	
				if((i-oi)%200 ==0)
					image.at<uchar>(j, i) = 100;	
					

			}	
					
	}


}
int main()
{
//showimg("/home/vision/Desktop/cmakeLearn/src/version1.bmp");
Mat m = imread("/home/vision/Desktop/cmakeLearn/src/version1.bmp");

	Mat img1,image = m;
	if (image.channels() == 3)
	{
		//ŽŽœšÄ¿±êÍŒÏñ  
		cvtColor(image, img1, CV_BGR2GRAY);
		image = img1;
		cout << img1.channels() << image.channels();
		cout << img1.rows << image.rows;
		cout << img1.cols << image.cols;
		
	}

	int i = 250, j = 250;
	bi(image,i,j);//1

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//2

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//3

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//4

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//5

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//6

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//7

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);//8

	i = 250, j +=150+173;//250+150+173;
	bi(image,i,j);	//9


	i = 1500, j = 250;
	bi2(image,i,j);//1

	j +=150+173;//250+150+173;
	bi2(image,i,j);//2

	j +=150+173;//250+150+173;
	bi2(image,i,j);//3

	j +=150+173;//250+150+173;
	bi2(image,i,j);//4

	j +=150+173;//250+150+173;
	bi2(image,i,j);//5

	j +=150+173;//250+150+173;
	bi2(image,i,j);//6

	j +=150+173;//250+150+173;
	bi2(image,i,j);//7

	j +=150+173;//250+150+173;
	bi2(image,i,j);//8

	j +=150+173;//250+150+173;
	bi2(image,i,j);	//9



imshow("ha",image);

imwrite("v3.bmp",image);
imwrite("v33.bmp",image);
	waitKey();
return 0;
}
