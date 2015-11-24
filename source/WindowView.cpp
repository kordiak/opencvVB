/* 
 * File:   Displayer.cpp
 * Author: tester
 * 
 * Created on 22 październik 2015, 19:45
 */

#include "../headers/WindowView.h"
#include "../headers/WindowController.h"
WindowView::WindowView()
{
  cv::namedWindow("output");
  cv::setMouseCallback("output",onMouse,this);
}
WindowView::WindowView(WindowController * prManager)
{
  prManager=prManager;
  cv::namedWindow("output");
  cv::setMouseCallback("output",onMouse,this);
}

WindowView::WindowView(const WindowView& orig) 
{
  
}

WindowView::~WindowView() {
}


////////////////
///METHODS/////
void WindowView::onMouse(int eventType,int x,int y,int cos,void* ptr)
{
  
  if(eventType==cv::EVENT_LBUTTONDOWN)
  {
  WindowView *disp = reinterpret_cast<WindowView*>(ptr);
  
  MouseEvent event(eventType,x,y);
  disp->prManager->SendEvent(disp->TranslateEvents (event));
  }
}


void WindowView::changeSize(const cv::Mat & input,cv::Mat & output)
{
  output =cv::Mat(cv::Size(400,300),CV_8U);
  cv::resize(input,output,output.size(),0,0);
}



bool WindowView::Draw (const cv::Mat& bigpicture)
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
  
  
  menu.addElement(new FieldWithText(firstButtonPos,firstButtonText,ProgramEvent::EVENT_SEARCH));
  menu.addElement(new FieldWithText(secondButtonPos,secondButtonText,ProgramEvent::EVENT_CALIBRATE));
  menu.addElement (new FieldWithText(thirdButtonPos,thirdButtonText,ProgramEvent::EVENT_SELECT));
  
  menu.draw(matWhole);
  }
  
  cv::Rect roi(0,0,picture.cols,picture.rows);
  cv::Mat image_roi=matWhole(roi);
  picture.copyTo (image_roi);
  cv::imshow("output",matWhole);
  
  return false;
}


ProgramEvent WindowView::TranslateEvents(MouseEvent & event)
{
 ProgramEvent evt= menu.translateEvents (event);
 return evt;
}