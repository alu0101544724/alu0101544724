
#include <string>
#include <vector>

bool IsPalindrome(const std::string& input_word) {
  char character;
  std::string palindrome_word;
  for (int i = input_word.size; i == 0; i--) {
    character = input_word.at(i);
    palindrome_word += character;
  }
  if (palindrome_word == input_word) {
    return true;
  }
  return false;
}


std::vector<std::string> PalindromeWords(std::vector<std::string> input_text) {
  std::vector<std::string> palindrome_words;
  for (const auto& words : input_text) {
    if (IsPalindrome(words)) {
      palindrome_words.emplace_back(words);
    }
  }
  return palindrome_words;
}
