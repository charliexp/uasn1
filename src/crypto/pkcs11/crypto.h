#ifndef UASN1_CRYPTO_KEY_PKCS11_H
#define UASN1_CRYPTO_KEY_PKCS11_H

/*
 * Copyright (C) 2016 Mathias Brossard <mathias@brossard.org>
 */

#include "crypto.h"

uasn1_asymetric_t uasn1_key_pkcs11_type(uasn1_key_t *key);
uasn1_key_t *uasn1_key_pkcs11_load(uasn1_crypto_t *crypto, uasn1_key_type_t type, char *label);
uasn1_item_t *uasn1_key_pkcs11_get_asn1_public_key_info(uasn1_key_t *key);
uasn1_item_t *uasn1_key_pkcs11_get_asn1_public_key(uasn1_key_t *key);
uasn1_item_t *uasn1_key_pkcs11_get_key_identifier(uasn1_key_t *key);
uasn1_item_t *uasn1_key_pkcs11_x509_sign(uasn1_key_t *key, uasn1_digest_t digest, uasn1_buffer_t *buffer);

uasn1_item_t *uasn1_digest_pkcs11_octet_string(uasn1_crypto_t *crypto, uasn1_digest_t digest, void *data, size_t length);

#endif
