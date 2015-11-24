/* 
 * File:   FileReader.cpp
 * Author: tester
 * 
 * Created on 10 listopad 2015, 14:30
 */

#include "../headers/FileReader.h"


#ifdef __linux__ 
#define separator '/'
#endif
#ifdef __APPLE__
#define separator '/'
#endif
#ifdef __MINGW32__
#define separator '\'
#endif



FileReader::FileReader () :dirSep(separator)
{

  std::cout << dirSep;

  
}

FileReader::FileReader (const FileReader& orig) :dirSep(separator)
{
 FileReader ();
}

FileReader::~FileReader () { }

