/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 */

#include "sample.h"

int MyOffset::SetOffset(int offset) {
  if (offset < 0) {
    offset_ = -1;
    return -1;
  }
  offset_ = DoSetOffset(offset);
  return offset_;
}
