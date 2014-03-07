/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 */

// a sample program demonstrating using Google C++ Mock framework
// Author: shishougang@gmail.com

#ifndef SMAPLE_H
#define SMAPLE_H

#include <string>
using std::string;

//A simple Offset class
class MyOffset{
 public:
  MyOffset() {}
  virtual ~MyOffset() {}

  /*
   * Set the offsest
   */
  int SetOffset(int offset);

  /*
   * Returns the current offset
   */
  int offset() const { return offset_; }

 protected:
  /*
   * Set the offset
   *
   * This method is called by the public SetOffset() method.
   */
  virtual int DoSetOffset(int offset) = 0;
  
 private:
  int offset_; 
};

#endif //#ifndef SMAPLE_H
  
