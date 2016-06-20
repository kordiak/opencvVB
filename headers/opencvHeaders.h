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

#include <exception>
#include <string>

//#define DEVICE_IP "http://192.168.0.100:8080/video?x.mjpeg"
#define DEVICE_IP "sos/czerwony.jpg"
const int height=300;
const int width=400;



class CamMeasurmentException : public std::runtime_error
{public:
  CamMeasurmentException(const std::string & _arg): std::runtime_error::runtime_error(_arg) { };
};


struct MouseEvent
{
  int eventType,x,y,z;
  
  MouseEvent():eventType(0),x(-1),y(-1)
  {
    
  }
  MouseEvent(int type,int x,int y): eventType(type),x(x),y(y)
  {
    
  }
};


enum ProgramEvent {
  EVENT_NOTME=-1,
  EVENT_NONE,EVENT_SEARCH,
  EVENT_CALIBRATE,
  EVENT_SELECT,
  EVENT_LINE,
  EVENT_FREEZE,
  EVENT_CLOSE,
  EVENT_PAINT,
  EVENT_LOADNEWIMAGE,
  EVENT_SELECT_BG
};


#endif	/* OPENCVHEADERS_H */

