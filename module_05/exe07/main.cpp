#include "../exe06/Point3DFactory.h"

int main()
{

    Point3D source;
    Point3D target1 = Point3DFactory::create(source);
    Point3D target2 = Point3DFactory::create(std::move(source));

    return 0;
}

