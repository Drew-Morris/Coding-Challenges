#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#include "RomanToDecimal.h"

void convert(const std::string& str, RomanToDecimal& converter);

int main(int argc, char** argv) {

  if (argc > 3) {
    fprintf(stderr,"Error: Invalid Args - Expected: {Input File}, {Output File}\n");
    exit(1);
  }

  if (argc > 2) { // Redirect Output
    FILE* fout = fopen(argv[argc - 1],"w");
    if (fout != NULL && fileno(stdout) != fileno(fout)) {
      dup2(fileno(fout),fileno(stdout));
      close(fileno(fout));
    }
  }

  RomanToDecimal converter = RomanToDecimal();

  if (argc > 1) { // Redirect Input
    FILE* fin = fopen(argv[1],"r");
    if (fin != NULL && fileno(stdin) != fileno(fin)) {
      dup2(fileno(fin),fileno(stdin));
      close(fileno(fin));
    }
  }
  for (std::string str; std::cin >> str;) {
    convert(str,converter);
  }

}

void convert(const std::string& str, RomanToDecimal& converter) {
  try {
    int num = converter.convert(str);
    std::cout << num << std::endl;
  } catch (std::string err) {
    std::cerr << err << std::endl;
  }
}
