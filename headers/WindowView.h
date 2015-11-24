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


class WindowController;


class WindowView 
{
  
  cv::Mat matWhole;
  WindowController * prManager;
  static void onMouse(int event,int x,int y,int,void*);
  ButtonsList menu;
  
    void changeSize(const cv::Mat & input,cv::Mat & output);
  
public:
    ProgramEvent TranslateEvents(MouseEvent &); // receive event and pass it to menu
    
    bool Draw(const cv::Mat&);
    WindowView();
    WindowView(WindowController * prManager);
    WindowView(const WindowView& orig);
    virtual ~WindowView();
private:

};

#endif	/* DISPLAYER_H */

