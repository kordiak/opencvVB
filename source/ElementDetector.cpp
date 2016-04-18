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
void ElementDetector::initDefault ()
{
  SASimple * algorithm=new SASimple();
  init(algorithm);
}

ElementDetector::ElementDetector () :searchingAlgorithm(0)
{ 
  initDefault();
}
ElementDetector::ElementDetector(SearchingAlgorithmBase * sab)
{
  init(sab);
}

ElementDetector::ElementDetector (WindowController* controller):searchingAlgorithm(0)
{
  //todo:: Not implemented yet
}
ElementDetector::ElementDetector (const ElementDetector& orig) { }

ElementDetector::~ElementDetector () 
{
  if(searchingAlgorithm!=0)
    delete searchingAlgorithm;
}
void ElementDetector::SetAlgorithm (SearchingAlgorithmBase* sab)
{
  if(searchingAlgorithm==0)
    {
      searchingAlgorithm=sab;
     
    }
}
bool ElementDetector::Detect (const cv::Mat& input)
{
  
  input.copyTo (output);
  
  ELEMENTS elements;
  
  SASimpleParams parameters;

  
  parameters.range=21;
  parameters.threshold=threshold;;
  
  this->searchingAlgorithm->SetParameters (reinterpret_cast<void*>(&parameters));
  this->searchingAlgorithm->Find(elements,output);
  
 
  return false;
}
cv::Mat ElementDetector::GetOutput ()
{
  return this->searchingAlgorithm->GetOutput ();
}

void ElementDetector::Threshold(int thresh)
{
  threshold=thresh;
}