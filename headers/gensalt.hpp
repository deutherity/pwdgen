#ifndef SALTHEAD
#define SALTHEAD

#include "const_pwdgenlib.hpp"
struct Salt {
    uchar data[SALTLEN];
};

void gensalt(Salt *out);
#endif
