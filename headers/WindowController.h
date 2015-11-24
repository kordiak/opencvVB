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



class WindowController
{
  WindowView * disp;
  
public:
  
  void SendEvent(ProgramEvent event);
  void Run();
  WindowController ();
  WindowController (const WindowController& orig);
  virtual ~WindowController ();
private:

};

#endif	/* PROGRAMMANAGER_H */

