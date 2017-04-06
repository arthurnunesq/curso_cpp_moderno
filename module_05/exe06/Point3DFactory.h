#ifndef POINT3DFACTORY_H
#define POINT3DFACTORY_H

#include "../exe05/Point3D.h"

struct Point3DFactory {
    template<class T = Point3D>
    static T create(T&& p){
        return T(std::forward<T>(p));
    }
};


#endif // POINT3DFACTORY_H
