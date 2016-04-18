/* 
 * File:   SearchingAlgorithmBase.h
 * Author: tester
 *
 * Created on 7 grudzień 2015, 09:05
 */

#ifndef SEARCHINGALGORITHMBASE_H
#define	SEARCHINGALGORITHMBASE_H


#include <vector>
#include "opencvHeaders.h"







typedef std::vector<std::vector<cv::Vec2f> >  ELEMENTS;

class SearchingAlgorithmBase
{
  
protected:
  cv::Mat_<unsigned char> outputMat;
public:
  SearchingAlgorithmBase ();
  
  SearchingAlgorithmBase (const SearchingAlgorithmBase& orig);
  
  cv::Mat GetOutput();
  virtual bool Find(ELEMENTS & elements,cv::Mat & input)=0;
  
  virtual void SetParameters(void * parameters)=0;
  
  virtual ~SearchingAlgorithmBase () {};
  
protected:

  void *params;
};

#endif	/* SEARCHINGALGORITHMBASE_H */

