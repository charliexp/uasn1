ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = ${my_CFLAGS} \
	-I$(srcdir)/src

noinst_LIBRARIES = libuasn1.a libsasn1.a

libuasn1_a_SOURCES = src/uasn1.c \
	src/base64.c \
	src/crl.c \
	src/crypto/cryptoki.c \
	src/crypto/key.c \
	src/crypto/pkcs11/digest.c \
	src/crypto/pkcs11/key.c \
	src/crypto/sign.c \
	src/decode.c \
	src/encode.c \
	src/ocsp.c \
	src/oids.c \
	src/oidsdb.c \
	src/pkix.c \
	src/request.c \
	src/tsa.c \
	src/utils.c \
	src/x509.c

libsasn1_a_SOURCES = src/sasn1.c

noinst_PROGRAMS = \
	tests/sasn1_fuzzer \
	tests/test_asn1 \
	tests/test_base64 \
	tests/test_cryptoki \
	tests/test_sasn1

tests_test_asn1_SOURCES = tests/test_asn1.c
tests_test_asn1_LDADD = libuasn1.a

tests_test_sasn1_SOURCES = tests/test_sasn1.c
tests_test_sasn1_LDADD = libsasn1.a

tests_test_base64_SOURCES = src/base64.c
tests_test_base64_CFLAGS = -DBASE64_TEST

tests_test_cryptoki_SOURCES = \
	tests/test_cryptoki.c \
	tests/crl_test.c \
	tests/ocsp_test.c \
	tests/tsa_test.c \
	tests/x509_test.c

tests_test_cryptoki_LDADD = libuasn1.a

tests_sasn1_fuzzer_SOURCES = \
	tests/sasn1_fuzzer.c \
	src/sasn1.c

test: clean-local $(noinst_PROGRAMS)
	./tests/test_asn1
	./tests/test_base64
	./tests/test_cryptoki
	./tests/test_sasn1

clean-local:
	rm -f tests/*.der tests/*.pem tests/*.db
