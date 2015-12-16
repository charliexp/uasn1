#ifndef UASN1_KEY_H
#define UASN1_KEY_H

/*
 * Copyright © 2015 Mathias Brossard
 */

#include "uasn1.h"
#include "crypto.h"
#include "cryptoki.h"

#ifdef HAVE_OPENSSL
#include <openssl/evp.h>
#endif

typedef struct {
    CK_FUNCTION_LIST_PTR functions;
    CK_SLOT_ID slot;
	CK_OBJECT_HANDLE object;
    CK_SESSION_HANDLE session;
    CK_ULONG size;
    CK_KEY_TYPE type;
    CK_OBJECT_CLASS class;
} pkcs11_key_t;

typedef struct _uasn1_key_t {
	uasn1_crypto_provider_t provider;
	union {
		pkcs11_key_t pkcs11;
#ifdef HAVE_OPENSSL
		EVP_PKEY *openssl;
#endif
	};
} uasn1_key_t;

#endif
