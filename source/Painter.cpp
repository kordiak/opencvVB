/* 
 * File:   Painter.cpp
 * Author: tester
 * 
 * Created on 21 luty 2016, 17:43
 */


#include "../headers/Painter.h"
#include "../headers/PLYGenerator.h"
#include <map>
#include <iostream>
unsigned int borderColor = 255;
int tableWidth = 0;
int tableHeight = 0;
float tableWidthMM =318.5f;
float tableHeightMM= 224;


typedef std::map<int, int> Axis;
typedef std::pair<cv::Point, cv::Point> PairOfPoints;

inline void fullfillMinMax (const cv::Point& pointRef, int & xMax, int & yMax, int & xMin, int & yMin, PairOfPoints & xMaxMin, PairOfPoints & yMaxMin);
void findMinMax (std::vector<cv::Point>& points, int & xMax, int & yMax, int & xMin, int &yMin, PairOfPoints & xMaxMin, PairOfPoints & yMaxMin);
void shiftToZeroZero (std::vector<cv::Point>& points, int xMin, int yMin);
void
fullfillMinMax (const cv::Point& pointRef, int & xMax, int & yMax, int & xMin, int & yMin, PairOfPoints & xMaxMin, PairOfPoints & yMaxMin)
{

  int x, y;
  x = pointRef.x;
  y = pointRef.y;

  if (pointRef.x > xMax)
    {
      xMax = x;
      xMaxMin.first = cv::Point (x, y);
    }

  else
    if (x < xMin)
    {
      xMin = x;
      xMaxMin.second = cv::Point (x, y);
    }

  if (y > yMax)
    {
      yMax = y;
      yMaxMin.first = cv::Point (x, y);
    }
  else

    if (y < yMin)
    {
      yMin = y;
      yMaxMin.second = cv::Point (x, y);
    }
}

void
findMinMax (std::vector<cv::Point>& points, int & xMax, int & yMax, int & xMin, int &yMin, PairOfPoints & xMaxMin, PairOfPoints & yMaxMin)
{
  
  
  
  xMax = yMax = std::numeric_limits<int>::min ();
  yMin = xMin = std::numeric_limits<int>::max ();


  for (int i = 0; i < points.size (); ++i)
    {
      fullfillMinMax (points[i], xMax, yMax, xMin, yMin, xMaxMin, yMaxMin);
    }
}

void
shiftToZeroZero (std::vector<cv::Point>& points, int xMin, int yMin)
{
  for (int i = 0; i < points.size (); ++i)
    {
      cv::Point &point= points[i];
      point.x=point.x-xMin;
      point.y=point.y-yMin;
    }
}

void
Painter::floodfill (std::vector<cv::Point> & pointsOfLine, cv::Mat * ptr, int u, int v)
{
  
  pointsOfLine.clear ();
  int umax = ptr->cols;
  int vmax = ptr->rows;

  int x = u;
  int y = v;

  cv::Point2f q (u, v);

  if (q.x < 0 || q.x > umax - 1 || q.y < 0 || q.y > vmax - 1)
    return;

  std::vector<cv::Point> stack;
  stack.push_back (q);


  int xMax, yMax, yMin, xMin;
  xMax = yMax = std::numeric_limits<int>::min ();
  yMin = xMin = std::numeric_limits<int>::max ();
  std::pair<cv::Point, cv::Point> xMaxMin, yMaxMin;

  while (stack.size () > 0)
    {
      cv::Point p = stack.back ();
      stack.pop_back ();
      int x = p.x;
      int y = p.y;

      if (y < 0 || y > vmax - 1 || x < 0 || x > umax - 1)
        continue;

      unsigned char & place = ptr->at<unsigned char>(p);

      if (place < 100)
        {
          place = 100;
          stack.push_back (cv::Point (x + 1, y));
          stack.push_back (cv::Point (x - 1, y));
          stack.push_back (cv::Point (x, y + 1));
          stack.push_back (cv::Point (x, y - 1));

        }
      else
        if (place == 255)
        {
          pointsOfLine.push_back (cv::Point (x, y));
          fullfillMinMax (pointsOfLine.back (), xMax, yMax, xMin, yMin, xMaxMin, yMaxMin);
        }

    }


  if (mState == PainterState::FLOOD_BG)
    {
      tableWidth = xMax - xMin;
      tableHeight = yMax - yMin;
      printf ("H: %d W: %d\n", tableWidth, tableHeight);
      
      
     
    }
  else
    {
      cv::Point r;
      float sinalpha;
      float cosalpha;
      float w = std::sqrt (std::pow (xMaxMin.first.x - xMaxMin.second.x, 2.0) + std::pow (xMaxMin.first.y - xMaxMin.second.y, 2.0));
      float h = std::sqrt (std::pow (yMaxMin.first.x - yMaxMin.second.x, 2.0) + std::pow (yMaxMin.first.y - yMaxMin.second.y, 2.0));

      if (w > h)
        {
          r = cv::Point (xMaxMin.first.x - xMaxMin.second.x, xMaxMin.first.y - xMaxMin.second.y);

        }
      else
        {
          r = cv::Point (yMaxMin.first.x - yMaxMin.second.x, yMaxMin.first.y - yMaxMin.second.y);
        }

      sinalpha = (r.x - r.y) / sqrt (2 * (r.x * r.x + r.y * r.y));
      cosalpha = (r.x + r.y) / sqrt (2 * (r.x * r.x + r.y * r.y));

      for (int i = 0; i < pointsOfLine.size (); ++i)
        {
          cv::Point & point = pointsOfLine[i];
          float x = cosalpha * point.x - sinalpha * point.y;
          float y = sinalpha * point.x + cosalpha * point.y;
          point.x = x;
          point.y = y;

        }

      

      findMinMax (pointsOfLine, xMax, yMax, xMin, yMin, xMaxMin, yMaxMin);
      shiftToZeroZero(pointsOfLine,xMin,yMin);
      findMinMax (pointsOfLine, xMax, yMax, xMin, yMin, xMaxMin, yMaxMin);
      
      PLYGenerator generator;
      
      float mm2pxW = tableWidthMM/tableWidth;
      float mm2pxH = tableHeightMM/tableHeight;
      
      float materialWpx= materialWmm/mm2pxW;
      float materialHpx= materialHmm/mm2pxH;
      

      
     
      generator.Generate (pointsOfLine,xMax-xMin,yMax-yMin,materialWpx,materialHpx);
      
    }

}

Painter::Painter (cv::Mat * picture, int pointSize) : mPointSize (pointSize), mImage (picture)
{
  mStartPos = cv::Point (-1, -1);
  mColor = 255;
}

Painter::Painter () : mPointSize (6), mImage (0), mState (PainterState::FLOOD) { }

Painter::Painter (const Painter& orig) { }

void
Painter::Image (cv::Mat * image)
{
  mImage = image;
}

void
Painter::PointSize (int pointSize)
{
  mPointSize = pointSize;

}

void
Painter::State (PainterState state)
{
  mState = state;
  mStartPos = cv::Point (-1, -1);

}

void
Painter::Start (cv::Point startingPoint)
{
  this->mStartPos = startingPoint;
}

void
Painter::Color (unsigned char color)
{
  this->mColor = color;
}

void
Painter::Draw (int u, int v, int mouseEvent)
{

  float xRatio = mImage->cols / width;
  float yRatio = mImage->rows / height;

  u *= xRatio;
  v *= yRatio;

  if (mState == PainterState::LINE)
    {
      if (mouseEvent == cv::EVENT_LBUTTONDOWN && mStartPos.x == -1)
        {
          mStartPos.x = u;
          mStartPos.y = v;
        }
      else
        if (mouseEvent == cv::EVENT_LBUTTONDOWN)
        {

          drawLine (u, v);
        }

    }
  else
    if (mState == PainterState::FLOOD || mState == PainterState::FLOOD_BG)
    {

      if (mouseEvent == cv::EVENT_LBUTTONDOWN)
        {


          floodfill (mLastPoints, mImage, u, v);



       // PLYGenerator generator;
       // generator.Generate ("ply.ply", mLastPoints);
        }

    }

  /*
  
  int leftCorner=u-mPointSize/2;
  int topCorner=v-mPointSize/2;
  
  bool beyondZero=leftCorner<0 || topCorner <0;
  bool beyondSize=leftCorner+mPointSize>=InputOutput.cols ||  topCorner+mPointSize>=InputOutput.rows;
  
  //if(beyondZero || beyondSize)
   // return;
  
  
  
  
  cv::Point zeroPoint(leftCorner,topCorner);
  
  cv::Rect brush(zeroPoint,cv::Size(mPointSize,mPointSize));
  
  cv::Mat ROI=InputOutput(brush);
  
  ROI=0;
  
   */
}

void
Painter::drawLine (int u, int v)
{
  cv::line (*mImage, mStartPos, cv::Point (u, v), cv::Scalar (mColor), mPointSize);
  mStartPos.x = -1;
  mStartPos.y = -1;
}

const std::vector<cv::Point> &
Painter::GetPoints ()
{
  return mLastPoints;
}

Painter::~Painter () { }

