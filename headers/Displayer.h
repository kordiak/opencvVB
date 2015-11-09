/* 
 * File:   Displayer.h
 * Author: tester
 *
 * Created on 22 październik 2015, 19:45
 */

#ifndef DISPLAYER_H
#define	DISPLAYER_H
#include <iostream>
#include "opencvHeaders.h"
#include "FieldWithText.h"
//#include "ProgramManager.h"
#include "Menu.h"


class ProgramManager;


class Displayer 
{
  
  cv::Mat matWhole;
  ProgramManager * prManager;
  static void onMouse(int event,int x,int y,int,void*);
  Menu menu;
  
    void changeSize(const cv::Mat & input,cv::Mat & output);
  
public:
    ProgramEvent TranslateEvents(MouseEvent &); // receive event and pass it to menu
    
    bool Draw(const cv::Mat&);
    Displayer();
    Displayer(ProgramManager * prManager);
    Displayer(const Displayer& orig);
    virtual ~Displayer();
private:

};

#endif	/* DISPLAYER_H */

