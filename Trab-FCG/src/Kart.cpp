#include "Kart.h"

#define TURNING_VALUE 2.0


glm::vec4 Kart::getPosition(){
    return position;
}

glm::vec4 Kart::getSpeed(){
    return speed;
}


glm::vec4 Kart::getAcceleration(){
    return acceleration;
}

glm::vec4 Kart::getOrientation(){
    return orientation;
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

void Kart::setOrientation(glm::vec4 orientationInput){
    orientation = glm::normalize(orientationInput);
}

Kart::Kart(glm::vec4 positionInput,glm::vec4 speedInput,glm::vec4 accelerationInput,glm::vec4 orientationInput)
{
    setPosition(positionInput);
    setSpeed(speedInput);
    setAcceleration(accelerationInput);
    setOrientation(orientationInput);
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
            accelerationDirection = glm::normalize(getOrientation());
        }
    }
    setAcceleration(accelerationDirection);

}

void Kart::updateSpeed(double previousTime, double currentTime){
    double timeDifference= currentTime- previousTime;
    glm::vec4 oldSpeed=getSpeed();
    glm::vec4 newSpeed=oldSpeed+ (getAcceleration()*(float)timeDifference);
    if(glm::length(newSpeed)<20){
        setSpeed(oldSpeed+ (getAcceleration()*(float)timeDifference));
    }
}

float Kart::getKartRotation(bool LeftKeyPressed,bool RightKeyPressed){
    if(LeftKeyPressed){
        if(RightKeyPressed){
            return 0;
        }else return TURNING_VALUE;
    }else if(RightKeyPressed){
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
    if(kartRotation!=0)
        setOrientation(getMatrixRotateOrientation(kartRotation*timeDifference)*getOrientation());

}

void Kart::update(bool UpKeyPressed,bool DownKeyPressed,bool LeftKeyPressed,bool RightKeyPressed,double previousTime, double currentTime){

    float kartRotation= getKartRotation(LeftKeyPressed,RightKeyPressed);
    updateOrientation(kartRotation,previousTime,currentTime);
    updateAcceleration(UpKeyPressed,DownKeyPressed,previousTime, currentTime);
    updateSpeed(previousTime,currentTime);
    updatePosition(previousTime,currentTime);
}


