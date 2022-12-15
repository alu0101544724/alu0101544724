
/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @file vowels_and_consonants.cc
  * @author José Ángel Portillo García alu0101568232@ull.edu.es
  * @date 14/12/2022
  * @bug There are no known bugs
  */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "ib/vowels_and_consonants.h"

/**
 * @brief The function will check if a input char is vowel
 *
 * @param character
 * @return true || false
 */

bool IsVowel(char character) {
  character = tolower(character);
  if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
    return true;
  }
  return false;
}

/**
 * @brief The function will receive a vector of strings
 *        and check which string is the one with the most
 *        vowels
 *
 * @param input_file
 * @return max_vowel_word
 */

std::string VowelsCheck(const std::vector<std::string>& input_file) {
  std::string max_vowel_word;
  int max_word_counter = 0;
  for (const auto& words : input_file) {
    int counter = 0;
    for (const auto& character : words) {
      if (IsVowel(character)) {
        counter++;
        if (counter > max_word_counter) {
          max_word_counter = counter;
          max_vowel_word = words;
        }
      }
    }
  }
  return max_vowel_word;
}

/**
 * @brief The function will receive a vector of strings
 *        and check which string is the one with the most
 *        consonants
 *
 * @param input_file
 * @return max_consonant_word
 */

std::string ConsonantsCheck(const std::vector<std::string>& input_file) {
  std::string max_consonant_word;
  int max_word_counter = 0;
  for (const auto& words : input_file) {
    int counter = 0;
    for (const auto& character : words) {
      if (!IsVowel(character)) {
        counter++;
        if (counter > max_word_counter) {
          max_word_counter = counter;
          max_consonant_word = words;
        }
      }
    }
  }
  return max_consonant_word;
}

/**
 * @brief The function will differentiate a string with
 *        spaces, & adding the individual words to a
 *        vector of strings
 *
 * @param input_string
 * @param querry_char
 * @return characters
 */

std::vector<std::string> Split(const std::string& input_string, const char querry_char) {
  std::vector<std::string> characters;
  std::stringstream character;
  for (char symbol : input_string) {
    if (symbol != querry_char) {
      character << symbol;
      continue;
    }
    characters.emplace_back(character.str());
    character.str(std::string());
  }
  characters.emplace_back(character.str());
  return characters;
}

/**
 * @brief The function will read an input file
 *        line by line an adding it to a vector
 *        of strings
 *
 * @param input_files
 * @return text_file
 */

std::vector<std::string> FileReader(std::ifstream& input_files) {
  std::vector<std::string> text_file;
  std::string text_line;
  while (!input_files.eof()) {
    std::getline(input_files, text_line);
    text_file = Split(text_line, ' ');
  }
  return text_file;
}





