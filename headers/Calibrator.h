/* 
 * File:   Calibrator.h
 * Author: tester
 *
 * Created on 25 listopad 2015, 18:56
 */

#ifndef CALIBRATOR_H
#define	CALIBRATOR_H


#include "opencvHeaders.h"
#include <vector>
#include "ImageSource.h"
class Calibrator
{
  
public:
  typedef std::vector<std::vector<cv::Point2f> > IMAGEPOINTS;
  typedef std::vector<std::vector<cv::Point3f> > IMAGINARYPOINTS;
  
private:
  cv::Size prepareImagePoints(ImageSource& image,const cv::Size& sizeOfPattern,IMAGEPOINTS& pointsOnImage);
  void prepareImaginaryPoints(const IMAGEPOINTS& pointsOnImage,const cv::Size& sizeOfPattern, IMAGINARYPOINTS& imaginaryPoints);
  
  cv::Mat  cameraMatrix;
  cv::Mat  distCoeffs;
  
  
public:
  
  Calibrator ();
  Calibrator (const Calibrator& orig);
  cv::Mat Undistort(const cv::Mat& input,cv::Mat& output);
  
  bool Calibrate(const char * name,const cv::Size& sizeofPattern);
  virtual ~Calibrator ();
private:

};

#endif	/* CALIBRATOR_H */

