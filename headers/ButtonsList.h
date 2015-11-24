/* 
 * File:   Menu.h
 * Author: tester
 *
 * Created on 24 październik 2015, 13:50
 */

#ifndef BUTTONSLIST_H
#define	BUTTONSLIST_H

#include "opencvHeaders.h"
#include "FieldWithText.h"
#include <iostream>
#include <vector>



class ButtonsList
{
  
  std::vector<FieldWithText*> elements;
  
  
public:
  void addElement(FieldWithText*);
  void removeElements();
  ProgramEvent translateEvents(MouseEvent & event);
  void draw(cv::Mat& output);
  ButtonsList ();
  ButtonsList (const ButtonsList& orig);
  virtual ~ButtonsList ();
private:

};

#endif	/* MENU_H */

