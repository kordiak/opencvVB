/* 
 * File:   main.cpp
 * Author: tester
 *
 * Created on 29 wrzesień 2015, 23:11
 */

#include <cstdlib>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cv::Mat material;
    
    
    cv::VideoCapture cap(
    "http://192.168.0.105:8080/video?x.mjpeg");
    //"http://208.42.203.54:8588/mjpg/video.mjpg");
    
    //+ CV_CAP_PVAPI
    //?dummy=param.mjpg
    //resolution=640x480&req_fps=30
    
    
    if(!cap.isOpened())
        return -1;
   
    
    
 
   
    
    
    //std::cout << cap.get(CV_
    
 // return -1;
    
    
    
    for(;;)
    {
        if(!cap.read(material))
            
        {
            std::cout << cap.get(CV_CAP_PROP_POS_AVI_RATIO);
            return -1;
            cv::waitKey(30);
        }
        else
            break;
    }
     
    
    cv::imshow("ok",material);
    
   cv::waitKey(0);
    
    
    return 0;
}

