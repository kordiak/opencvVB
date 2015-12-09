/* 
 * File:   SASimple.cpp
 * Author: tester
 * 
 * Created on 7 grudzień 2015, 19:15
 */

#include <opencv2/imgproc.hpp>

#include "../headers/SASimple.h"

SASimple::SASimple () { }

SASimple::SASimple (const SASimple& orig) { }

SASimple::~SASimple () { }


cv::Mat SASimple::sharpenInclines (cv::Mat& input)
{
  cv::Mat kernel =cv::Mat::zeros(3,3,CV_32F);
  
  cv::Mat leftUpper2bottom=cv::Mat::zeros(input.size(),input.type ());
  cv::Mat rightUpper2bottom=cv::Mat::zeros(input.size(),input.type ());
  cv::Mat leftBottom2Upper=cv::Mat::zeros(input.size(),input.type ());
  cv::Mat rightBottom2Upper=cv::Mat::zeros(input.size(),input.type ());
  
  
  kernel.at<float>(0,0)=-1;
  kernel.at<float>(1,1)=1;
  cv::filter2D (input,leftUpper2bottom,leftUpper2bottom.depth (),kernel);
  
  kernel.at<float>(0,0)=0;
  kernel.at<float>(0,2)=-1;
  cv::filter2D(input,rightUpper2bottom,rightUpper2bottom.depth(),kernel);
  
  kernel.at<float>(0,2)=0;
  kernel.at<float>(2,0)=-1;
  cv::filter2D (input,leftBottom2Upper,leftBottom2Upper.depth(),kernel);
  
  kernel.at<float>(2,0)=0;
  kernel.at<float>(2,2)=-1;
  cv::filter2D(input,rightBottom2Upper,rightBottom2Upper.depth(),kernel);
  
  
  
  
  return leftUpper2bottom | rightUpper2bottom | leftBottom2Upper | rightBottom2Upper;
}

cv::Mat SASimple::sharpenHorizontals (cv::Mat& input)
{
  cv::Mat kernel =cv::Mat::zeros(3,3,CV_32F);
  kernel.at<float>(0,1)=-1;
  kernel.at<float>(1,1)=1;
  
  cv::Mat up2bottom=cv::Mat::zeros(input.size(),input.type ());
  cv::filter2D (input,up2bottom,up2bottom.depth (),kernel);
  
  
  kernel.at<float>(0,1)=0;
  kernel.at<float>(2,1)=-1;
  cv::Mat bottom2up=cv::Mat::zeros(input.size(),input.type ());
  cv::filter2D (input,bottom2up,bottom2up.depth (),kernel);
  
  
  return up2bottom | bottom2up;
  
  
}
cv::Mat SASimple::sharpenVerticals (cv::Mat& input)
{
  cv::Mat kernel =cv::Mat::zeros(3,3,CV_32F);
  kernel.at<float>(1,0)=-1;
  kernel.at<float>(1,1)=1;
  
  cv::Mat left2right=cv::Mat::zeros(input.size(),input.type ());
  cv::filter2D (input,left2right,left2right.depth (),kernel);
  
  
  kernel.at<float>(1,0)=0;
  kernel.at<float>(1,2)=-1;
  cv::Mat right2left = cv::Mat::zeros(input.size(),input.type());
  cv::filter2D (input,right2left,right2left.depth (),kernel);
  
  
  
  return left2right | right2left;
}


bool SASimple::Find (ELEMENTS& elements, cv::Mat& input)
{
 
  
  cv::Mat vertical = sharpenVerticals (input);
  cv::Mat horizontal = sharpenHorizontals(input);
  cv::Mat inclines = sharpenInclines(input);
  cv::Mat result = vertical | horizontal | inclines ;
  
  
   cv::Mat output;
   cv::adaptiveThreshold (input,output,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,input.cols/4+1,0.01);
  
 
  /*
  cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
  kernel.at <float>(1,0)=-5;
  kernel.at<float>(1,1)=5;
   
  cv::Mat result(output.size(),CV_8U,cv::Scalar(0));
  cv::Mat right(output.size(),CV_8U,cv::Scalar(0));
   
  cv::filter2D (output,right,output.depth(),kernel);
  kernel.at<float>(1,0)=0;
  kernel.at<float>(1,2)=-1;
   
  cv::filter2D(output,result,-1,kernel);
   
  result|=right;
  */
  cv::imshow("owe",output);
  
  return false;
}