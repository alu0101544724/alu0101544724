/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14 Dec 2022
  * @brief Es el archivo main del programa. El programa encripta y/o desencripta
  *        ficheros de texto mediante dos métodos (XOR / Cesar).
  * @bug There are no known bugs
  */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "ib/cripto.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kInputFilename{argv[1]};
  const std::string kOutputFilename{argv[2]};
  const std::string kMethod{argv[3]};
  const std::string kPassword{argv[4]};
  const std::string kOperation{argv[5]};
  bool do_encrypt = kOperation == "+";
  std::ifstream input_file(kInputFilename);
  if (!input_file.is_open()) {
    std::cerr << "Error: " << kInputFilename << R"( no se pudo abrir!
    Revise todo e intentelo de nuevo!)";
    std::cerr << "Pruebe: " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::ofstream output_file(kOutputFilename);
  if (!output_file.is_open()) {
    std::cerr << "Error: " << kOutputFilename << " no se pudo abrir! \n\
    Revise todo e intentelo de nuevo!\n\
    Pruebe: " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
  std::stringstream input_file_text;
  input_file_text << input_file.rdbuf();
  std::stringstream output_file_text;
  const int kMethodNum = stoi(kMethod);
  if (kMethodNum == 1) {
    output_file_text << XOREncrypt(input_file_text.str(), kPassword, do_encrypt);
  } else if (kMethodNum == 2) {
    int kPasswordNum = stoi(kPassword);
    output_file_text << CesarEncrypt(input_file_text.str(), kPasswordNum, do_encrypt);
  } else {
    std::cerr << "Error: Metodo elegido no válido" << std::endl;
    exit(EXIT_FAILURE);
  }
  output_file << output_file_text.rdbuf();
  input_file.close();
  output_file.close();
  return 0;
}