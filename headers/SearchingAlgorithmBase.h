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
public:
  SearchingAlgorithmBase ();
  
  SearchingAlgorithmBase (const SearchingAlgorithmBase& orig);
  
  virtual bool Find(ELEMENTS & elements,cv::Mat & input)=0;
  virtual ~SearchingAlgorithmBase () {};
private:

};

#endif	/* SEARCHINGALGORITHMBASE_H */

