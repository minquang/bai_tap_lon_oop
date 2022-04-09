#ifndef CAMERA_H
#define CAMERA_H

#include "pch.h"
#include "ThietBi.h"

class Camera : public ThietBi {
    public:
        Camera(std::string tenCam) : ThietBi(tenCam, TrangThai::tat) {}
        Camera() {}
        ~Camera() {}
    private:

};

#endif