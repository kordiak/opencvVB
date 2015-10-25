/* 
 * File:   main.cpp
 * Author: tester
 *
 * Created on 29 wrzesień 2015, 23:11
 */

#include <cstdlib>
#include <iostream>
#include "headers/opencvHeaders.h"
#include <thread>
#include "headers/Displayer.h"


using namespace std;

/*
 * 
 */
void killHim(cv::VideoCapture& video)
{
    std::cout << "KILLING" << video.isOpened();
    video.release();
}

cv::Mat GetPictureFromWebCam(const char* path)
{
    cv::Mat material;
    cv::VideoCapture cap(path);
    
    if(!cap.isOpened())
        return cv::Mat();
    
    for(;;)
    {
        if(!cap.read(material))
            
        {
            std::cout << cap.get(CV_CAP_PROP_POS_AVI_RATIO);
            return cv::Mat();
            cv::waitKey(30);
            
            
        }
        else
            break;
    }
     
    
   // cv::imshow("ok",material);
   
    
    //cv::imwrite("zrzut2.png",material);
    
    return material;
    
}


int main(int argc, char** argv) 
{

    //FieldWithText fwt;
    Displayer disp;
    
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
   
   //cv::imshow("output",result);
   
  
   disp.Draw (result);
   cv::waitKey(0);
   disp.Draw(result);
    
   // GetPictureFromWebCam("http://192.168.0.105:8080/video?x.mjpeg");
    
//    
//    cv::Mat material;
//    cv::VideoCapture cap(
//    "http://192.168.0.105:8080/video?x.mjpeg");
//   // "http://208.42.203.54:8588/mjpg/video.mjpg");
//    
//   //std::thread killer(killHim,std::ref(cap));
//    
//    
//    
//    //+ CV_CAP_PVAPI
//    //?dummy=param.mjpg
//    //resolution=640x480&req_fps=30
//    
//    if(!cap.isOpened())
//        return -1;
//   
//    //std::cout << cap.get(CV_
//    
// // return -1;
//    
//    
//    
//    
//    
   cv::waitKey(0);
    
    
    return 0;
}

