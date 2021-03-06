// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

#pragma once

#include <cstdint>
#include "context.h"
#include "biguint.h"
#include "plaintext.h"
#include "smallmodulus.h"
#include "memorymanager.h"

namespace seal
{
    /**
    Encodes integers into plaintext polynomials that Encryptor can encrypt. An instance of
    the IntegerEncoder class converts an integer into a plaintext polynomial by placing its
    binary digits as the coefficients of the polynomial. Decoding the integer amounts to
    evaluating the plaintext polynomial at x=2.

    Addition and multiplication on the integer side translate into addition and multiplication
    on the encoded plaintext polynomial side, provided that the length of the polynomial
    never grows to be of the size of the polynomial modulus (poly_modulus), and that the
    coefficients of the plaintext polynomials appearing throughout the computations never
    experience coefficients larger than the plaintext modulus (plain_modulus).

    @par Negative Integers
    Negative integers are represented by using -1 instead of 1 in the binary representation,
    and the negative coefficients are stored in the plaintext polynomials as unsigned integers
    that represent them modulo the plaintext modulus. Thus, for example, a coefficient of -1
    would be stored as a polynomial coefficient plain_modulus-1.
    */
    class IntegerEncoder
    {
    public:
        /**
        Creates a IntegerEncoder object. The constructor takes as input a pointer to
        a SEALContext object which contains the plaintext modulus. 

        @param[in] context The SEALContext
        @throws std::invalid_argument if the context is not set
        @throws std::invalid_argument if the plain_modulus set in context is not 
        at least 2
        */
        IntegerEncoder(std::shared_ptr<SEALContext> context);

        /**
        Creates a copy of a IntegerEncoder.

        @param[in] copy The IntegerEncoder to copy from
        */
        IntegerEncoder(const IntegerEncoder &copy) = default;

        /**
        Creates a new IntegerEncoder by moving an old one.

        @param[in] source The IntegerEncoder to move from
        */
        IntegerEncoder(IntegerEncoder &&source) = default;

        /**
        Destroys the IntegerEncoder.
        */
        ~IntegerEncoder() = default;

        /**
        Encodes an unsigned integer (represented by std::uint64_t) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        */
        Plaintext encode(std::uint64_t value);

        /**
        Encodes an unsigned integer (represented by std::uint64_t) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        @param[out] destination The plaintext to overwrite with the encoding
        */
        void encode(std::uint64_t value, Plaintext &destination);

        /**
        Decodes a plaintext polynomial and returns the result as std::uint32_t.
        Mathematically this amounts to evaluating the input polynomial at x=2.

        @param[in] plain The plaintext to be decoded
        @throws std::invalid_argument if the output does not fit in std::uint32_t 
        */
        std::uint32_t decode_uint32(const Plaintext &plain);

        /**
        Decodes a plaintext polynomial and returns the result as std::uint64_t.
        Mathematically this amounts to evaluating the input polynomial at x=2.

        @param[in] plain The plaintext to be decoded
        @throws std::invalid_argument if the output does not fit in std::uint64_t 
        */
        std::uint64_t decode_uint64(const Plaintext &plain);

        /**
        Encodes a signed integer (represented by std::uint64_t) into a plaintext polynomial.

        @par Negative Integers
        Negative integers are represented by using -1 instead of 1 in the binary representation,
        and the negative coefficients are stored in the plaintext polynomials as unsigned integers
        that represent them modulo the plaintext modulus. Thus, for example, a coefficient of -1
        would be stored as a polynomial coefficient plain_modulus-1.

        @param[in] value The signed integer to encode
        */
        Plaintext encode(std::int64_t value);

        /**
        Encodes a signed integer (represented by std::int64_t) into a plaintext polynomial.

        @par Negative Integers
        Negative integers are represented by using -1 instead of 1 in the binary representation,
        and the negative coefficients are stored in the plaintext polynomials as unsigned integers
        that represent them modulo the plaintext modulus. Thus, for example, a coefficient of -1
        would be stored as a polynomial coefficient plain_modulus-1.

        @param[in] value The signed integer to encode
        @param[out] destination The plaintext to overwrite with the encoding
        */
        void encode(std::int64_t value, Plaintext &destination);

        /**
        Encodes an unsigned integer (represented by BigUInt) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        */
        Plaintext encode(const BigUInt &value);

        /**
        Encodes an unsigned integer (represented by BigUInt) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        @param[out] destination The plaintext to overwrite with the encoding
        */
        void encode(const BigUInt &value, Plaintext &destination);

        /**
        Decodes a plaintext polynomial and returns the result as std::int32_t.
        Mathematically this amounts to evaluating the input polynomial at x=2.

        @param[in] plain The plaintext to be decoded
        @throws std::invalid_argument if plain does not represent a valid plaintext polynomial
        @throws std::invalid_argument if the output does not fit in std::int32_t 
        */
        std::int32_t decode_int32(const Plaintext &plain);

        /**
        Decodes a plaintext polynomial and returns the result as std::int64_t.
        Mathematically this amounts to evaluating the input polynomial at x=2.

        @param[in] plain The plaintext to be decoded
        @throws std::invalid_argument if plain does not represent a valid plaintext polynomial
        @throws std::invalid_argument if the output does not fit in std::int64_t 
        */
        std::int64_t decode_int64(const Plaintext &plain);

        /**
        Decodes a plaintext polynomial and returns the result as BigUInt.
        Mathematically this amounts to evaluating the input polynomial at x=2.

        @param[in] plain The plaintext to be decoded
        @throws std::invalid_argument if plain does not represent a valid plaintext polynomial
        @throws std::invalid_argument if the output is negative
        */
        BigUInt decode_biguint(const Plaintext &plain);

        /**
        Encodes a signed integer (represented by std::int32_t) into a plaintext polynomial.

        @par Negative Integers
        Negative integers are represented by using -1 instead of 1 in the binary representation,
        and the negative coefficients are stored in the plaintext polynomials as unsigned integers
        that represent them modulo the plaintext modulus. Thus, for example, a coefficient of -1
        would be stored as a polynomial coefficient plain_modulus-1.

        @param[in] value The signed integer to encode
        */
        Plaintext encode(std::int32_t value) 
        {
            return encode(static_cast<std::int64_t>(value));
        }

        /**
        Encodes an unsigned integer (represented by std::uint32_t) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        */
        Plaintext encode(std::uint32_t value) 
        {
            return encode(static_cast<std::uint64_t>(value));
        }

        /**
        Encodes a signed integer (represented by std::int32_t) into a plaintext polynomial.

        @par Negative Integers
        Negative integers are represented by using -1 instead of 1 in the binary representation,
        and the negative coefficients are stored in the plaintext polynomials as unsigned integers
        that represent them modulo the plaintext modulus. Thus, for example, a coefficient of -1
        would be stored as a polynomial coefficient plain_modulus-1.

        @param[in] value The signed integer to encode
        @param[out] destination The plaintext to overwrite with the encoding
        */
        void encode(std::int32_t value, Plaintext &destination) 
        {
            encode(static_cast<std::int64_t>(value), destination);
        }

        /**
        Encodes an unsigned integer (represented by std::uint32_t) into a plaintext polynomial.

        @param[in] value The unsigned integer to encode
        @param[out] destination The plaintext to overwrite with the encoding
        */
        void encode(std::uint32_t value, Plaintext &destination) 
        {
            encode(static_cast<std::uint64_t>(value), destination);
        }

        /**
        Returns a reference to the plaintext modulus.
        */
        const SmallModulus &plain_modulus() const 
        {
            auto &context_data = *context_->context_data();
            return context_data.parms().plain_modulus();
        }

    private:
        IntegerEncoder &operator =(const IntegerEncoder &assign) = delete;

        IntegerEncoder &operator =(IntegerEncoder &&assign) = delete;

        std::shared_ptr<SEALContext> context_{ nullptr };

        std::uint64_t coeff_neg_threshold_;

        std::uint64_t neg_one_;
    };
}
