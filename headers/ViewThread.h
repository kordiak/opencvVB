/* 
 * File:   ViewThread.h
 * Author: tester
 *
 * Created on 16 grudzień 2015, 11:15
 */

#ifndef VIEWTHREAD_H
#define	VIEWTHREAD_H


#include <thread>
#include "WindowController.h"

class ViewThread : public std::thread
{
public:
  ViewThread (WindowController * controller);
  ViewThread (const ViewThread& orig);
  virtual ~ViewThread ();
private:

};

#endif	/* VIEWTHREAD_H */

