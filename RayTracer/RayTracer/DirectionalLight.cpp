#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const STVector3& dir,const STColor3f& c){
    color = new STColor3f(c);
    direction = new STVector3(dir);
}

STColor3f DirectionalLight::sumTerm(RayIntersection inter, Material *material, Ray *viewingRay){
    STVector3 incomingLight = -*direction;
    incomingLight.Normalize();
    STVector3 normal = inter.ptNormal;
    STVector3 view = -viewingRay->direction;
    
    STColor3f diffuse = material->diff * (*color) * fmax(0.0, STVector3::Dot(incomingLight, normal));
    STColor3f specular = material->spec * (*color) * pow(fmax(0, STVector3::Dot(view, Utils::reflectVector(normal, incomingLight))), material->shine);
    
    return diffuse + specular;
}


