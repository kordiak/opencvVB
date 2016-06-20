/* 
 * File:   PLYGenerator.h
 * Author: tester
 *
 * Created on 28 luty 2016, 21:54
 */

#ifndef PLYGENERATOR_H
#define	PLYGENERATOR_H

#include <vector>
#include <string>
#include "../headers/opencvHeaders.h"

class PLYGenerator
{
private:
  
  
  
public:
  
  
  PLYGenerator ();
  
  bool Generate(const char* filename, const std::vector<cv::Point> & points);
  bool Generate(const std::vector<cv::Point>& points,float elementWpx,float elementHpx,float tableWpx,float tableHpx);
  std::string getHeader(const std::vector<cv::Point> & points,int multi=1);
  std::string getPoints(const std::vector<cv::Point> & points,int col=0,int row=0.f);
  PLYGenerator (const PLYGenerator& orig);
  virtual ~PLYGenerator ();


};

#endif	/* PLYGENERATOR_H */

