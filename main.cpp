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
#include <chrono>


#include "headers/opencvHeaders.h"

#include "headers/WindowController.h"
#include "headers/WindowView.h"
#include "headers/ImageSource.h"
#include "headers/Calibrator.h"
#include "headers/ElementDetector.h"
#include "headers/Painter.h"

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


void onMouse(int event,int x,int y,int flags, void * data)
{
  if(event == cv::EVENT_LBUTTONDOWN)
    {
      
      
      
      Painter * paint=(Painter*) data;
      
      paint->Draw (x,y,event);
      
     // cv::Mat * mat=(cv::Mat*) data;
     // painter.BrushPoint (*mat,x,y,20);
      
      
    }
}

int main(int argc, char** argv) 
{

       WindowController pr;
       pr.Run();
      
   
     
//     
//         SASimple sa;
//  
//         ELEMENTS s;
//        
//  
//        ImageSource fr("sos/czerwony.jpg");
//        SASimpleParams pa;
//        
//        pa.threshold=20.0;
//        sa.SetParameters (&pa);
//       /* 
//        cv::Mat ot=fr.GetImage ();
//        
//         sa.Find (s,ot);
//        */
//        cv::Mat zakretkiWczytane=fr.GetImage ();
//        cv::Mat grad_u(zakretkiWczytane.size(),CV_8U,0);
//        cv::Mat grad_v(zakretkiWczytane.size(),CV_8U,0);
//        
//        cv::Mat PodbityThreshold;
//        
//        
//        cv::adaptiveThreshold (zakretkiWczytane,PodbityThreshold,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,21,6);
//       
//        cv::Sobel(PodbityThreshold,grad_u,CV_8U,1,0,3);
//        cv::Sobel(PodbityThreshold,grad_v,CV_8U,0,1,3);
//        
//        std::vector<std::vector<cv::Point> > array;
//        std::vector<cv::Vec4i> hier;
//      //   cv::cvtColor (zakretki,zakretki_gray,CV_BGR2GRAY);
//        
//        cv::Mat wynik= grad_v & grad_u;
//        
//        
//        cv::Mat cannyOut;
//        
//        cv::Canny (PodbityThreshold,cannyOut,200,400);
//        
//        cv::findContours (cannyOut,array,hier,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,cv::Point(0,0));
//        //cv::Canny
//        
//        
//        cv::Mat contours(cannyOut.size(),cannyOut.type(),cv::Scalar(0));
//       for(int i=0;i<array.size ();++i)
//         if(array[i].size()>100)
//        cv::drawContours (contours,array,i,cv::Scalar(255));
//  
//        cv::imwrite("plik.jpg",grad_u& grad_v& contours);
//       
//       
//      //  Painter painter;
//        
//     //   painter.Paint (contours,0,200,100);
//        
//        
//        //cv::namedWindow("contours",1);
//        
//        
//        
//        cv::imshow("podbityThreshold",PodbityThreshold);
//        
//        cv::imwrite("thresh.jpg",PodbityThreshold);
//        cv::imwrite("canny.jpg",cannyOut);
//        cv::imwrite("contours.jpg",contours);
//        cv::imshow("cannyOut",cannyOut);
//        
//        
//        
//        
//        
//        cv::namedWindow("contours",1);
//        
//        Painter paint(&contours);
//        
//        paint.State (PainterState::POINT);
//        
//        
//        cv::setMouseCallback("contours",onMouse,(void*) &paint);
//        
//        
//        
//        
//        while(true)
//          { cv::imshow("contours",contours);
//            cv::waitKey (100);
//          }
//       
//        
//        
//        cv::imshow("contours",contours);
//        cv::waitKey ();
//        
        
             
       //  cv::imwrite ("plik0.jpg",wynik);
  
       /*
        
        for(int i=0;i <array.size ();++i)
          {
            int size=array[i].size();
            if(size>20)
              {
                
                
                
                
                
                cv::Point max(0,0);
                cv::Point min(end.cols,end.rows);
                
                for(int j=0; j<size;++j)
                  {
                    cv::Point point=array[i][j];
                   
                    if(point.x > max.x)
                      max.x=point.x;
                    else
                      if(point.x < min.x)
                        min.x=point.x;
                    
                    if(point.y > max.y)
                      max.y=point.y;
                    else
                      if(point.y < min.y)
                        min.y=point.y;
                    
                  }
                
                unsigned int width=max.x- min.x;
                unsigned int height=max.y- max.y;
                
                
                cv::Point center(max.x-width/2,max.y-height/2);
                
               // end.at<unsigned int>(center)=255;
                
                
                
               cv::line(end,max, min, cv::Scalar(255));
                     

                
                
                
//                
//                for(int v=0; v< height;++v)
//                  {
//                    for(int u=0; u< width;++u)
//                      {
//                        end.at<unsigned char>(v,u)=255;
//                      }
//                  }
                
                
              }
          }
         
         
         
         
         
         
        
      //  cv::imwrite ("plik.jpg",end);
       // std::cout << "FLAGA: " << pr.flag;
   
   */
        
        
        //cv::im
    
   // pr.Run ();
    
   
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
  // cv::waitKey(0);
    

    return 0;
}

