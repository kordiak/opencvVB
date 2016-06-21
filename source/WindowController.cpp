/* 
 * File:   ProgramManager.cpp
 * Author: tester
 * 
 * Created on 1 listopad 2015, 14:26
 */

#include <thread>
#include <chrono>
#include "../headers/WindowController.h"
#include "../headers/WindowView.h"

WindowController::WindowController () : mDisplayer(0), mDetector(0), mCalibrator(0),mDispThread(0),mProgramThread(0),mPainter(0)
{
  
  this->mDisplayer = new WindowView (this);
  this->mDetector = new ElementDetector(this);
  this->mCalibrator = new Calibrator();
  this->mPainter = new Painter();
  this->mImageSource=new ImageSource(SOURCE_PATH.c_str ());
  
}

WindowController::WindowController (const WindowController& orig) { }


void WindowController::displayLoop (WindowController* pointer, cv::Mat* pattern)
{
  
    this->mDispThread= new std::thread([](WindowController * pointer,cv::Mat* pattern)
    {
      
    while(pointer->run)
    {
       
     cv::createTrackbar ("Filter threshold","output",&pointer->threshold,10);
    
     pointer->mDisplayer->Draw (*pattern);   
     
    }
    },pointer,pattern);
     
    
}
void WindowController::programLoop (WindowController* pointer, cv::Mat* pattern)
{
  pointer->mProgramThread=new std::thread([](WindowController* pointer,cv::Mat* pattern)
      {
       
       
      int i=0;
      while(pointer->run)
        {
         
          
          pointer->mDisplayer->PushEvent(ProgramEvent::EVENT_FREEZE);
          //*pattern/=2;
          switch(pointer->mDisplayer->PopEvent())
            {
            case ProgramEvent::EVENT_CALIBRATE:
              
              pointer->mCalibrator->Calibrate ("sos/chess",cv::Size(9,6));
              break;
            case ProgramEvent::EVENT_CLOSE:
              pointer->run=false;
              break;
            case ProgramEvent::EVENT_SEARCH:
              
              pointer->mDetector->Threshold (pointer->threshold);
              pointer->mDetector->Detect (*pattern);
              pointer->mDetector->GetOutput ().copyTo (*pattern);
              
              break;
              
            case ProgramEvent::EVENT_PAINT:
            {
              
              MouseEvent mouse=pointer->mDisplayer->GetMouseEvent ();           
              pointer->mPainter->Draw (mouse.x,mouse.y,mouse.eventType);
             
            }
              break;
            case ProgramEvent::EVENT_LINE:
              pointer->mPainter->State (PainterState::LINE);
              pointer->mPainter->Color (255);
              break;
            case ProgramEvent::EVENT_SELECT:
              pointer->mPainter->State (PainterState::FLOOD);
              break;
            case ProgramEvent::EVENT_SELECT_BG:
              pointer->mPainter->State (PainterState::FLOOD_BG);
              break;
            case ProgramEvent::EVENT_LOADNEWIMAGE:
              cv::Mat & refToPattern=*pattern;
              cv::Mat temp;
              temp=pointer->mImageSource->GetImage ();
              pointer->mCalibrator->Undistort (temp,refToPattern);
              break;
            }
         // *pattern*=2;
          pointer->mDisplayer->PushEvent(ProgramEvent::EVENT_NONE);
          
          std::this_thread::__sleep_for (std::chrono::seconds(0),std::chrono::nanoseconds(50000000));
         
          i++;
        }
      
      
      },pointer,pattern);
}



void
WindowController::SendEvent (ProgramEvent event)
{
  
 // std::cout << " WindowController received : " << event << "|";
  
 // cv::Mat mat=cv::Mat::eye(5,5,CV_8UC1);
  //this->detector->Detect (mat);


  switch(event)
    {
    
    case ProgramEvent::EVENT_NONE : break;
    case ProgramEvent::EVENT_CALIBRATE:
      
  break;
    case ProgramEvent::EVENT_SEARCH: 
    break;
    case ProgramEvent::EVENT_SELECT: break;
    case ProgramEvent::EVENT_NOTME: break;
    default: break;
    
    }
  
}

void
WindowController::Run ()
{
  
  
  /*
  // cv::Mat picture(20,20,CV_8U,cv::Scalar(255));
  cv::Mat picture = cv::imread ("zrzut.png", CV_LOAD_IMAGE_GRAYSCALE);
  //GetPictureFromWebCam("http://192.168.0.105:8080/video?x.mjpeg");
  //cv::resize(picture,picture,cv::Size(picture.cols/2,picture.rows/2));


  cv::Mat kernel (3, 3, CV_32F, cv::Scalar (0));
  kernel.at <float>(1, 0) = -1;
  kernel.at<float>(1, 1) = 20;

  cv::Mat result (picture.size (), CV_8U, cv::Scalar (0));
  cv::Mat right (picture.size (), CV_8U, cv::Scalar (0));

  cv::filter2D (picture, right, picture.depth (), kernel);
  kernel.at<float>(1, 0) = 0;
  kernel.at<float>(1, 2) = -1;

  cv::filter2D (picture, result, -1, kernel);

  result |= right;
  */
   // ImageSource fr("sos/czerwony.jpg");
    //ImageSource fr(SOURCE_PATH.c_str ());
    
    Calibrator calib;
    cv::Size sizeOfPattern(9,6);
    calib.Calibrate ("sos/chess",sizeOfPattern);
    
    SASimple *sas=new SASimple;
  //  ElementDetector detectorInternal(sas);
   
    cv::Mat input= this->mImageSource->GetImage ();
    //cv::cvtColor(input,input,CV_BGR2GRAY);
    cv::Mat pattern;
    
    
   // input.copyTo (pattern);
    calib.Undistort (input,pattern);
   
   // detectorInternal.Detect(pattern);
   // WindowController * pt=this;
   
    mPainter->Image (&pattern); 
    mDetector->SetAlgorithm (sas);
    
    displayLoop (this,&pattern);
    programLoop (this,&pattern);
    
    
    if(mProgramThread->joinable () && mDispThread->joinable ())
    {
    this->mProgramThread->join();
    this->mDispThread->join();
    }
    
}

WindowController::~WindowController ()
{
  if (mDisplayer != 0)
    delete mDisplayer;
  if (mDetector != 0)
    delete mDetector;
  if(mCalibrator !=0 )
    delete mCalibrator;
  if(mDispThread!=0)
    delete mDispThread;
  if(mProgramThread!=0)
    delete mProgramThread;
    
  delete mPainter;
  delete mImageSource;
  
}

