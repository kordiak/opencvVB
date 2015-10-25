/* 
 * File:   FieldWithText.h
 * Author: tester
 *
 * Created on 24 październik 2015, 11:59
 */

#ifndef FIELDWITHTEXT_H
#define	FIELDWITHTEXT_H

#include "opencvHeaders.h"
#include <iostream>
#include <string>



class FieldWithText
{
  cv::Rect fromTop;
  std::string text;
  ProgramEvent evt;
  
  bool isClickedInside(int x,int y);
  
public:
  FieldWithText (const cv::Rect & ,const std::string &,ProgramEvent evt=ProgramEvent::EVENT_NONE);
  FieldWithText (const FieldWithText& orig);
  
  ProgramEvent attendToEvent(MouseEvent & );
  void draw(cv::Mat&);
  virtual ~FieldWithText ();
private:

};

#endif	/* FIELDWITHTEXT_H */

