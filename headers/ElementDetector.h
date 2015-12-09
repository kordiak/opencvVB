/* 
 * File:   LineDetector.h
 * Author: tester
 *
 * Created on 7 grudzień 2015, 09:01
 */

#ifndef LINEDETECTOR_H
#define	LINEDETECTOR_H

#include "SearchingAlgorithmBase.h"
#include "SASimple.h"

class ElementDetector
{
  
private:
  SearchingAlgorithmBase * searchingAlgorithm;
  void init(SearchingAlgorithmBase * sab);
public:
  ElementDetector ();
  bool Detect(const cv::Mat & input);
  ElementDetector(SearchingAlgorithmBase * sab);
  ElementDetector (const ElementDetector& orig);
  virtual ~ElementDetector ();
private:

};

#endif	/* LINEDETECTOR_H */

