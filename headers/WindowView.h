/* 
 * File:   Displayer.h
 * Author: tester
 *
 * Created on 22 październik 2015, 19:45
 */

#ifndef WINDOWVIEW_H
#define	WINDOWVIEW_H
#include <iostream>
#include "opencvHeaders.h"
#include "FieldWithText.h"
//#include "ProgramManager.h"
#include "ButtonsList.h"
#include "thread"

class WindowController;


class WindowView 
{
  
  cv::Mat matWhole;

  
  WindowController * mPrManager;
  static void onMouse(int event,int x,int y,int,void*);
  ButtonsList mMenu;
  MouseEvent mMouseEvent;
  
    void changeSize(const cv::Mat & input,cv::Mat & output);
  
public:
  
    
  ProgramEvent mOutput;
  ProgramEvent mInput;
  
    ProgramEvent TranslateEvents(MouseEvent &); // receive event and pass it to menu
    
    ProgramEvent PopEvent();
    void PushEvent(ProgramEvent);
    MouseEvent GetMouseEvent() const;
    bool Draw(const cv::Mat&,bool busy=false);
    WindowView();
    WindowView(WindowController * prManager);
    WindowView(const WindowView& orig);
    virtual ~WindowView();
private:

};

#endif	/* DISPLAYER_H */

