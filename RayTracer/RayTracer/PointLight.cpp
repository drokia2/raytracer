#include "PointLight.h"

PointLight::PointLight(const STPoint3& loc,const STColor3f& c){
    color = new STColor3f(c);
    location = new STVector3(loc);
}

STColor3f PointLight::sumTerm(Intersection inter, Material *material, Ray *viewingRay){
    STVector3 incomingLight = *location - inter.pt;
    incomingLight.Normalize();
    STVector3 normal = inter.ptNormal;
    normal.Normalize();
    STVector3 view = -viewingRay->direction;
    
    STColor3f diffuse = material->diff * (*color) * fmax(0.0, STVector3::Dot(incomingLight, normal));
    STColor3f specular = material->spec * (*color) * pow(fmax(0, STVector3::Dot(view, Utils::reflectVector(normal, incomingLight))), material->shine);
    
    return diffuse + specular;
}
