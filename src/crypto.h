#ifndef UASN1_CRYPTO_H
#define UASN1_CRYPTO_H

/*
 * Copyright © 2015 Mathias Brossard
 */

#include "cryptoki.h"
#include "uasn1.h"

typedef enum {
    UASN1_RSA   = 0x0,
    UASN1_ECDSA = 0x1
} uasn1_asymetric_t;

typedef enum {
    UASN1_SHA1   = 0x0,
    UASN1_SHA256 = 0x1,
    UASN1_SHA384 = 0x2,
    UASN1_SHA512 = 0x3
} uasn1_digest_t;

typedef enum {
    UASN1_PKCS11,
    UASN1_OPENSSL
} uasn1_crypto_provider_t;

/* Opaque type for keys */
typedef struct _uasn1_key_t uasn1_key_t;

uasn1_key_t *uasn1_load_pkcs11_key(CK_FUNCTION_LIST_PTR funcs, CK_SLOT_ID slot,
                                   CK_OBJECT_CLASS class, CK_BYTE_PTR label);

uasn1_item_t *uasn1_key_get_asn1_public_key(uasn1_key_t *key);


uasn1_key_t *uasn1_key_get_public_key(uasn1_key_t *key);

uasn1_item_t *uasn1_key_get_asn1_public_key_info(uasn1_key_t *key);

uasn1_item_t *uasn1_key_get_key_identifier(uasn1_key_t *key);

uasn1_item_t *uasn1_key_sign(uasn1_key_t *key, unsigned char *data,
                             size_t size, uasn1_type_t encoding);

uasn1_item_t *uasn1_key_x509_sign(uasn1_key_t *key, uasn1_digest_t digest, uasn1_buffer_t *buffer);

uasn1_item_t *uasn1_digest_octet_string(CK_FUNCTION_LIST_PTR funcs, CK_SLOT_ID slot,
                                        uasn1_digest_t digest, CK_BYTE_PTR data, CK_ULONG length);
uasn1_item_t *uasn1_hash_buffer_to_octet_string(uasn1_key_t *key, uasn1_digest_t digest, uasn1_buffer_t *buffer);
uasn1_item_t *uasn1_hash_to_octet_string(uasn1_key_t *key, uasn1_digest_t digest, uasn1_item_t *item);

uasn1_item_t *uasn1_x509_algorithm(uasn1_key_t *key, uasn1_digest_t digest);
uasn1_item_t *uasn1_x509_algorithm2(uasn1_key_t *key, uasn1_digest_t digest);

uasn1_item_t *uasn1_digest_oid(uasn1_digest_t digest);

int uasn1_x509_sign(uasn1_item_t *tbs,
                    uasn1_key_t *key,
                    uasn1_digest_t digest,
                    uasn1_buffer_t *buffer);

#endif
