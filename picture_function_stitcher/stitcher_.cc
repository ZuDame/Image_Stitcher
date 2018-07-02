#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

vector<Mat> imgs;

void parseCmdArgs(int argc, char** argv);

int main(int argc, char* argv[])
{
	parseCmdArgs(argc, argv);
	Mat pano;
	
	Stitcher stitcher = Stitcher::createDefault(false);
	Stitcher::Status status = stitcher.stitch(imgs,pano);
	
	if (status != Stitcher::OK)
	{
		cout<<"error code .."<<int(status)<<endl;
		return -1;
	}
	namedWindow("全景拼接",0);
	imshow("全景拼接",pano);
	imwrite("拼接结果.jpg",pano);
	waitKey();
	return 0;
}

void parseCmdArgs(int argc, char** argv)
{
	for(int i=1;i<argc;i++)
	{
		Mat img=imread(argv[i]);
		
		if(img.empty())
		{
			cout<<"can't read image !"<<argv[i]<<endl;
		}
		imgs.push_back(img);
	}
}




	
	
	

