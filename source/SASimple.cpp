/* 
 * File:   SASimple.cpp
 * Author: tester
 * 
 * Created on 7 grudzień 2015, 19:15
 */

#include <opencv2/imgproc.hpp>
#include "../headers/Painter.h"
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




void SASimple::SetParameters (void* parameters)
{
  this->params=parameters;
}

cv::Mat SASimple::findContours(cv::Mat & input)
{
  
 // return input;
  

        cv::Mat output(input.size(),input.type(),cv::Scalar(0));//(input.size(),input.type (),0.f);
       // cv::Canny (input,output,255,255);
       
        std::vector<std::vector<cv::Point> > array;
        std::vector<cv::Vec4i> hier;
        
        cv::findContours (input,array,hier,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);
        
        cv::Mat contours(output.size(),output.type(),cv::Scalar(0));
       
       for(int i=0;i<array.size ();++i)
       if(array[i].size()>10)
        cv::drawContours (contours,array,i,cv::Scalar(255));
  
       
     
        
       
       // cv::imwrite("plik.jpg",contours);
        
        return contours;
        
        
}

bool SASimple::Find (ELEMENTS& elements, cv::Mat& input)
{
  
  cv::Mat output;
  
  SASimpleParams saparams;
  saparams.threshold=0.01;
  
  
  saparams.range=static_cast<int>(input.cols/4);
  if(saparams.range%2==0)
    saparams.range+=1;
  
  if(this->params!=0)
    saparams.threshold=reinterpret_cast<SASimpleParams*>(params)->threshold;
  
  input.copyTo (output);
 
  cv::Mat vertical = sharpenVerticals (output);
  cv::Mat horizontal = sharpenHorizontals(output);
  cv::Mat inclines = sharpenInclines(output);
  cv::Mat result = vertical | horizontal | inclines ;
  
  result.copyTo (outputMat);
  //outputMat=result ; //findContours(result);
  
  for(int r=0;r<outputMat.rows;++r)
    for(int w=0;w<outputMat.cols;++w)
      {
        if(outputMat.at<unsigned char>(r,w)>saparams.threshold)
        outputMat.at<unsigned char>(r,w)=255;
        else
          outputMat.at<unsigned char>(r,w)=0;
      }
  outputMat=findContours(outputMat);
  
  int type=outputMat.type ();
  return false;
}