/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 */

#include "sample.h"
#include <string>
using std::string;

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Return;

class MockMyOffset : public MyOffset {
 public:
  MockMyOffset() {}
  virtual ~MockMyOffset() {}

  MOCK_METHOD1(DoSetOffset, int(int offset));
};

TEST(MyOffsetTest, SetOffset) {
  MockMyOffset my_offset;
  EXPECT_CALL(my_offset, DoSetOffset(10)).WillOnce(Return(10));
  EXPECT_EQ(10, my_offset.SetOffset(10));
  EXPECT_EQ(10, my_offset.offset());

  EXPECT_CALL(my_offset, DoSetOffset(5)).WillOnce(Return(5));
  EXPECT_EQ(5, my_offset.SetOffset(5));
  EXPECT_EQ(5, my_offset.offset());

  EXPECT_CALL(my_offset, DoSetOffset(20)).WillOnce(Return(1));
  EXPECT_EQ(1, my_offset.SetOffset(20));
  EXPECT_EQ(1, my_offset.offset());

  EXPECT_CALL(my_offset, DoSetOffset(10)).WillOnce(Return(-1));
  EXPECT_EQ(-1, my_offset.SetOffset(10));
  EXPECT_EQ(-1, my_offset.offset());
}


