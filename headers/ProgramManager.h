/* 
 * File:   ProgramManager.h
 * Author: tester
 *
 * Created on 1 listopad 2015, 14:26
 */


#ifndef PROGRAMMANAGER_H
#define	PROGRAMMANAGER_H

#include "opencvHeaders.h"
#include <iostream>
#include "Displayer.h"



class ProgramManager
{
  Displayer * disp;
  
public:
  
  void SendEvent(ProgramEvent event);
  void Run();
  ProgramManager ();
  ProgramManager (const ProgramManager& orig);
  virtual ~ProgramManager ();
private:

};

#endif	/* PROGRAMMANAGER_H */

