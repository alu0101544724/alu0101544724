
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file main.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14/12/2022
  * @brief The program will read a text file, and will print
  *        the word with the most vowels, and the one with the
  *        most consonants
  * @bug There are no known bugs
  */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "ib/usage.h"
#include "ib/vowels_and_consonants.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kInputFile = argv[1];
  std::ifstream input_file(kInputFile);
  if (!input_file.is_open()) {
    std::cerr << "Error: " << kInputFile << " no se pudo abrir! \n\
    Revise todo e intentelo de nuevo!\n\
    Pruebe: " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::vector<std::string> file_text = FileReader(input_file);
  std::cout << "The word with the most vowels is " << VowelsCheck(file_text) << std::endl;
  std::cout << "The word with the most consonants is " << ConsonantsCheck(file_text) << std::endl;
  return 0;
}
