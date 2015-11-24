/* 
 * File:   FileReader.h
 * Author: tester
 *
 * Created on 10 listopad 2015, 14:30
 */


#include <cstdio>
#include <iostream>
#include <string>

#ifndef FILEREADER_H
#define	FILEREADER_H

class FileReader
{
  const char dirSep;
public:
  FileReader ();
  FileReader (const FileReader& orig);
  virtual ~FileReader ();
private:

};

#endif	/* FILEREADER_H */

