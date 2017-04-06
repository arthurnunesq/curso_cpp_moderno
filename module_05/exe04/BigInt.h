#ifndef BIGINT_H
#define BIGINT_H

#include <cstdint>
#include <algorithm>
#include <vector>
#include <iostream>

struct BigInt{
    int sig_;
    int len_;
    std::vector<uint8_t> mag_;


    BigInt()
        : sig_(1), len_(0), mag_(0){
        // std::cout << "BigInt: Construtor" << std::endl;
    }

    BigInt(int sig, int len)
        : sig_(sig), len_(len), mag_( len)
    {
        // std::cout << "BigInt: Construtor" << std::endl;
    }

    BigInt(const BigInt& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_(bi.mag_)
    {
        // std::cout << "BigInt: Construtor de copia" << std::endl;
    }

    BigInt& operator=(const BigInt& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        mag_ = bi.mag_;
        // std::cout << "BigInt: Atribuicao por copia" << std::endl;
        return *this;
    }

    BigInt(BigInt&& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_(std::move(bi.mag_))
    {
        bi.len_ = 0;
        // std::cout << "BigInt: Construtor de transferencia" << std::endl;
    }

    BigInt& operator=(BigInt&& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        mag_ = std::move(bi.mag_);
        bi.len_ = 0;
        // std::cout << "BigInt: Atribuicao por transferencia" << std::endl;
        return *this;
    }

    ~BigInt(){
    }
};


#endif // BIGINT_H
