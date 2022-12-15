
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file rotate.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14/12/2022
  * @bug There are no known bugs
  */

#include <string>

#include <ib/rotate.h>

/**
 * @brief The function will rotate the vowels to the next vowel
 *        for example a will be e, an so on
 *
 * @param input_text
 * @return Rotated_text
 */

std::string Rotate(const std::string& input_text) {
  std::string rotated_text = input_text;
  std::string reference_vowels = "aeiou";
  for (auto& current_char : rotated_text) {
    for (int i = 0; i < reference_vowels.size(); ++i) {
      const auto& reference_vowel = reference_vowels.at(i);
      if (current_char == reference_vowel) {
        int new_index = (i + 1) % reference_vowels.size();
        current_char = reference_vowels.at(new_index);
        break;
      }
    }
  }
  return rotated_text;
}
