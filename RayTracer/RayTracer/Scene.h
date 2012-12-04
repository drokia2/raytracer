#ifndef SCENE_H
#define SCENE_H

#include "st.h"
#include <vector>
//#include "tracer.h"
// I shouldn't have to reinclude this
#include "ImagePlane.h"
#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Light.h"
#include "AmbientLight.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "RayIntersection.h"
#include "Material.h"
#include "SceneObject.h"
#include "OcclusionRay.h"

class Scene
{
public:
	Scene(std::string sceneFilename);

	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    void Render();

private:

	/** Parsing helpers **/
	void Parse(std::string sceneFilename);
	void BeganParsing();
	void FinishedParsing();
	void ParsedCamera(const STPoint3& eye, const STVector3& up, const STPoint3& lookAt, float fovy, float aspect);
	void ParsedOutput(int imgWidth, int imgHeight, const std::string& outputFilename);
	void ParsedBounceDepth(int depth);
	void ParsedShadowBias(float bias);
	void ParsedPushMatrix();
	void ParsedPopMatrix();
	void ParsedRotate(float rx, float ry, float rz);
	void ParsedScale(float sx, float sy, float sz);
	void ParsedTranslate(float tx, float ty, float tz);
	void ParsedSphere(const STPoint3& center, float radius);
	void ParsedTriangle(const STPoint3& v1, const STPoint3& v2, const STPoint3& v3);
	void ParsedAmbientLight(const STColor3f& col);
	void ParsedPointLight(const STPoint3& loc, const STColor3f& col);
	void ParsedDirectionalLight(const STVector3& dir, const STColor3f& col);
	void ParsedMaterial(const STColor3f& amb, const STColor3f& diff, const STColor3f& spec, const STColor3f& mirr, float shine);

	/** CS 148 TODO: Add instance vars to store camera, lights, objects, etc. **/
    
    STColor3f CalcColor(RayIntersection surface_pt, Ray *viewingRay, SceneObject *min_object);
    bool Occluded(SceneObject *o, RayIntersection surface_pt, Light *l);
    bool Scene::Intersect(Ray *ray, SceneObject **intersectedObject, RayIntersection **intersectionPoint);
    Camera *camera;
    ImagePlane *imagePlane;
    Material *lastDeclaredMaterial;
    int bounceDepth;
    std::vector<Shape *> shapes;
    std::vector<SceneObject *> objects;
    std::vector<Light *> lights;
    float epsilon;
    
};


#endif
