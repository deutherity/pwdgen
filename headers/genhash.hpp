#ifndef GENHASHHEAD
#define GENHASHHEAD

#include "const_pwdgenlib.hpp"
void genhash(uchar *data, size_t datalen, uchar *output, size_t outputlen,
             uchar *salt = nullptr, size_t saltlen = 0);

#endif
