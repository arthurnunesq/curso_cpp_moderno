#ifndef POINT3D_H
#define POINT3D_H

#include <cstdint>
#include <algorithm>
#include <vector>
#include "../exe04/BigInt.h"

class Point3D {
    std::vector<BigInt> coord_;

public:
    Point3D() : coord_({BigInt(),BigInt(),BigInt()})
    {
        std::cout << "Point3D: Construtor" << std::endl;
    }

    Point3D(const BigInt& x, const BigInt& y, const BigInt& z) : coord_(3)
    {
        coord_.push_back(x);
        coord_.push_back(y);
        coord_.push_back(z);
    }

    Point3D(const Point3D& bi)
        : coord_(bi.coord_)
    {
        std::cout << "Point3D: Construtor de copia" << std::endl;
    }

    Point3D& operator=(const Point3D& bi){
        coord_ = bi.coord_;
        std::cout << "Point3D: Atribuicao por copia" << std::endl;
        return *this;
    }

    Point3D(Point3D&& bi)
        :  coord_(std::move(bi.coord_))
    {
        bi.coord_ =  {BigInt(),BigInt(),BigInt()};
        std::cout << "Point3D: Construtor de transferencia" << std::endl;
    }

    Point3D& operator=(Point3D&& bi){
        coord_ = std::move(bi.coord_);
        bi.coord_ =  {BigInt(),BigInt(),BigInt()};
        std::cout << "Point3D: Atribuicao por transferencia" << std::endl;
        return *this;
    }

    ~Point3D(){
    }

    const BigInt& x(){
        return coord_[0];
    }

    const BigInt& y(){
        return coord_[1];
    }

    const BigInt& z(){
        return coord_[2];
    }
};


#endif // POINT3D_H
