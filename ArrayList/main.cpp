// Copyright 2019 Daltro Oliveira Vinuto

#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.hpp"

int main(int argc, char **argv) {
  List* list = NULL;
  Student student_aux;
  int total = 5;
  Student array[total] = {{111, "Galileu", 5.0, 5.0, 5.0},
                      {222, "Newton", 6.0, 6.0, 6.0},
                      {333, "Maxwell", 7.0, 7.0, 7.0},
                      {444, "Faraday", 8.0, 8.0, 8.0},
                      {555, "Newton", 9.0 , 9.0, 9.0}};
  
  list = new_list(total);
  if (list != NULL) {
    print_list(list);
    for (int i = 0; i < total; i+= 1) {
      add_begin(list, array[i]);
      print_list(list);
    }
    printf("======\n");
    if (Working == search_pos(list, 5, &student_aux)) {
      print_student(student_aux);
    }
    printf("======\n\n");
    for (int i = 0; i < total; i+= 1) {
      remove_begin(list);
      print_list(list);
    }
  }

  delete_list(list);
  return 0;
}