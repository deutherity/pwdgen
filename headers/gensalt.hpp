#pragma once

#include "const_pwdgenlib.hpp"
struct Salt {
    uchar *data;
    static const std::size_t saltlen = SALTLEN;
};

void gensalt(Salt *out);
