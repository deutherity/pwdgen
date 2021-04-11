#include "genhash.hpp"
#include "crash.hpp"
#include "gensalt.hpp"
#include "openssl/evp.h"
#include "openssl/kdf.h"
#define MYSALT "aethernet's personal salt"

void genhash(uchar *data, size_t datalen, uchar *output, size_t outputlen,
             uchar *salt, size_t saltlen) {
    EVP_PKEY_CTX *pctx;
    if (saltlen == 0) {
        salt = (uchar *)MYSALT;
        saltlen = sizeof(MYSALT);
    }
    pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_SCRYPT, NULL);

    if (EVP_PKEY_derive_init(pctx) <= 0) {
        crash("EVP_PKEY_derive_init");
    }
    if (EVP_PKEY_CTX_set1_pbe_pass(pctx, data, datalen) <= 0) {
        crash("EVP_PKEY_CTX_set1_pbe_pass");
    }
    if (EVP_PKEY_CTX_set1_scrypt_salt(pctx, salt, saltlen) <= 0) {
        crash("EVP_PKEY_CTX_set1_scrypt_salt");
    }
    if (EVP_PKEY_CTX_set_scrypt_N(pctx, 1024) <= 0) {
        crash("EVP_PKEY_CTX_set_scrypt_N");
    }
    if (EVP_PKEY_CTX_set_scrypt_r(pctx, 8) <= 0) {
        crash("EVP_PKEY_CTX_set_scrypt_r");
    }
    if (EVP_PKEY_CTX_set_scrypt_p(pctx, 1) <= 0) {
        crash("EVP_PKEY_CTX_set_scrypt_p");
    }
    if (EVP_PKEY_derive(pctx, output, &outputlen) <= 0) {
        crash("EVP_PKEY_derive");
    }
}