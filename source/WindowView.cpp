/* 
 * File:   Displayer.cpp
 * Author: tester
 * 
 * Created on 22 październik 2015, 19:45
 */




#include <thread>
#include "../headers/WindowView.h"
#include "../headers/WindowController.h"

WindowView::WindowView ()
{
  cv::namedWindow ("output");
  cv::setMouseCallback ("output", onMouse, this);
}

WindowView::WindowView (WindowController * prManager)
{
  mPrManager = prManager;
  cv::namedWindow ("output");

  this->mInput = ProgramEvent::EVENT_NONE;
  this->mOutput = ProgramEvent::EVENT_NONE;
}

WindowView::WindowView (const WindowView& orig) {
 }

WindowView::~WindowView () { }


////////////////
///METHODS/////

void
WindowView::onMouse (int eventType, int x, int y, int cos, void* ptr)
{

  if (eventType == cv::EVENT_LBUTTONDOWN)
    {

      WindowView *disp = reinterpret_cast<WindowView*> (ptr);

      MouseEvent event (eventType, x, y);

      if (disp->mInput != ProgramEvent::EVENT_FREEZE)
        {

          disp->mOutput = disp->TranslateEvents (event);
          if (disp->mOutput == ProgramEvent::EVENT_NOTME && x < width && y < height)
            {

              disp->mOutput = ProgramEvent::EVENT_PAINT;
              disp->mMouseEvent = event;
            }

        }
      // disp->prManager->SendEvent(disp->TranslateEvents (event));

    }
}

void
WindowView::changeSize (const cv::Mat & input, cv::Mat & output)
{

  int w = input.cols / width;
  int h = input.rows / (w);
  output = cv::Mat (cv::Size (width, h), CV_8U);
  cv::resize (input, output, output.size (), 0, 0);
}

bool
WindowView::Draw (const cv::Mat& bigpicture, bool busy)
{

  cv::setMouseCallback ("output", onMouse, this);
  mOutput = ProgramEvent::EVENT_NONE;

  cv::Mat picture;
  changeSize (bigpicture, picture);


  if (matWhole.empty ())
    {

      unsigned int buttonWidth = 200;
      unsigned int buttonHeight = 50;
      matWhole = cv::Mat (picture.rows + buttonHeight, picture.cols + buttonWidth + 1, picture.type (), cv::Scalar (0));

      std::string firstButtonText = "Find";
      cv::Rect firstButtonPos (picture.cols + 1, 1, buttonWidth, buttonHeight);

      std::string secondButtonText = "Calib";
      cv::Rect secondButtonPos (firstButtonPos);
      secondButtonPos.y += buttonHeight + 1;

      std::string thirdButtonText = "Select";
      cv::Rect thirdButtonPos (secondButtonPos);
      thirdButtonPos.y += buttonHeight + 1;

      std::string fourthButtonText = "Close";
      cv::Rect fourthButtonPos (thirdButtonPos);
      fourthButtonPos.y += buttonHeight + 1;

      std::string fifthButtonText = "Draw";
      cv::Rect fifthButtonPos (fourthButtonPos);
      fifthButtonPos.y += buttonHeight + 1;

      std::string sixthButtonText = "Refresh";
      cv::Rect sixthButtonPos (fifthButtonPos);
      sixthButtonPos.y += buttonHeight + 1;

      std::string seventhButtonText = "Background";
      cv::Rect seventhButtonPos (sixthButtonPos);
      seventhButtonPos.y += buttonHeight + 1;


      mMenu.addElement (new FieldWithText (firstButtonPos, firstButtonText, ProgramEvent::EVENT_SEARCH));
      mMenu.addElement (new FieldWithText (secondButtonPos, secondButtonText, ProgramEvent::EVENT_CALIBRATE));
      mMenu.addElement (new FieldWithText (thirdButtonPos, thirdButtonText, ProgramEvent::EVENT_SELECT));
      mMenu.addElement (new FieldWithText (fourthButtonPos, fourthButtonText, ProgramEvent::EVENT_CLOSE));
      mMenu.addElement (new FieldWithText (fifthButtonPos, fifthButtonText, ProgramEvent::EVENT_LINE));
      mMenu.addElement (new FieldWithText (sixthButtonPos, sixthButtonText, ProgramEvent::EVENT_LOADNEWIMAGE));
      mMenu.addElement (new FieldWithText (seventhButtonPos, seventhButtonText, ProgramEvent::EVENT_SELECT_BG));

      mMenu.draw (matWhole);
    }

  cv::Rect roi (0, 0, picture.cols, picture.rows);
  cv::Mat image_roi = matWhole (roi);
  picture.copyTo (image_roi);

  if (busy)
    {
      cv::rectangle (matWhole, cv::Point (100, 100), cv::Point (200, 200), cv::Scalar (255));
    }
  cv::imshow ("output", matWhole);

  cv::waitKey (500);
  std::this_thread::__sleep_for (std::chrono::seconds (0), std::chrono::nanoseconds (50000000));
  return false;
}

ProgramEvent
WindowView::TranslateEvents (MouseEvent & event)
{
  ProgramEvent evt = mMenu.translateEvents (event);
  return evt;
}

ProgramEvent
WindowView::PopEvent ()
{
  ProgramEvent event = mOutput;
  mOutput = ProgramEvent::EVENT_NONE;
  return event;
}

void
WindowView::PushEvent (ProgramEvent event)
{
  mInput = event;
}

MouseEvent
WindowView::GetMouseEvent () const
{
  return mMouseEvent;
}