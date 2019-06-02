
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "staticList.hpp"

int read_file(char* file, Student **s) {
  FILE *fp , *fpb ;
  char fileb[21];
  int i = 0;

  strcpy(fileb,"");
  strcat(fileb,file);
  strcat(fileb,".bin");
  strcat(file,".txt");
  fp = fopen(file, "r");
  fpb = fopen(fileb, "w+b");
  if (fp != NULL) {
    // fseek(fp, 0, SEEK_SET);
    // fseek(fpb, 0, SEEK_SET);
    Student aux;
    memset(aux.name,'\0' , sizeof(aux.name));
    while(fscanf(fp, "%d %21s %lf %lf %lf", &aux.reg,
                                      aux.name,
                                      &aux.grade[0], &aux.grade[1], &aux.grade[2]) == 5) {

      fwrite(&aux, sizeof(Student), 1, fpb);
      //memset(aux.name, 0, sizeof(aux.name));
    }
    fclose(fp);
    fp = NULL;
    fclose(fpb);
    fpb = NULL;
    fpb = fopen(fileb, "r+b");
    // fseek(fpb, 0L, SEEK_SET);
    i = 0;
    while (fread(&aux, sizeof(Student), 1, fpb) == 1) {
      if (i == 0) {
        *s = (Student*) malloc(sizeof(Student));
      } else {
        *s = (Student*) realloc(*s, sizeof(Student)*(i+1));
      }
      *(*s + i) = aux;
      i+= 1;
      //fseek(fpb, sizeof(Student)*i, SEEK_SET);
    }
  }
  fclose(fpb);
  fpb = NULL;
  return i;
}

int sum(int a, int b) {
  return a + b;
}