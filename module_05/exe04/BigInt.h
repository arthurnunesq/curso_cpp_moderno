#ifndef BIGINT_H
#define BIGINT_H

#include <cstdint>
#include <algorithm>
#include <vector>

struct BigInt{
    int sig_;
    int len_;
    std::vector<uint8_t> mag_;


    BigInt()
        : sig_(1), len_(0), mag_(0){

    }

    BigInt(int sig, int len)
        : sig_(sig), len_(len), mag_( len)
    {

    }

    BigInt(const BigInt& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_(bi.mag_)
    {
    }

    BigInt& operator=(const BigInt& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        mag_ = bi.mag_;
        return *this;
    }

    BigInt(BigInt&& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_(std::move(bi.mag_))
    {
        bi.len_ = 0;
    }

    BigInt& operator=(BigInt&& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        mag_ = std::move(bi.mag_);
        bi.len_ = 0;
        return *this;
    }

    ~BigInt(){
    }
};


#endif // BIGINT_H
