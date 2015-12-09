/* 
 * File:   ImageSource.cpp
 * Author: tester
 * 
 * Created on 10 listopad 2015, 14:23
 */

#include "../headers/ImageSource.h"

///TODO : PRzenieść kod z każdej platrofmy do osobnego pliku, i zrobić include w zależności od systemu w cmaku, przeniesc dzialanie na foldreach do osobnej klasy

#if  !defined(__CYGWIN__) && defined(_WIN32) || defined(WIN32) || defined(__WIN32) 

#define WINDOWS
#include <windows.h>

//na wsb maila wysylac


#elif defined(__linux__) || defined(__unix__)
#define LINUX  
#include <cstdio>
#include <cerrno>
#include <sys/stat.h>
#include <sys/io.h>
#include <dirent.h>

#elif defined(__APPLE__)
#define OSX
std::cerr << "NOT IMPLEMENTED YET : LINE NUMBER: " << __LINE__ << " FILENAME: " << __FILE__ << " FUNCTION: " << __func__;

#endif

unsigned int
ImageSource::getLength (const char* text)
{
  if (text == 0)
    return 0;

  unsigned int length = 0;
  while (text[length] != '\0')
    {
      ++length;
    }

  return length;
}

void
ImageSource::stringtolower (char * text)
{
  if (text == 0)
    return;

  unsigned int i = 0;
  while (text[i] != '\0')
    {
      text[i] = tolower (text[i]);
      i++;
    }
}

bool
ImageSource::isHttp (const char* link)
{
  //todo: It is not necessary to copy the whole link, first  7 char should be enought.
  if (link != 0)
    {

      unsigned int sizeOfPath = getLength (link);
      char * copiedText = new char[sizeOfPath + 1];

      strcpy (copiedText, link);
      stringtolower (copiedText);

      std::string httpName = "http://";

      if (sizeOfPath >= httpName.length ())
        {
          if (strncmp (httpName.c_str (), copiedText, httpName.length ()) == 0)
            {
              delete[] copiedText;
              return true;
            }
        }

      delete[] copiedText;
    }
  return false;
}

bool
ImageSource::isDirectory (const char* link)
{
#ifdef WINDOWS

  DWORD ftype = GetFileAttributes (link);
  if (ftype == INVALID_FILE_ATTRIBUTES)
    return false;
  if (ftype & FILE_ATTRIBUTES_DIRECTORY)
    return true;
  return false;
#elif defined(LINUX) 

  int status;
  struct stat st_buf;

  status = stat (link, &st_buf);

  if (status != 0)
    {
      std::cout << "ERROR";
      return false;

    }

  if (S_ISREG (st_buf.st_mode))
    return false;
  if (S_ISDIR (st_buf.st_mode))
    return true;

#elif defined(OSX)
  std::cerr << "NOT IMPLEMENTED YET : LINE NUMBER: " << __LINE__ << " FILENAME: " << __FILE__ << " FUNCTION: " << __func__;
  return false;
#endif


}

bool
ImageSource::getFilesName (const char* filename, FILENAMES & filenames)
{
#ifdef WINDOWS 
  std::cerr << "NOT IMPLEMENTED YET : LINE NUMBER: " << __LINE__ << " FILENAME: " << __FILE__ << " FUNCTION: " << __func__;
#elif defined(LINUX)
  DIR * dir;
  struct dirent *ent;


  if ((dir = opendir (filename)) != 0)
    {
      while ((ent = readdir (dir)) != 0)
        {
          std::string path=filename;
          path+="/";
          path+=ent->d_name;
          std::cout << path;
          filenames.push_back (path);
         
        }
      closedir (dir);
    }
#elif defined(OSX)  
  std::cerr << "NOT IMPLEMENTED YET : LINE NUMBER: " << __LINE__ << " FILENAME: " << __FILE__ << " FUNCTION: " << __func__;
#endif
  return false;
}

ImageSource::ImageSource (const char* filename, int type) : position (0), eos(false)
{

  
  
  if (isHttp (filename))
    {
      type = source_type::http;
      std::cout << "Http";
    }
  else if (isDirectory (filename))
    {

      std::cout << "Directory";
      this->getFilesName (filename, files);

    }
  else
    {
      std::cout << "Photo";
      files.push_back (filename);
    }
  
  type = source_type::photo;
}

ImageSource::ImageSource (const ImageSource& orig) {
 }

ImageSource::~ImageSource ()
{



  unsigned int size = images.size ();
  for (unsigned int i = 0; i < size; ++i)
    {
     // delete images[i];
    }
}

ImageSource::source_type
ImageSource::GetType () const
{
  return type;
}

cv::Mat
ImageSource::GetImage ()
{
  cv::Mat newMat;

  
  if (!files.empty ())
    {
      while (newMat.empty () && position < files.size ())
        {
          //std::cout << std::endl << files[position];
          newMat = cv::imread (files[position].c_str());
          position++;

        }

    }
  
  if(newMat.empty())
    {
      eos=true;
      return cv::Mat(10,10,CV_8UC1,cv::Scalar(0));
    }
  return newMat;
}

bool ImageSource::EOS() const
{
  return eos;
}