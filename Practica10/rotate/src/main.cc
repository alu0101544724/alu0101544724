
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file main.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14/12/2022
  * @brief The program will read a text file and will rotate
  *        the vowels to the next vowel, like a will be e
  *        and so on. And the output will go to another text file
  *        introduced
  * @bug There are no known bugs
  */

#include <fstream>
#include <sstream>

#include "ib/rotate.h"
#include "ib/usage_rotate.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file(argv[1]);
  if (!input_file.is_open()) {
    throw std::runtime_error("problem with file");
  }
  std::ofstream output_file(argv[2]);
  if (!output_file.is_open()) {
    throw std::runtime_error("problem with file");
  }
  std::stringstream input_file_text;
  input_file_text << input_file.rdbuf();
  output_file << Rotate(input_file_text.str());
  return 0;
}
