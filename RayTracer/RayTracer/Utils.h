#ifndef __RayTracer__Utils__
#define __RayTracer__Utils__

#include <iostream>
#include "st.h"
#include "stgl.h"

class Utils
{
public:
    static STVector3 reflectVector(STVector3 normal, STVector3 lightSource);
};

#endif /* defined(__RayTracer__Utils__) */
