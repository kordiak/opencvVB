/* 
 * File:   PLYGenerator.cpp
 * Author: tester
 * 
 * Created on 28 luty 2016, 21:54
 */

#include "../headers/PLYGenerator.h"
#include <iostream>
#include <fstream>
#include <chrono>

PLYGenerator::PLYGenerator () { }

PLYGenerator::PLYGenerator (const PLYGenerator& orig) { }

PLYGenerator::~PLYGenerator () { }

std::string
PLYGenerator::getHeader (const std::vector<cv::Point> & points, int multi)
{

  char buffer[255];
  snprintf (buffer, 255, "%ld\n", points.size () * multi);
  std::string header;

  header = "ply\nformat ascii 1.0\nelement vertex ";
  header += buffer;
  header += "property float x\nproperty float y\nproperty float z\nelement face 0\nproperty list uchar int vertex_indices\nend_header\n";

  return header;
}

std::string
PLYGenerator::getPoints (const std::vector<cv::Point> & points, int col, int row)
{
  std::string pointsList;
  for (int i = 0; i < points.size (); ++i)
    {

      char bufferX[100];
      char bufferY[100];

      sprintf (bufferX, "%d", points[i].x + col);
      sprintf (bufferY, "%d", points[i].y + row);
      pointsList += std::string (bufferX) + " " + std::string (bufferY) + " " + "0.0\n";
    }
  return pointsList;
}

bool
PLYGenerator::Generate (const char* filename, const std::vector<cv::Point>& points)
{

  std::ofstream output (filename);
  bool is_opened = output.is_open ();

  if (is_opened)
    {

      output << getHeader (points);
      output << getPoints (points);


      output.close ();
      return true;
    }
  return false;
}

bool
PLYGenerator::Generate (const std::vector<cv::Point>& points, float elementWpx, float elementHpx, float tableWpx, float tableHpx)
{


  std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds > (std::chrono::system_clock::now ().time_since_epoch ());
  char buffer[500];
  snprintf (buffer, 500, "%ld.ply", ms.count ());

  std::ofstream output (buffer);
  bool is_opened = output.is_open ();

  if (is_opened)
    {

      int elementsPerRow = tableWpx / elementWpx + 1;
      int elementsPerColumn = tableHpx / elementHpx + 1;
      int amountOfElements = elementsPerRow* elementsPerColumn;

      output << getHeader (points, amountOfElements);

      for (int row = 0; row < elementsPerColumn; ++row)

        {
          for (int col = 0; col < elementsPerRow; ++col)
            {
              output << getPoints (points, col * (elementWpx), row * elementHpx);
            }
        }

      // output << getPoints(points,0*20,0*20);
      output.close ();
      return true;
    }
  return false;
}