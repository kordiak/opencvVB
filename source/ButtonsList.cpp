/* 
 * File:   Menu.cpp
 * Author: tester
 * 
 * Created on 24 październik 2015, 13:50
 */



#include "../headers/ButtonsList.h"


ButtonsList::ButtonsList () { }

ButtonsList::ButtonsList (const ButtonsList& orig) { }

ButtonsList::~ButtonsList () 
{
  unsigned int size=elements.size();
  for(unsigned int i=0;i < size;++i)
    {
      delete elements[i];
    }
}

//////////////
////METHODS//


void ButtonsList::addElement(FieldWithText* field)
{
  this->elements.push_back (field);
}
//todo
void ButtonsList::removeElements()
{
  unsigned int size=elements.size();
  for(unsigned int i=0;i<size;++i)
    {
     delete elements[i];
      
    }
  elements.clear();
    
}
ProgramEvent ButtonsList::translateEvents(MouseEvent& event)
{
 
  unsigned int size=elements.size();
  for(unsigned int i=0; i < size;++i)
  {
      ProgramEvent evt=elements[i]->attendToEvent(event);
      if(evt!=EVENT_NOTME)
        return evt;
  }
  
  return EVENT_NOTME;
}

void ButtonsList::draw(cv::Mat& output)
{
  unsigned int size=elements.size ();
  for(unsigned int i=0;i< size;++i)
  {
      elements[i]->draw (output);
  }
  
}