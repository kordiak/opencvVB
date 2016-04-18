/* 
 * File:   Application.h
 * Author: tester
 *
 * Created on 12 grudzień 2015, 11:18
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "WindowController.h"


class Application
{
  
private:
  
  Application ();
  Application (const Application& orig);
  
  static Application * instance;
  
public:
  static Application * GetInstance();
  
  
  
  virtual ~Application ();
private:

};

#endif	/* APPLICATION_H */

