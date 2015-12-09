/* 
 * File:   ImageSource.h
 * Author: tester
 *
 * Created on 10 listopad 2015, 14:23
 */

#ifndef IMAGESOURCE_H
#define	IMAGESOURCE_H


#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include "opencvHeaders.h"



typedef std::vector<std::string> FILENAMES;



class ImageSource
{
private:
  
  bool eos;
  std::vector<cv::Mat*> images;
  cv::Mat picture;
  
  FILENAMES files;
  
  unsigned int position;
  
  
  bool isHttp(const char* link);
  bool isDirectory(const char* link);
  bool getFilesName(const char* filename,FILENAMES&);
  unsigned int getLength(const char* text);
  void stringtolower(char *);
  
public:
  
  enum source_type {photo,http,video};
  ImageSource (const char* filename,int type=-1);
  ImageSource (const ImageSource& orig);
  bool EOS() const;
  source_type GetType() const;
  cv::Mat GetImage() ;
  virtual ~ImageSource ();
  

private:
  source_type type;

};

#endif	/* IMAGESOURCE_H */

