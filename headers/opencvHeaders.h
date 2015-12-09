/* 
 * File:   opencvHeaders.h
 * Author: tester
 *
 * Created on 24 październik 2015, 12:06
 */

#ifndef OPENCVHEADERS_H
#define	OPENCVHEADERS_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/calib3d/calib3d.hpp"

struct MouseEvent
{
  int eventType,x,y,z;
  MouseEvent(int type,int x,int y): eventType(type),x(x),y(y)
  {
    
  }
};


enum ProgramEvent {EVENT_NOTME=-1,EVENT_NONE,EVENT_SEARCH,EVENT_CALIBRATE,EVENT_SELECT};


#endif	/* OPENCVHEADERS_H */

