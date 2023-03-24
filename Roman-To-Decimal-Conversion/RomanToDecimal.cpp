#include "RomanToDecimal.h"

RomanToDecimal::~RomanToDecimal() {delete[] flags;}

void RomanToDecimal::set_flag(int flag, bool val) {flags[flag] = val;}
void RomanToDecimal::flag_on(int flag) {set_flag(flag,true);}
void RomanToDecimal::flag_off(int flag) {set_flag(flag,false);}
void RomanToDecimal::switch_flag(int flag) {set_flag(flag,!flags[flag]);}
void RomanToDecimal::reset_flags() {
  for (size_t i = 0; i < NUM_SYMBOLS; ++i) {
    flag_off(i);
  }
}

size_t RomanToDecimal::symb_to_ind(char symbol) const {
  switch (symbol) {
    case ('I') : return 0;
    case ('V') : return 1;
    case ('X') : return 2;
    case ('L') : return 3;
    case ('C') : return 4;
    case ('D') : return 5;
    case ('M') : return 6;
    default : throw symbol;
  }
}

int RomanToDecimal::val_to_ind(int value) const {
  switch (value) {
    case (I) : return 0;
    case (V) : return 1;
    case (X) : return 2;
    case (L) : return 3;
    case (C) : return 4;
    case (D) : return 5;
    case (M) : return 6;
    default : throw value;
  }
}


bool RomanToDecimal::check_valid() {
  reset_flags();
  for (size_t i = 0; i < curr_size; ++i) {
    if (!check_flags(curr_inds[i])) {
      return false;  
    }
    flag_on(curr_inds[i]);
  }
  return true;
}

bool RomanToDecimal::check_flags(size_t flag) const {
  if (flag >= NUM_SYMBOLS) {
    throw flag;
  }
  if (flag >= 2) {
    for (size_t i = 0; i < flag - 2; ++i) {
      if (flags[i]) {return false;}
    }
  }
  return true;

}

int RomanToDecimal::vals_to_final() {
  if (!check_valid()) {
    std::stringstream eSS;
    eSS << "Error: Invalid Input - " << curr_symbs;
    throw eSS.str();
  };
  for (size_t i = 0; i < curr_size - 1; ++i) {
    if (curr_inds[i] < curr_inds[i + 1]) {
      final_val -= curr_vals[i];
    } else {
      final_val += curr_vals[i];
    }
  }
  final_val += curr_vals[curr_size - 1]; // Add Last Value
  return final_val;
  
}
