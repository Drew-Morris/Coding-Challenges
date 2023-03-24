#ifndef ROMAN_TO_DECIMAL_H
#define ROMAN_TO_DECIMAL_H

#define NUM_SYMBOLS 7
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

#include "Converter.h"

const static int ROMAN_VALS[NUM_SYMBOLS] = {I,V,X,L,C,D,M};

class RomanToDecimal : public Converter {

  public:

    RomanToDecimal() : Converter(ROMAN_VALS,NUM_SYMBOLS) {
      flags = new bool[NUM_SYMBOLS];
    }
    ~RomanToDecimal();

  private:

    bool* flags; 

    void set_flag(int flag, bool val);
    void flag_on(int flag);
    void flag_off(int flag);
    void switch_flag(int flag);
    void reset_flags();

    /* Checks Flags */
    bool check_flags(size_t flag) const;

    /* Converts Symbols to Indices */
    virtual size_t symb_to_ind(char symbol) const final;

    /* Converts Values to Indices */
    virtual int val_to_ind(int value) const final;

    /* Checks for Valid Input */
    bool check_valid();
          
    /* Converts Stored Values to Final Value */
    virtual int vals_to_final() final;
      
};

#endif
