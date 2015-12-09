/* 
 * File:   Calibrator.cpp
 * Author: tester
 * 
 * Created on 25 listopad 2015, 18:56
 */

#include <opencv2/calib3d/calib3d.hpp>

#include "../headers/Calibrator.h"

//private:

cv::Size
Calibrator::prepareImagePoints (ImageSource& imagesource, const cv::Size& sizeOfPattern, IMAGEPOINTS& pointsOnImage)
{

  cv::Mat image;

  //Get image, till the end of stream

  cv::Size size;

  while ((!(image = imagesource.GetImage ()).empty ())&& !imagesource.EOS ())
    {
      cv::cvtColor (image, image, CV_BGR2GRAY);
      bool found = false;
      std::vector<cv::Point2f> singleImagePoints;
      found = cv::findChessboardCorners (image, sizeOfPattern, singleImagePoints);

      if (found)
        {
          cv::cornerSubPix (image, singleImagePoints, cv::Size (11, 11), cv::Size (-1, -1), cv::TermCriteria (cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));
          pointsOnImage.push_back (singleImagePoints);

        }

      size = image.size ();
    }

  return size;
}

void
Calibrator::prepareImaginaryPoints (const IMAGEPOINTS& pointsOnImage, const cv::Size& sizeOfPattern, IMAGINARYPOINTS& imaginaryPoints)
{
  float squaresize = 1.f;

  imaginaryPoints.push_back (std::vector<cv::Point3f>());

  for (unsigned int i = 0; i < sizeOfPattern.height; ++i)
    {
      for (unsigned int j = 0; j < sizeOfPattern.width; ++j)
        {
          imaginaryPoints[0].push_back (cv::Point3f (static_cast<float> (j * squaresize), static_cast<float> (i * squaresize), 0.f));
        }
    }

  imaginaryPoints.resize (pointsOnImage.size (), imaginaryPoints[0]);
}

Calibrator::Calibrator ()
{
  cameraMatrix = cv::Mat::eye (3, 3, CV_64F);
  distCoeffs = cv::Mat::zeros (8, 1, CV_64F);
}

bool
Calibrator::Calibrate (const char * name, const cv::Size& sizeOfPattern)
{

  ImageSource fr (name);
  IMAGEPOINTS imagePoints;
  IMAGINARYPOINTS imaginarypoints;

  bool calibrated = false;

  std::vector<cv::Mat> rvces;
  std::vector<cv::Mat> tvces;

  cv::Size imageSize;

  imageSize = prepareImagePoints (fr, sizeOfPattern, imagePoints);


  if (imagePoints.size () > 3)
    {

      prepareImaginaryPoints (imagePoints, sizeOfPattern, imaginarypoints);

      double rms = cv::calibrateCamera (imaginarypoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvces, tvces, cv::CALIB_FIX_K4 | cv::CALIB_FIX_K5);

      bool calibrated = cv::checkRange (cameraMatrix) && cv::checkRange (distCoeffs);


      if (calibrated)
        {
          for (int i = 0; i < cameraMatrix.rows; ++i)
            {

              std::cout << std::endl;
              for (int j = 0; j < cameraMatrix.cols; ++j)
                {
                  std::cout << cameraMatrix.at<double>(i, j) << " ";

                }

            }
        }
    }

  return calibrated;
}
cv::Mat Calibrator::Undistort(const cv::Mat& input,cv::Mat& output)
{
  cv::undistort (input,output,this->cameraMatrix,this->distCoeffs); 
  return output;
}
Calibrator::Calibrator (const Calibrator& orig) { }

Calibrator::~Calibrator () {
 }

