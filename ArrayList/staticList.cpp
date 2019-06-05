
#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.hpp"

// create a new list and delete a list ====================================================================
List* new_list(int max) {
  List *list = NULL;
  list = (List*) malloc(sizeof(List));
  if (list != NULL) {
    list->max = max;
    list->size = 0;
    list->array = (Student*) malloc(list->max*sizeof(Student));
  }
  return list;
}

void delete_list(List* list) {
  if (list != NULL) {
    free(list->array);
    list->array = NULL;
    free(list);
    list = NULL;
  }
}

// check if a list is empty or full      =================================================================================
Logic empty_list(List* list) {
  Logic logic;
  if (list->size == 0) {
    logic = True;
  } else {
    logic = False;
  }
  return logic;
}

Logic full_list(List* list) {
  Logic logic;
  if (list->size == list->max) {
    logic = True;
  } else {
    logic = False;
  }
  return logic;
}

// add elements inside the list   =====================================================================================
State add_begin(List* list, Student s) {
  State state;
  if (list == NULL || full_list(list) == True) {
    state = Failed;
  } else {
    list->array[list->size] = list->array[0];
    list->array[0] = s;
    list->size+= 1;
    state = Working;
  }
  return state;
}

State add_end(List* list, Student s) {
  State state;
  if (list == NULL || full_list(list) == True) {
    state = Failed;
  } else {
    list->array[list->size] = s;
    list->size+= 1;
    state = Working;
  }
  return state;
}

State add_pos(List* list, int pos, Student s) {
  State state;
  if (list == NULL || full_list(list) == True || pos <= 0 || pos > list->max || pos > list->size+1) {
    state = Failed;
  } else {
    list->array[list->size] = list->array[pos-1];
    list->array[pos-1] = s;
    list->size+= 1;
    state = Working;
  }
  return state;
}

// remove elements from the list =================================================================================
State remove_begin(List* list) {
  State state;
  if (list == NULL || empty_list(list) == True) {
    state = Failed;
  } else {
    list->array[0] = list->array[list->size-1];
    list->size-= 1;
    state = Working;
  }
  return state;
}

State remove_end(List* list) {
  State state;
  if (list == NULL || empty_list(list) == True) {
    state = Failed;
  } else {
    list->size-= 1;
    state = Working;
  }
  return state;
}

State remove_pos(List* list, int pos) {
  State state;
  if (list == NULL || empty_list(list) == True || pos <= 0 || pos > list->max) {
    state = Failed;
  } else {
    list->array[pos-1] = list->array[list->size-1];
    list->size-= 1;
    state = Working;
  }
  return state;
}

// Search for a element ===================================================================================
State search_pos(List* list, int pos, Student *s) {
  State state;
  if (list == NULL || empty_list(list) == True || pos <= 0 || pos >= list->max) {
    state = Failed;
  } else {
    *s = list->array[pos-1];
    state = Working;
  }
  return state;
}

// Print the all list or the some struct Student
State print_list(List* list) {
  State state;
  if (list == NULL) {
    state = Failed;
  } else {
    if (empty_list(list) == True) {
      printf("Empty List!\n\n");
    } else {
      for (int i = 0; i < list->size; i+= 1) {
        print_student(list->array[i]);
      }
      printf("\n");
    }
    state = Working;
  }
  return state;
}

void print_student(Student s) {
  printf("Reg: %d\n", s.reg);
  printf("Name: %s\n", s.name);
  printf("Grades: ");
  for (int i = 0; i < 3; i+= 1) {
    printf("%.1lf\t", s.grades[i]);
  }
  printf("\n");
}




