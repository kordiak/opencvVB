/* 
 * File:   Menu.h
 * Author: tester
 *
 * Created on 24 październik 2015, 13:50
 */

#ifndef MENU_H
#define	MENU_H

#include "opencvHeaders.h"
#include "FieldWithText.h"
#include <iostream>
#include <vector>



class Menu
{
  
  std::vector<FieldWithText*> elements;
  
  
public:
  void addElement(FieldWithText*);
  void removeElements();
  ProgramEvent translateEvents(MouseEvent & event);
  void draw(cv::Mat& output);
  Menu ();
  Menu (const Menu& orig);
  virtual ~Menu ();
private:

};

#endif	/* MENU_H */

