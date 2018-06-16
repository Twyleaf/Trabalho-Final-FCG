#include "CollisionSphere.h"

void CollisionSphere::setCenter(glm::vec4 centerInput){
    center=centerInput;
}

void CollisionSphere::setRadius(float radiusInput){
    radius=radiusInput;
}

glm::vec4 CollisionSphere::getCenter(){
    return center;
}

float CollisionSphere::getRadius(){
    return radius;
}

CollisionSphere::CollisionSphere(glm::vec4 centerInput,float radiusInput)
{
    setCenter(centerInput);
    setRadius(radiusInput);
}

CollisionSphere::~CollisionSphere()
{
    //dtor
}

bool CollisionSphere::isPointInSphere(glm::vec4 pointToTest){
    if(glm::length(pointToTest-getCenter())<getRadius()){
        return true;
    }else return false;

}


bool CollisionSphere::isObjectInSphere(glm::vec4* collisionRectangle){
    for(int i=0;i<4;i++){
        if(isPointInSphere(collisionRectangle[i])){
            return true;
        }
    }
    if(isPointInSphere(collisionRectangle[2]))
        return true;

    if(isPointInSphere(collisionRectangle[3]))
        return true;

    return false;
}
