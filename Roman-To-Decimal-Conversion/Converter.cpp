#include "Converter.h"

Converter::Converter() {
  conv_vals = nullptr;
  curr_inds = nullptr;
  curr_vals = nullptr;
}

Converter::Converter(const int* conv_vals, std::size_t num_vals) {
  this->num_vals = num_vals;
  this->conv_vals = new int[num_vals];
  for (size_t i = 0; i < num_vals; ++i) {
    this->conv_vals[i] = conv_vals[i];
  }
  curr_symbs = nullptr;
  curr_inds = nullptr;
  curr_vals = nullptr;
}

Converter::~Converter() {
  delete[] curr_symbs;
  delete[] curr_inds;
  delete[] conv_vals;
}

int Converter::convert(std::string str) {
  try {
    final_val = 0;
    symbs_to_vals(str);
    return vals_to_final();
  } catch (int value) {
    std::stringstream eSS;
    eSS << "ERROR: Invalid Value - " << value;
    throw eSS.str();
  } catch (char symbol) {
    std::stringstream eSS;
    eSS << "ERROR: Invalid Symbol - " << symbol;
    throw eSS.str();
  } catch (size_t flag) {
    std::stringstream eSS;
    eSS << "ERROR: Invalid Flag - " << flag;
    throw eSS.str();
  }
}

std::string Converter::to_string() const {
  std::stringstream SS;
  SS << "Symbols: " << symbs_to_str() << std::endl;
  SS << "Indices: " << inds_to_str() << std::endl;
  SS << "Values: " << vals_to_str() << std::endl;
  return SS.str();
}

void Converter::store_string(std::string symbols) {
  delete[] curr_symbs;
  curr_size = symbols.length();
  curr_symbs = new char[curr_size + 1];
  std::strcpy(curr_symbs,symbols.c_str());
}

size_t* Converter::symbs_to_inds(std::string symbols) {
  store_string(symbols);
  delete[] curr_inds;
  curr_inds = new size_t[curr_size];
  for (size_t i = 0; i < curr_size; ++i) {
    curr_inds[i] = symb_to_ind(symbols.at(i));
  }
  return curr_inds;
}

int Converter::symb_to_val(char symbol) {
  return conv_vals[symb_to_ind(symbol)];        
}

int* Converter::symbs_to_vals(std::string symbols) {
  symbs_to_inds(symbols);
  delete[] curr_vals;
  curr_vals = new int[curr_size];
  for (size_t i = 0; i < curr_size; ++i) {
    curr_vals[i] = conv_vals[curr_inds[i]];
  }
  return curr_vals;
}
