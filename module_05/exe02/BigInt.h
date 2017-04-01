#ifndef BIGINT_H
#define BIGINT_H

struct BigInt{
    int sig_;
    int len_;
    uint8_t* mag_;

    BigInt(int sig, int len)
        : sig_(sig), len_(len), mag_( len ? new uint8_t[len] : nullptr)
    {

    }

    BigInt(const BigInt& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_( bi.len_ ? new uint8_t[bi.len_] : nullptr)
    {
        std::copy(bi.mag_, bi.mag_ + len_, mag_);
    }

    BigInt& operator=(const BigInt& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        delete[] mag_;
        mag_ = len_ ? new uint8_t[len_] : nullptr;
        std::copy(bi.mag_, bi.mag_ + len_, mag_);
        return *this;
    }

    BigInt(BigInt&& bi)
        : sig_(bi.sig_), len_(bi.len_), mag_(nullptr)
    {
        mag_ = bi.mag_;
        bi.len_ = 0;
        bi.mag_ = nullptr;
    }

    BigInt& operator=(BigInt&& bi){
        sig_ = bi.sig_;
        len_ = bi.len_;
        delete[] mag_;
        mag_ = bi.mag_;
        bi.len_ = 0;
        bi.mag_ = nullptr;
        return *this;
    }

    ~BigInt(){
        delete[] mag_;
    }
};


#endif // BIGINT_H
