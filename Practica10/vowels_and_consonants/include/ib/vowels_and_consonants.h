
#include <string>
#include <vector>
#include <fstream>

bool IsVowel(char character);
std::string VowelsCheck(const std::vector<std::string>& input_file);
std::string ConsonantsCheck(const std::vector<std::string>& input_file);
std::vector<std::string> FileReader(std::ifstream& input_files);
std::vector<std::string> Split(const std::string& input_string, const char querry_char);
