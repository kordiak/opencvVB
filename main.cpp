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
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;

/*
 * 
 */
void
killHim (cv::VideoCapture& video)
{
  std::cout << "KILLING" << video.isOpened ();
  video.release ();
}

cv::Mat
GetPictureFromWebCam (const char* path)
{
  cv::Mat material;
  cv::VideoCapture cap (path);

  if (!cap.isOpened ())
    return cv::Mat ();
  

  for (int counter=0;counter<30;counter++)
    {
      if(cap.grab () &&cap.retrieve (material))
        {
          counter=0;
          cv::imshow("pic",material);
          cv::waitKey(1);
        }
     std::this_thread::__sleep_for (std::chrono::seconds(0),std::chrono::nanoseconds(1000000000));
     // 
      
      /*
      if (cap.read (material))
        {
          return material;
        }
       * */
    }

    
   

  //cv::imshow("ok",material);


  //cv::imwrite("zrzut2.png",material);

  return material;

}

void
onMouse (int event, int x, int y, int flags, void * data)
{
  if (event == cv::EVENT_LBUTTONDOWN)
    {



      Painter * paint = (Painter*) data;

      paint->Draw (x, y, event);

      // cv::Mat * mat=(cv::Mat*) data;
      // painter.BrushPoint (*mat,x,y,20);


    }
}


//cv::Ptr<cv::xfeatures2d::SURF> surf = cv::xfeatures2d::SURF::create(); // note
//extra namespace surf->detect(...); surf->compute(...);

using namespace cv;

/*
String face_cascade_name = "moneta/cascade.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;
String window_name = "Capture - Face detection";
*/


void detectAndDisplay( Mat frame )
{
  /*
    std::vector<Rect> faces;
    Mat frame_gray;

   // cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame, frame );

    //-- Detect faces
    face_cascade.detectMultiScale( frame, faces, 1.1, 2, 0, Size(80, 80) );
    
    for( size_t i = 0; i < faces.size(); i++ )
    {
        Mat faceROI = frame( faces[i] );
       
            //-- Draw the face
            Point center( faces[i].x+15 , faces[i].y+15  );
            cv::circle (frame,center,30,cv::Scalar(255));
            //ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 0 ), 2, 8, 0 );
        

    }
    //-- Show what you got
    imshow( window_name, frame );
    waitKey(0);
   * */
}

int
main (int argc, char** argv)
{
 // surf.
  
  
   /*
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };
    Mat image=ImageSource("/home/tester/NetBeansProjects/TesOpenCV/Photos/IMG_20160618_002449.jpg").GetImage ();
    cv::resize (image,image,cv::Size(image.size()/8));
     detectAndDisplay(image);
  
     return 0;
    
   // return 0;
    
  /*
  cv::Ptr<cv::Feature2D> f2d = cv::xfeatures2d::SIFT::create(); 
  

  ImageSource is("/home/tester/NetBeansProjects/TesOpenCV/matches");
  
  std::vector<cv::Mat> descriptors;
  
  for(int i=0;i<19;++i)
    {
      
      
      std::vector<cv::KeyPoint> keypoints_1;
      cv::Mat descriptors_1;
      cv::Mat img_1 = is.GetImage ();
      cv::resize (img_1,img_1,cv::Size(img_1.size()/4));
      
      
      f2d->detect(img_1,keypoints_1);
      f2d->compute(img_1,keypoints_1,descriptors_1);
      descriptors.push_back(descriptors_1);
      
      
    }
  
  cv::FlannBasedMatcher matcher;
  
  matcher.add (descriptors);
  matcher.train ();
  cv::Mat background= ImageSource("/home/tester/NetBeansProjects/TesOpenCV/2.jpg").GetImage ();
  cv::resize (background,background,cv::Size(background.size()/4));
  
  cv::Mat missing= ImageSource("/home/tester/NetBeansProjects/TesOpenCV/szukana.jpg").GetImage ();
  cv::resize(missing,missing,cv::Size(missing.size()/4));
  
  std::vector<cv::KeyPoint> keypointsBack, keypointsMissing;
  cv::Mat descBack, descMissing;
  
  
 // cv::imshow("szukana",background);
 // cv::waitKey(0);
  f2d->detect(background,keypointsBack);
  f2d->detect(missing,keypointsMissing);
  
  f2d->compute(background,keypointsBack,descBack);
  f2d->compute(missing,keypointsMissing,descMissing);
  
  std::vector<cv::DMatch > matches;
  matcher.match (descBack,descMissing,matches);
  
  printf(" Matches: %d", matches.size ());
  
 cv::Mat output; 
 
 double max_dist=0; double min_dist =100;
 for(int i=0;i < descBack.rows; ++i)
    {
     double dist=matches[i].distance;
     
     if(dist < min_dist) min_dist = dist;
     if(dist > max_dist) max_dist = dist; 
     
      
    }
 
 std::vector<cv::DMatch> good_matches;
 
 for(int i=0;i < descBack.rows; ++i)
   {
     if(matches[i].distance <= cv::max(2*min_dist,0.02))
       {
         good_matches.push_back(matches[i]);
       }
   }
 
 
   
 cv::drawMatches (background,keypointsBack,missing,keypointsMissing,good_matches,output);
          
  
  //cv::Mat img_2 = is.GetImage ();
  
 
 
 //cv::resize (img_2,img_2,cv::Size(img_2.size()/4));
 
 // img_1.resize (cv::Size(img_2.size().height/2 , img_2.size().width/2));
 //
 // f2d->detect (img_1,keypoints_1);
 // f2d->detect (img_2,keypoints_2);

 // cv::Mat descriptors_1,descriptors_2;
  
  //f2d->compute (img_1,keypoints_1,descriptors_1);
 // f2d->compute (img_2,keypoints_2,descriptors_2);
  
  
  
//  
  
//  
//  //cv::BFMatcher matcher;
// 
//  matcher.train ();
//  matcher.match(descriptors_2,descriptors_1,matches);
// 
//  
//  
  
  
  //matcher.knnMatch (descriptors_2,descriptors_1,)
  
  
  */
//  
  /*

  //*/
//  
  
 // cv::imshow ("out",output);
 // cv::waitKey (0);
  
  

  
  
/*
for(;;)
{
cv::imshow("win",is.GetImage ());
cv::waitKey (1000);
}
//*/
// 
//    cout << "OpenCV version : " << CV_VERSION << endl;
//  cout << "Major version : " << CV_MAJOR_VERSION << endl;
//  cout << "Minor version : " << CV_MINOR_VERSION << endl;
//  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

  //
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

