/* 
 * File:   SASimple.h
 * Author: tester
 *
 * Created on 7 grudzień 2015, 19:15
 */

#ifndef SASIMPLE_H
#define	SASIMPLE_H


#include "SearchingAlgorithmBase.h"

class SASimple : public SearchingAlgorithmBase
{
public:
  SASimple ();
  bool Find (ELEMENTS& elements, cv::Mat& input);
  
  cv::Mat sharpenInclines(cv::Mat& input);
  cv::Mat sharpenVerticals(cv::Mat& input);
  cv::Mat sharpenHorizontals(cv::Mat& input);
  
  SASimple (const SASimple& orig);
  virtual ~SASimple ();
private:

};

#endif	/* SASIMPLE_H */

