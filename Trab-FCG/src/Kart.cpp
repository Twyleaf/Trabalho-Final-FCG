#include "Kart.h"
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define TURNING_VALUE 0.4f


glm::vec4 Kart::getPosition(){
    return position;
}

glm::vec4 Kart::getSpeed(){
    return speed;
}


glm::vec4 Kart::getAcceleration(){
    return acceleration;
}

float Kart::getOrientationAngle(){
    return orientation;
}

glm::vec4 Kart::getOrientationVector(){
    glm::vec4 forwardVector= glm::vec4(0.0,0.0,1.0,0.0);
    return getMatrixRotateOrientation(-1*getOrientationAngle())*forwardVector;
}

void Kart::setPosition(glm::vec4 positionInput){
    position=positionInput;
}

void Kart::setSpeed(glm::vec4 speedInput){
    speed= speedInput;
}

void Kart::setAcceleration(glm::vec4 accelerationInput){
    acceleration = glm::normalize(accelerationInput);
}

void Kart::setOrientationAngle(float orientationInput){
    orientation = orientationInput;
}

Kart::Kart(glm::vec4 positionInput,glm::vec4 speedInput,glm::vec4 accelerationInput,float orientationInput)
{
    setPosition(positionInput);
    setSpeed(speedInput);
    setAcceleration(accelerationInput);
    setOrientationAngle(orientationInput);
    //ctor
}

Kart::~Kart()
{
    //dtor
}

void Kart::updatePosition(double previousTime, double currentTime){
    double timeDifference= currentTime- previousTime;
    glm::vec4 oldPosition=getPosition();
    setPosition(oldPosition+ (getSpeed()*(float)timeDifference));

}

void Kart::updateAcceleration(bool UpKeyPressed,bool DownKeyPressed,bool LeftKeyPressed,bool RightKeyPressed){
    glm::vec4 accelerationDirection = glm::vec4(0.0f,0.0f,0.0f,0.0f);
    if(UpKeyPressed){
        if(!DownKeyPressed){
            accelerationDirection = 10.0f*glm::normalize(getOrientationVector());
        }
    }else if(DownKeyPressed){
        accelerationDirection = -10.0f*glm::normalize(getOrientationVector());
    }
    setAcceleration(accelerationDirection);

}

void Kart::updateSpeed(double previousTime, double currentTime){
    double timeDifference= currentTime- previousTime;
    glm::vec4 oldSpeed=getSpeed();
    /*
    glm::vec4 normOldSpeed = glm::normalize(oldSpeed);
    glm::vec4 accelerationDirection=glm::normalize(getAcceleration());
    float angle = acos(dot(oldSpeed,getAcceleration())/(normOldSpeed*accelerationDirection));
    if((angle<2 ))
    {
        oldSpeed=oldSpeed*0.5f;
    }*/
    glm::vec4 speedFriction=oldSpeed - (oldSpeed *(float)timeDifference*0.1f);
    glm::vec4 newSpeed=speedFriction+ (getAcceleration()*(float)timeDifference);

    if(glm::length(newSpeed)<1000){
        setSpeed(newSpeed);
    }
}

float Kart::getKartRotation(bool LeftKeyPressed,bool RightKeyPressed, bool UpKeyPressed,bool DownKeyPressed){
    if(((LeftKeyPressed&&UpKeyPressed)&&!RightKeyPressed)||((RightKeyPressed&&DownKeyPressed)&&!LeftKeyPressed)){
        return TURNING_VALUE;
    }else if(((RightKeyPressed&&UpKeyPressed)&&!LeftKeyPressed)||((LeftKeyPressed&&DownKeyPressed)&&!RightKeyPressed)){
        return -1*TURNING_VALUE;
    }else return 0;
}

// Matriz R de "rotação de um ponto" em relação à origem do sistema de
// coordenadas e em torno do eixo X (primeiro vetor da base do sistema de
// coordenadas). Seja p=[px,py,pz,pw] um ponto em coordenadas homogêneas.
// Então, a matriz R é definida pela seguinte igualdade:
//
//   R*p = [ px, c*py-s*pz, s*py+c*pz, pw ];
//
// onde 'c' e 's' são o cosseno e o seno do ângulo de rotação, respectivamente.
glm::mat4 Kart::getMatrixRotateOrientation(float angle)
{
    float c = cos(angle);
    float s = sin(angle);
    glm::mat4 matrix= glm::mat4(
         c   , 0.0f ,  s   , 0.0f ,
        0.0f , 1.0f , 0.0f , 0.0f ,
        -s   , 0.0f ,  c   , 0.0f ,
        0.0f , 0.0f , 0.0f , 1.0f
    );
    return matrix;
}

void Kart::updateOrientation(float kartRotation,double previousTime, double currentTime){
    double timeDifference= currentTime- previousTime;
    float oldAngle=getOrientationAngle();

    setOrientationAngle(oldAngle + (kartRotation*timeDifference));

}

void Kart::updateSpeedOrientation(float kartRotation,double previousTime, double currentTime){
    double timeDifference= currentTime- previousTime;
    glm::vec4 oldSpeed=getSpeed();

    setSpeed(getMatrixRotateOrientation(kartRotation*timeDifference*-1.0f)*oldSpeed );

}

glm::vec4* Kart::getCollisionRectangle(){
    glm::vec4 forwardVector=glm::normalize(getOrientationVector());
    glm::vec4 leftVector=getMatrixRotateOrientation(M_PI_2)*forwardVector;
    glm::vec4 center=getPosition();
    glm::vec4 rectangle[4];
    rectangle[0]=center+forwardVector*1.8f+leftVector*0.8f;
    rectangle[1]=center+forwardVector*1.8f-leftVector*0.8f;
    rectangle[2]=center-forwardVector*1.8f+leftVector*0.8f;
    rectangle[3]=center-forwardVector*1.8f-leftVector*0.8f;
    return rectangle;
}

void Kart::update(bool UpKeyPressed,bool DownKeyPressed,bool LeftKeyPressed,bool RightKeyPressed,double previousTime, double currentTime){

    float kartRotation= getKartRotation(LeftKeyPressed,RightKeyPressed,UpKeyPressed,DownKeyPressed);
    updateOrientation(kartRotation,previousTime,currentTime);
    updateSpeedOrientation(kartRotation,previousTime,currentTime);
    updateAcceleration(UpKeyPressed,DownKeyPressed,previousTime, currentTime);
    updateSpeed(previousTime,currentTime);
    updatePosition(previousTime,currentTime);
}


