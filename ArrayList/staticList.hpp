// Copyright 2019 Daltro Oliveira Vinuto

#ifndef STATICLIST__HPP__
#define STATICLIST__HPP__

const int MAX = 100;

typedef struct student {
  int reg;
  char name[MAX];
  double grade[3];
} Student;

int sum(int, int);
int read_file(char*, Student**);

#endif // STATICLIST__HPP__
