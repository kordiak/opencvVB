/* 
 * File:   Painter.h
 * Author: tester
 *
 * Created on 21 luty 2016, 17:43
 */
#include "opencvHeaders.h"

#ifndef PAINTER_H
#define	PAINTER_H

enum PainterState { LINE,POINT };

class Painter
{
public:
  Painter (cv::Mat *,int pointSize=3);
  Painter (const Painter& orig);
  Painter();
  
  void Draw(int u, int v,int mouseEvent);
  
  
  
  
  
  void Start(cv::Point startingPoint);
  void Image(cv::Mat *);
  void PointSize(int);
  void State(PainterState state);
  void Color(unsigned char color);
  const std::vector<cv::Point>  &  GetPoints();
  virtual ~Painter ();
private:
  
  
  void drawLine(int u, int v);
  void drawPoint(int u, int v);
  
  
  int mPointSize;
  int mColor;
  cv::Point mStartPos;
  std::vector<cv::Point> mLastPoints;
  cv::Mat * mImage;
  PainterState mState;
  

};

#endif	/* PAINTER_H */

