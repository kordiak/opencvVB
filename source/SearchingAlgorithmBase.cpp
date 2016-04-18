/* 
 * File:   SearchingAlgorithmBase.cpp
 * Author: tester
 * 
 * Created on 7 grudzień 2015, 09:05
 */

#include "../headers/SearchingAlgorithmBase.h"




SearchingAlgorithmBase::SearchingAlgorithmBase () { }


SearchingAlgorithmBase::SearchingAlgorithmBase (const SearchingAlgorithmBase& orig) { }



cv::Mat SearchingAlgorithmBase::GetOutput ()
{
  return outputMat;
}