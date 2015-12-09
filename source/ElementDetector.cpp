/* 
 * File:   LineDetector.cpp
 * Author: tester
 * 
 * Created on 7 grudzień 2015, 09:01
 */

#include "../headers/ElementDetector.h"


void ElementDetector::init(SearchingAlgorithmBase * sab)
{
  searchingAlgorithm=sab;
}


ElementDetector::ElementDetector () :searchingAlgorithm(0)
{ 
  SASimple * algorithm=new SASimple();
  init(algorithm);
}
ElementDetector::ElementDetector(SearchingAlgorithmBase * sab)
{
  init(sab);
}
ElementDetector::ElementDetector (const ElementDetector& orig) { }

ElementDetector::~ElementDetector () 
{
  if(searchingAlgorithm!=0)
    delete searchingAlgorithm;
}

bool ElementDetector::Detect (const cv::Mat& input)
{
  
  cv::Mat output;
  
  input.copyTo (output);
  
  ELEMENTS elements;
  this->searchingAlgorithm->Find(elements,output);
  
  return false;
}