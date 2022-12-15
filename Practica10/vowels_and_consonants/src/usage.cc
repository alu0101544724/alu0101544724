
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file usage.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14/12/2022
  * @bug There are no known bugs
  */

#include <string>
#include <iostream>

const std::string kTitle = "Vowels and consonants";
const std::string kHelpText =
  "• How to use: to use this program you will have to execute it like ./a.out file.txt \n\
 » Parameters:\n\
    - file.txt: is the file to read\n";

/**
 * @brief: The function will configure the use of argc & argv
 * @param[in]: argc | argv
 * @return: none
 */
void Usage(int argc, char* argv[]) {
  const std::string kHelp{"--help"};
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "► How to use: " << argv[0]
              << "[introduce como se escribe en consola]"
              << std::endl;
    std::cerr << "♦ Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) {
    std::cout << kTitle << std::endl;
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc > 2) && (argv[1] != kHelp)) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "► How to use: " << argv[0]
              << "[introduce como se escribe en consola]"
              << std::endl;
    std::cerr << "♦ Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}
