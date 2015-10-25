/* 
 * File:   Displayer.cpp
 * Author: tester
 * 
 * Created on 22 październik 2015, 19:45
 */

#include "../headers/Displayer.h"

Displayer::Displayer()
{
  cv::namedWindow("output");
  cv::setMouseCallback("output",onMouse,this);
}

Displayer::Displayer(const Displayer& orig) 
{
  
}

Displayer::~Displayer() {
}


////////////////
///METHODS/////
void Displayer::onMouse(int eventType,int x,int y,int cos,void* ptr)
{
 
  if(eventType==cv::EVENT_LBUTTONDOWN)
  {
  Displayer *disp = reinterpret_cast<Displayer*>(ptr);
  
  MouseEvent event(eventType,x,y);
  disp->TranslateEvents (event);
  }
}


void Displayer::changeSize(const cv::Mat & input,cv::Mat & output)
{
  output =cv::Mat(cv::Size(400,300),CV_8U);
  cv::resize(input,output,output.size(),0,0);
}



bool Displayer::Draw (const cv::Mat& bigpicture)
{
  
  cv::Mat picture;
  changeSize(bigpicture,picture);
  
  
  if(matWhole.empty())
  {
  unsigned int buttonWidth=200;
  unsigned int buttonHeight=50;
  matWhole=cv::Mat(picture.rows+buttonHeight,picture.cols+buttonWidth+1,picture.type (),cv::Scalar(0));
  
  std::string firstButtonText="Szukaj";
  cv::Rect firstButtonPos(picture.cols+1,1,buttonWidth,buttonHeight);
  
  std::string secondButtonText="Koryguj";
  cv::Rect secondButtonPos(firstButtonPos);
  secondButtonPos.y+=buttonHeight+1;
  
  std::string thirdButtonText="Zaznacz";
  cv::Rect thirdButtonPos(secondButtonPos);
  thirdButtonPos.y+=buttonHeight+1;
  
  
  menu.addElement(new FieldWithText(firstButtonPos,firstButtonText));
  menu.addElement(new FieldWithText(secondButtonPos,secondButtonText));
  menu.addElement (new FieldWithText(thirdButtonPos,thirdButtonText));
  
  menu.draw(matWhole);
  }
  
  cv::Rect roi(0,0,picture.cols,picture.rows);
  cv::Mat image_roi=matWhole(roi);
  picture.copyTo (image_roi);
  cv::imshow("output",matWhole);
  
  return false;
}


ProgramEvent Displayer::TranslateEvents(MouseEvent & event)
{
 ProgramEvent evt= menu.translateEvents (event);
 return evt;
}