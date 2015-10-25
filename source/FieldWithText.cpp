/* 
 * File:   FieldWithText.cpp
 * Author: tester
 * 
 * Created on 24 październik 2015, 11:59
 */
#include "../headers/FieldWithText.h"



//private
bool FieldWithText::isClickedInside(int x,int y)
{
  if(x>this->fromTop.x && x<this->fromTop.x+fromTop.width)
    if(y>fromTop.y && y<fromTop.y+fromTop.height)
      return true;
  return false;
}



//////////////////
//////PUBLIC/////

FieldWithText::FieldWithText (const cv::Rect & fromTop,const std::string & text,ProgramEvent evt):fromTop(fromTop),text(text),evt(evt)
{
  
}


FieldWithText::FieldWithText (const FieldWithText& orig) { }

FieldWithText::~FieldWithText () { }

/////////////////
//METHODS///////

void FieldWithText::draw (cv::Mat& output)
{
  cv::rectangle (output,fromTop,cv::Scalar(200),CV_FILLED);
  unsigned int x=fromTop.x;
  unsigned int y=fromTop.y+fromTop.height*0.7;
  cv::putText(output,text,cv::Point(x,y),cv::FONT_HERSHEY_DUPLEX,1,cv::Scalar(255));
  
}

ProgramEvent FieldWithText::attendToEvent (MouseEvent& event)
{
  if(isClickedInside(event.x,event.y))
    {
        return evt;
    }
  return EVENT_NOTME;
}
