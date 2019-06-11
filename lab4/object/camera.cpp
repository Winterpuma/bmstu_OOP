#ifndef CAMERA_CPP
#define CAMERA_CPP

#include "camera.h"

Camera::Camera() : shiftParam(3, 0), scaleParam(3, 1), rotateParam(3, 0) {}

double Camera::getShX() const {return shiftParam[0];}
double Camera::getShY() const {return shiftParam[1];}
double Camera::getShZ() const {return shiftParam[2];}

double Camera::getScX() const {return scaleParam[0];}
double Camera::getScY() const {return scaleParam[1];}
double Camera::getScZ() const {return scaleParam[2];}

double Camera::getRtX() const {return rotateParam[0];}
double Camera::getRtY() const {return rotateParam[1];}
double Camera::getRtZ() const {return rotateParam[2];}

void Camera::shift(const double x, const double y, const double z)
{
    shiftParam[0] += x;
    shiftParam[1] += y;
    shiftParam[2] += z;
}

void Camera::scale(const double x, const double y, const double z)
{
    scaleParam[0] *= x;
    scaleParam[1] *= y;
    scaleParam[2] *= z;
}

void Camera::rotate(const double x, const double y, const double z)
{
    rotateParam[0] += x;
    rotateParam[1] += y;
    rotateParam[2] += z;
}

#endif // CAMERA_CPP

