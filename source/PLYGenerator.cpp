/* 
 * File:   PLYGenerator.cpp
 * Author: tester
 * 
 * Created on 28 luty 2016, 21:54
 */

#include "../headers/PLYGenerator.h"
#include <iostream>
#include <fstream>
PLYGenerator::PLYGenerator () { }

PLYGenerator::PLYGenerator (const PLYGenerator& orig) { }

PLYGenerator::~PLYGenerator () { }


std::string PLYGenerator::getHeader(const std::vector<cv::Point> & points)
{
  
  char buffer[255];
  sprintf(buffer,"%ld\n",points.size ());
  std::string header;
  
  header="ply\nformat ascii 1.0\nelement vertex ";
  header+=buffer;
  header+="property float x\nproperty float y\nproperty float z\nelement face 0\nproperty list uchar int vertex_indices\nend_header\n";
  
  return header;
}
std::string PLYGenerator::getPoints(const std::vector<cv::Point> & points)
{
  std::string pointsList;
  for(int i=0; i<points.size ();++i)
    {
      
      char bufferX[100];
      char bufferY[100];
      
      sprintf(bufferX,"%d", points[i].x );
      sprintf(bufferY,"%d", points[i].y );
      pointsList+=std::string(bufferX)+" "+std::string(bufferY)+" "+"0.0\n";
    }
  return pointsList;
}

bool PLYGenerator::Generate (const char* filename, const std::vector<cv::Point>& points)
{
  
  std::ofstream output(filename);
  bool is_opened=output.is_open ();
  
  if(is_opened)
    {
     
      output << getHeader(points);
      output << getPoints(points);
      
      
      output.close ();
    }
  return false;
}