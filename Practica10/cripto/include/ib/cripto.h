
#include <iostream>

const std::string kHelpText =
  R"(./cripto -- Cifrado de ficheros
  Modo de uso: ./cripto fichero_entrada fichero_salida método
  password operación
  fichero_entrada: Fichero a codificar
  fichero_salida:  Fichero codificado
  método:          Indica el método de encriptado
                     1: Cifrado xor
                     2: Cifrado de César
  password:        Palabra secreta en el caso de método 1, Valor de K en el
  método 2
  operación:       Operación a realizar en el fichero
                     +: encriptar el fichero
                     -: desencriptar el fichero )";

void Usage(int argc, char* argv[]);
std::string XOREncrypt(const std::string &input_text, const std::string& kPassword, const bool do_encrypt);
std::string CesarEncrypt(const std::string &input_text, const int kPasswordNum, const bool do_encrypt);