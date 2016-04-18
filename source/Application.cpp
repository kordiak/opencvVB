/* 
 * File:   Application.cpp
 * Author: tester
 * 
 * Created on 12 grudzień 2015, 11:18
 */

#include "../headers/Application.h"


Application* Application::instance=0;

Application* Application::GetInstance ()
{
  if(!instance)
          instance=new Application();  
    
  return instance;
}

Application::Application()
{
  
}

Application::~Application ()
{
 // std::cout << " DEEE";
}