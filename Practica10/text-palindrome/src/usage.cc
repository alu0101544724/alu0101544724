/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file usage.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 15/12/2022
  * @bug There are no known bugs
  */

#include <string>
#include <iostream>

const std::string kTitle = "text-palindrome";
const std::string kHelpText =
  R("How to use: to use this program you will have to execute it like ./a.out file.txt output_file.txt
    Parameters:
    - file.txt: is the file to read
    -output_file.txt: is the file to print");

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
              << "./a.out file.txt out_file.txt"
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
  if ((argc > 3) && (argv[1] != kHelp)) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "► How to use: " << argv[0]
              << "./a.out file.txt out_file.txt"
              << std::endl;
    std::cerr << "♦ Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}