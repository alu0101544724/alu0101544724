
#include <cctype>
#include <numeric>

#include "acronym.h"

namespace acronym {
namespace {
struct acronim_accumulator {
  std::string str;
  bool should_take_next_char = true;
};
auto operator+(acronim_accumulator acc, const char &c) {
  if (acc.should_take_next_char && std::isalpha(c)) {
    acc.str += std::toupper(c);
    acc.should_take_next_char = false;
  } else if (c == ' ' || c == '-') {
    acc.should_take_next_char = true;
  }
  return acc;
}
}// namespace
auto acronym(std::string_view input) -> std::string {
  auto acc =
      std::accumulate(input.cbegin(), input.cend(), acronim_accumulator{});
  return acc.str;
}
}// namespace acronym
