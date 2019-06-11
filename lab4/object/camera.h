#ifndef CAMERA_CH
#define CAMERA_CH

#include "object.h"

#include <vector>

class Camera : public InvisibleObject
{
public:
    Camera();
    ~Camera() = default;

    double getShX() const;
    double getShY() const;
    double getShZ() const;

    double getScX() const;
    double getScY() const;
    double getScZ() const;

    double getRtX() const;
    double getRtY() const;
    double getRtZ() const;

    void shift(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void rotate(const double x, const double y, const double z);

private:
    std::vector<double> shiftParam;
    std::vector<double> scaleParam;
    std::vector<double> rotateParam;
};

#endif // CAMERA_CH

