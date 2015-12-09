/* 
 * File:   main.cpp
 * Author: tester
 *
 * Created on 29 wrzesień 2015, 23:11
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <thread>


#include "headers/opencvHeaders.h"

#include "headers/WindowController.h"
#include "headers/WindowView.h"
#include "headers/ImageSource.h"
#include "headers/Calibrator.h"
#include "headers/ElementDetector.h"

#include "headers/SASimple.h"

#include <opencv2/features2d/features2d.hpp>


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
  
  //cv::fin
   // DIR * p;
  
    /*
    FILE *file=fopen("sos","rb");
    if(file!=0) std::cout << " OK";
    else
      return -1;
    
    char buffor[255];
    std::memset(buffor,'\0',255);
    
    fread(buffor,1,255,file);
    
    for(int i=0;i<254;++i)
      {
        std::cout << (int)buffor[i];
      }
    
    fclose(file);
   
  
    
    std::ifstream in;
    in.open("sos",ifstream::in & ifstream::binary);
    
    
    while(in.goodbit)
     {
        std::cout <<std::ios_base::hex<< (int)in.get();
        
     }
    
    in.close();
    std::cout<< std::ios_base::hex << in;
     * 
    //*/
  
  
  
    ImageSource fr("sos/chess/WP_20151130_14_45_25_Pro.jpg");
    Calibrator calib;
    cv::Size sizeOfPattern(9,6);
    calib.Calibrate ("sos/chess",sizeOfPattern);
    
    SASimple *sas=new SASimple;
    ElementDetector detector(sas);
    
    cv::Mat input=fr.GetImage ();
    cv::cvtColor(input,input,CV_BGR2GRAY);
    cv::Mat pattern;
    calib.Undistort (input,pattern);
   
    detector.Detect(pattern);
    
    
    
   // std::vector<cv::Vec2f> buffor;
    //cv::imshow("und",pattern);
   //  cv::Mat output;
    // std::vector<cv::Vec2f> out;
    //std::vector<std::vector<cv::Vec3f> > output;
    /*
    
    int i=0; bool found=false;
    while(i<3)
      {i++;
      cv::flip(pattern,pattern,i);
        found=cv::findChessboardCorners (pattern,sizeOfPattern,out);
      }
    
    

    if(found)
      {
        
        cv::cvtColor (pattern,pattern,CV_BGR2GRAY);
        
        cv::cornerSubPix (pattern,out,cv::Size(11,11),cv::Size(-1,-1),cv::TermCriteria(cv::TermCriteria::EPS+cv::TermCriteria::COUNT,30,0.1));
        
        cv::drawChessboardCorners (pattern,sizeOfPattern,cv::Mat(out),found);
        
        
        cv::Mat cameraMatrix=cv::Mat::eye (3,3,CV_64F);
        cv::Mat distCoeffs=cv::Mat::zeros(8,1,CV_64F);
        
        std::vector<std::vector<cv::Point3f> > corners(1);
        float squaresize=1.f;
        
        
        for(unsigned int i=0;i<sizeOfPattern.height;++i)
          {
            for(unsigned int j=0;j<sizeOfPattern.width;++j)
              {
                corners[0].push_back (cv::Point3f(static_cast<float>(j*squaresize),static_cast<float>(i*squaresize),0.f));
              }
          }
        //todo!!! many finds;
        corners.resize(10,corners[0]);
        
               std::cout << std::endl << "Found for : " << 9 << " " << 6 << std::endl;
               std::cout <<  std::endl;
               
               for(int i=0;i<out.size();++i)
                {
                    std::cout << out[i]<< std::endl;
                }
           
               //cv::un
            
            
      }
    
     cv::imshow("ok",pattern);
     */
    //cv::imshow("ok",fr.GetImage ());
    //cv::waitKey (0);
   
    
   // cv::imshow ("fifth",fr.GetImage ());
    cv::Mat iro;
    
    WindowController pr;
    // Displayer disp(&pr);
    
    pr.Run ();
    
   
   //cv::imshow("output",result);
   
  
 //  disp.Draw (result);
   //cv::waitKey(0);
   //disp.Draw(result);
    
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

