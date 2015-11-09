/* 
 * File:   ProgramManager.cpp
 * Author: tester
 * 
 * Created on 1 listopad 2015, 14:26
 */

#include "../headers/ProgramManager.h"
#include "../headers/Displayer.h"
ProgramManager::ProgramManager ()
{
  this->disp=new Displayer(this);
  
}

ProgramManager::ProgramManager (const ProgramManager& orig) { }

void ProgramManager::SendEvent(ProgramEvent event)
{
  std::cout << event;
}

void ProgramManager::Run()
{
 
   // cv::Mat picture(20,20,CV_8U,cv::Scalar(255));
    cv::Mat picture=cv::imread ("zrzut.png",CV_LOAD_IMAGE_GRAYSCALE);
   //GetPictureFromWebCam("http://192.168.0.105:8080/video?x.mjpeg");
   //cv::resize(picture,picture,cv::Size(picture.cols/2,picture.rows/2));
   
   
   cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
   kernel.at <float>(1,0)=-1;
   kernel.at<float>(1,1)=20;
   
   
   
   cv::Mat result(picture.size(),CV_8U,cv::Scalar(0));
   cv::Mat right(picture.size(),CV_8U,cv::Scalar(0));
   
   cv::filter2D (picture,right,picture.depth(),kernel);
   kernel.at<float>(1,0)=0;
   kernel.at<float>(1,2)=-1;
   
   cv::filter2D(picture,result,-1,kernel);
   
   result|=right;
   
   this->disp->Draw (result);
}
ProgramManager::~ProgramManager ()
{
  delete disp;
}

