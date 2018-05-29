#ifndef KART_H
#define KART_H
// Headers das bibliotecas OpenGL
#include <glad/glad.h>   // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h>  // Criação de janelas do sistema operacional

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>



class Kart
{
    public:
        glm::vec4 getPosition();
        glm::vec4 getSpeed();
        glm::vec4 getAcceleration();
        glm::vec4 getOrientation();
        void setPosition(glm::vec4 positionInput);
        void setSpeed(glm::vec4 speedInput);
        void setAcceleration(glm::vec4 accelerationInput);
        void setOrientation(glm::vec4 orientationInput);
        Kart(glm::vec4 positionInput,glm::vec4 speedInput,glm::vec4 accelerationInput,glm::vec4 orientationInput);
        virtual ~Kart();
        void updatePosition(double previousTime, double currentTime);
        void updateAcceleration(bool UpKeyPressed,bool DownKeyPressed,bool LeftKeyPressed,bool RightKeyPressed);
        void updateSpeed(double previousTime, double currentTime);
        float getKartRotation(bool LeftKeyPressed,bool RightKeyPressed);
        void updateOrientation(float kartRotation,double previousTime, double currentTime);
        void update(bool UpKeyPressed,bool DownKeyPressed,bool LeftKeyPressed,bool RightKeyPressed,double previousTime, double currentTime);

    protected:

    private:
        glm::vec4 position;
        glm::vec4 speed;
        glm::vec4 acceleration;
        glm::vec4 orientation;
        glm::mat4 getMatrixRotateOrientation(float angle);
};

#endif // KART_H
