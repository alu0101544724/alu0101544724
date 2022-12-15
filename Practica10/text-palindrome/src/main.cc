
#include <string>

int main(int argc, char* argv[]) {
  
}

#include <string>
#include <fstream>

#include "usage.h"

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
}