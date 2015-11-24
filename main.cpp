/* 
 * File:   main.cpp
 * Author: tester
 *
 * Created on 29 wrzesień 2015, 23:11
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "headers/opencvHeaders.h"
#include <thread>
#include "headers/WindowController.h"
#include "headers/WindowView.h"
#include "headers/ImageSource.h"
#include <fstream>

#include "opencv2/calib3d/calib3d.hpp"
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
  
  
  
    ImageSource fr("sos/chess.png");
    
    cv::Mat pattern=fr.GetImage ();
    std::vector<cv::Vec2f> buffor;
  
    cv::Mat output;
    cv::Size sizeOfPattern(9,6);
    bool found=cv::findChessboardCorners (pattern,sizeOfPattern,output,cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FILTER_QUADS );
    if(found)
      {
            std::cout << std::endl << "Found for : " << 9 << " " << 6 << std::endl;
           
            
            
            cv::Vec2f *ptr=reinterpret_cast<cv::Vec2f*> (output.data);
             for(int i=0;i< output.rows;++i)
              {
                 
                std::cout << ptr[i]<< std::endl;
              }
            
            
            
            
      }
    
     cv::imshow("ok",pattern);
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

