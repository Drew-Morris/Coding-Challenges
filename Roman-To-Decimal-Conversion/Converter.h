#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

/* Converts an Array to a String */
template <typename T>
std::string arr_to_str(T* array, size_t size, std::string insert = ",") {
  std::stringstream SS;
  std::string ins = "";
  SS << '[';
  for (size_t i = 0; i < size; ++i) {
    SS << ins << array[i];
    ins = insert;
  }
  SS << ']';
  return SS.str();
}

class Converter {

  public:

    Converter();
    Converter(const int*, std::size_t);
    ~Converter();

    /* Converts Input String to Output Value */
    int convert(std::string);

    /* Converts Symbols Attribute to String */
    std::string symbs_to_str() const {return attrs_to_str<char>(curr_symbs);}
    /* Converts Indices Attribute to String */
    std::string inds_to_str() const {return attrs_to_str<size_t>(curr_inds);}
    /* Converts Values Attribute to String */
    std::string vals_to_str() const {return attrs_to_str<int>(curr_vals);}

    /* Converts Private Data to String */
    std::string to_string() const;

  protected:

    int* conv_vals;
    size_t num_vals;
    char* curr_symbs;
    size_t* curr_inds;
    int* curr_vals;
    size_t curr_size;
    int final_val;

    /* Converts a Symbol to an Index */
    virtual size_t symb_to_ind(char symbol) const = 0;

    /* Converts Attribute Arrays to Strings */
    template <typename T>
    std::string attrs_to_str(T* attrs) const {
      return arr_to_str<T>(attrs,curr_size);
    }

    /* Stores an Input String */
    void store_string(std::string symbols);

    /* Converts Symbols to Indices */
    size_t* symbs_to_inds(std::string symbols);

    /* Converts a Value to an Index */
    virtual int val_to_ind(int value) const = 0;

    /* Converts a Symbol to a Value */
    int symb_to_val(char symbol);

    /* Converts Symbols to Values */
    int* symbs_to_vals(std::string symbols);

    /* Converts Stored Values to the Final Output */
    virtual int vals_to_final() = 0;

  friend std::ostream& operator<< (std::ostream& oS, const Converter& oConv) {
    oS << oConv.to_string();
    return oS;
  }

};

#endif
