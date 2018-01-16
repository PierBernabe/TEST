#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(char *str) {
  char buffer[30]; 
  printf("%p\n", buffer); 
  strcpy(buffer, str); //copie de str dans buffer
  printf("%s\n", buffer); 
}

int main(int argc, char **argv) {
  if (argc != 2) {
    exit(0); 
  }
  foo(argv[1]); 
  return 0; 
}
