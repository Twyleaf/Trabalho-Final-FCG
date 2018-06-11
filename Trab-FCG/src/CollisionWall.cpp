#include "CollisionWall.h"

void CollisionWall::setPoints(glm::vec4 pointsInput[4]){
    points[0]=pointsInput[0];
    points[1]=pointsInput[1];
    points[2]=pointsInput[2];
    points[3]=pointsInput[3];
}

void CollisionWall::setFrontFace(glm::vec4 faceInput[2]){
    points[0]=faceInput[0];
    points[1]=faceInput[1];

}

void CollisionWall::setBackFace(glm::vec4 faceInput[2]){
    points[2]=faceInput[0];
    points[3]=faceInput[1];
}


void CollisionWall::setFrontLeft(glm::vec4 pointInput){
    points[0]=pointInput;
}
void CollisionWall::setFrontRight(glm::vec4 pointInput){
    points[1]=pointInput;
}

void CollisionWall::setBackLeft(glm::vec4 pointInput){
    points[2]=pointInput;
}
void CollisionWall::setBackRight(glm::vec4 pointInput){
    points[3]=pointInput;
}

glm::vec4 CollisionWall::getFrontLeft(){
    return points[0];
}
glm::vec4 CollisionWall::getFrontRight(){
    return points[1];
}
glm::vec4 CollisionWall::getBackLeft(){
    return points[2];
}
glm::vec4 CollisionWall::getBackRight(){
    return points[3];
}

CollisionWall::CollisionWall(glm::vec4 pointsInput[4])
{
    setPoints(pointsInput);
}

CollisionWall::~CollisionWall()
{
    //dtor
}



bool CollisionWall::isInWall(glm::vec4 points[4]){
    glm::vec3 rectangle[4];
    rectangle[0]= glm::vec3(getFrontLeft().x,getFrontLeft().z,1);
    rectangle[1]= glm::vec3(getFrontRight().x,getFrontRight().z,1);
    rectangle[2]= glm::vec3(getBackLeft().x,getBackLeft().z,1);
    rectangle[3]= glm::vec3(getBackRight().x,getBackRight().z,1);

    glm::vec3 objectPoints3[4];
    objectPoints3[0]= glm::vec3(points[0].x,points[0].z,1);
    objectPoints3[1]= glm::vec3(points[1].x,points[1].z,1);
    objectPoints3[2]= glm::vec3(points[2].x,points[2].z,1);
    objectPoints3[3]= glm::vec3(points[3].x,points[3].z,1);

    for (int i=0;i<4;i++){
        float f01=edgeEquation(rectangle[0],rectangle[1],objectPoints3[i]);
        float f13=edgeEquation(rectangle[1],rectangle[3],objectPoints3[i]);
        float f32=edgeEquation(rectangle[3],rectangle[2],objectPoints3[i]);
        float f20=edgeEquation(rectangle[2],rectangle[0],objectPoints3[i]);
        if((f01>=0 && f13>=0)&&(f32>=0&&f20>=0))
            return true;

    }
    return false;


}

float CollisionWall::edgeEquation(glm::vec3 pontoA,glm::vec3 pontoB,glm::vec3 toTest){
    glm::vec3 v=pontoB-pontoA;
    glm::vec3 vLine=glm::vec3(v.y,-1*v.x,0);
    return glm::dot(vLine,(toTest-pontoA));


}

