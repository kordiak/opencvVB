/* 
 * File:   ProgramManager.h
 * Author: tester
 *
 * Created on 1 listopad 2015, 14:26
 */


#ifndef WINDOWCONTROLLER_H
#define	WINDOWCONTROLLER_H

#include "opencvHeaders.h"
#include <iostream>
#include "WindowView.h"
#include "ElementDetector.h"
#include "Calibrator.h"
#include "Painter.h"


class WindowController
{
  
  
  bool run;
  int threshold;
  
  WindowView * mDisplayer;
  ElementDetector * mDetector;
  Calibrator * mCalibrator;
  Painter * mPainter;
  ImageSource * mImageSource;
  
  std::thread * mDispThread;
  std::thread * mProgramThread;
  
  void displayLoop(WindowController * pointer,cv::Mat* pattern);
  void programLoop(WindowController * pointer,cv::Mat* pattern);
  

 // void algorithmLoop()
  
public:
  bool flag;
  void SetEvent()
  {
    //flag=true;
  }
  void SendEvent(ProgramEvent event);
  void Run();
  WindowController ();
  WindowController (const WindowController& orig);
  
  virtual ~WindowController ();
private:

};

#endif	/* PROGRAMMANAGER_H */

