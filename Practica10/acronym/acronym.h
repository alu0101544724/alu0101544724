
#if !defined(ACRONYM_H)
#define ACRONYM_H

#include <string>
#include <string_view>

namespace acronym {
auto acronym(std::string_view input) -> std::string;
} // namespace acronym
#endif // ACRONYM_H
