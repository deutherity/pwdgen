#include "const_pwdgenlib.hpp"
#include <string_view>

std::string genpw(const std::string_view &data, const size_t retlen, const std::string_view addalphabet = "", uchar *salt = nullptr, size_t saltlen = 0);
