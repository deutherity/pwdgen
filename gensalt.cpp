#include "gensalt.hpp"
#include <random>
#include <cstring>

typedef RANDOM_ENGINE::result_type rint_t;   // random int type of RANDOM_ENGINE
static constexpr size_t sz = sizeof(rint_t); // random int type size

void gensalt(Salt * out)
{
    std::random_device seed;
    RANDOM_ENGINE rng(seed());
    RANDOM_ENGINE::result_type num;
    size_t i = 0;
    for (; i +sz <= SALTLEN; i += sz)
    {
        num = rng();
        std::memcpy(out->data + i, (void*)&num, sz);
    }
    size_t left = SALTLEN - i;
    if (left)
    {
        num = rng();
        std::memcpy(out->data + i, (void*)&num, left);
    }
}
