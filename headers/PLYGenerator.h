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
  std::string getHeader(const std::vector<cv::Point> & points);
  std::string getPoints(const std::vector<cv::Point> & points);
  PLYGenerator (const PLYGenerator& orig);
  virtual ~PLYGenerator ();


};

#endif	/* PLYGENERATOR_H */

