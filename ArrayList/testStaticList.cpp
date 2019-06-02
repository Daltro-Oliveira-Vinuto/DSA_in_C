#include "gtest/gtest.h"
#include <string.h>
#include "staticList.hpp"


TEST(FirstTest, TestSum) {
  EXPECT_EQ(sum(3,13), 16);
}

Student *s;
char file[] = "input";

TEST(TestFile, File) {

  EXPECT_EQ(s[0].reg, 111);  
  EXPECT_EQ(strcmp(s[0].name, "Galileu"), 0);
  EXPECT_EQ(s[0].grade[0], 5.0);
  EXPECT_EQ(s[1].reg, 222);
  free(s);
}

int main(int argc, char **argv) {

  read_file(file, &s);

  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}