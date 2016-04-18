/* 
 * File:   Painter.cpp
 * Author: tester
 * 
 * Created on 21 luty 2016, 17:43
 */


#include "../headers/Painter.h"
#include "../headers/PLYGenerator.h"
#include <map>
unsigned int borderColor = 255;

typedef std::map<int, int> Axis;

void
floodfill (std::vector<cv::Point> & pointsOfLine, cv::Mat * ptr, int u, int v)
{

  int umax = ptr->cols;
  int vmax = ptr->rows;

  int x = u;
  int y = v;

  cv::Point2f q (u, v);

  if (q.x < 0 || q.x > umax - 1 || q.y < 0 || q.y > vmax - 1)
    return;

  std::vector<cv::Point> stack;
  stack.push_back (q);
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
        if(place==255)
          {
            pointsOfLine.push_back (cv::Point(x,y));
          }

    }


}

Painter::Painter (cv::Mat * picture, int pointSize) : mPointSize (pointSize), mImage (picture)
{
  mStartPos = cv::Point (-1, -1);
  mColor = 255;
}

Painter::Painter():mPointSize(6),mImage(0),mState(PainterState::POINT)
{
  
}
Painter::Painter (const Painter& orig) { }

void Painter::Image(cv::Mat * image)
{
  mImage=image;
}
void Painter::PointSize (int pointSize)
{
  mPointSize=pointSize;
 
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
Painter::Draw (int u, int v, int mouseEvent)
{

  float xRatio=mImage->cols/width;
  float yRatio=mImage->rows/height;
  
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
    if (mState == PainterState::POINT)
    {

      if (mouseEvent == cv::EVENT_LBUTTONDOWN)
        {

          
          floodfill (mLastPoints, mImage, u*xRatio, v*yRatio);
          
          PLYGenerator generator;
          generator.Generate ("ply.ply",mLastPoints);
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
}


const std::vector<cv::Point> & Painter::GetPoints()
{
  return mLastPoints;
}

Painter::~Painter () { }

