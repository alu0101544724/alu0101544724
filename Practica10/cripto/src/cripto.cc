/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2022-2023
 *
 * @author José Ángel Portillo García alu0101568232@ull.edu.es
 * @date 14 Dec 2022
 * @brief This file define the three functions
 *
 */


#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "ib/cripto.h"

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa los nombres de los ficheros de texto, el método, la
 *  contraseña y la operación para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char* argv[]) {
  if (argc != 6 && argc != 2) {
    std::cerr << "Modo de uso: " << argv[0]
              << " fichero_entrada fichero_salida método password operación"
              << std::endl;
    std::cerr << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string parameter{argv[1]};
  if (argc == 2 && parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc < 6 || argc > 6) && (parameter != "--help")) {
    std::cerr << argv[0] << " -- Cifrado de ficheros" << std::endl;
    std::cerr << "Modo de uso: " << argv[0]
              << " fichero_entrada fichero_salida método password operación"
              << std::endl;
    std::cerr << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief La función encripta / desencripta en el metodo xor
 *        introduciendo un fichero de entrada para codificar / decodificar
 *        y uno de salidad para el texto cifrado / descifrado, partiendo
 *        de una palabra
 *
 * @param input_text
 * @param kPassword
 * @param do_encrypt
 * @return line_text
 */

std::string XOREncrypt(const std::string& input_text, const std::string& kPassword, bool do_encrypt) {
  std::string line_text = input_text;
  for (size_t i = 0; i < line_text.length(); ++i) {
    if (line_text[i] == ' ' || line_text[i] == '\n' || line_text[i] == '\t')
      continue;
    line_text[i] = line_text[i] ^ (i % kPassword.length());
  }
  return line_text;
}

/**
 * @brief Encripta / Desencritpa por el método de César.
 *        En case de que el uso no sea el correcto, muestra
 *        el mensaje y finaliza la ejecución del programa.
 * 
 * @param input_file file to be encrypted
 * @param output_file file encrypted
 * @param kPasswordNum number to encrypt the letter 
 * @param do_encrypt Option to choose (+ = Encrypt / - = Desencrytp)
 */
std::string CesarEncrypt(const std::string& input_text, const int kPasswordNum, const bool do_encrypt) {
  std::string line_text = input_text;
  int password_num = do_encrypt ? kPasswordNum : -kPasswordNum;
  for (char& current_char : line_text) {
    if (current_char == ' ' || current_char == '\n' || current_char == '\t')
      continue;
    current_char = current_char + password_num;
  }
  return line_text;
}