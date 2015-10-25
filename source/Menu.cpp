/* 
 * File:   Menu.cpp
 * Author: tester
 * 
 * Created on 24 październik 2015, 13:50
 */



#include "../headers/Menu.h"


Menu::Menu () { }

Menu::Menu (const Menu& orig) { }

Menu::~Menu () 
{
  unsigned int size=elements.size();
  for(unsigned int i=0;i < size;++i)
    {
      delete elements[i];
    }
}

//////////////
////METHODS//


void Menu::addElement(FieldWithText* field)
{
  this->elements.push_back (field);
}
//todo
void Menu::removeElements()
{
  unsigned int size=elements.size();
  for(unsigned int i=0;i<size;++i)
    {
     delete elements[i];
      
    }
  elements.clear();
    
}
ProgramEvent Menu::translateEvents(MouseEvent& event)
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

void Menu::draw(cv::Mat& output)
{
  unsigned int size=elements.size ();
  for(unsigned int i=0;i< size;++i)
  {
      elements[i]->draw (output);
  }
  
}