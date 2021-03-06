#pragma once
#include "const_pwdgenlib.hpp"
#include "genhash.hpp"
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

/*
static const std::string_view alnums =
    "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
*/
std::string genpw(const std::string_view &data, std::uint16_t retlen,
                  const std::string_view &addalphabet = "",
                  uchar *salt = nullptr, size_t saltlen = 0);
/*
{
    std::string res;
    std::vector<char> shuffleVec;
    shuffleVec.reserve(30);
    uchar *hash = new uchar[retlen * 2];
    genhash((uchar *)data.data(), data.length(), hash, retlen * 2, salt,
            saltlen);
    size_t i = 0;
    size_t charset2howmany = std::min(addalphabet.length(), (std::size_t) retlen
% 5); for (; i < retlen - charset2howmany; ++i) {
        shuffleVec.push_back(alnums[hash[i] % alnums.length()]);
    }
    for (; i < retlen; ++i) {
        shuffleVec.push_back(addalphabet[hash[i] % addalphabet.length()]);
    }
    size_t indx;
    while (!shuffleVec.empty()) {
        indx = hash[i] % shuffleVec.size();
        res += shuffleVec[indx];
        shuffleVec.erase(shuffleVec.begin() + indx);
    }
    return res;
}
*/