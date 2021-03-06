#ifndef CAMERA_H
#define CAMERA_H

#include "pch.h"
#include "ThietBi.h"

class Camera : public ThietBi {
    public:
        Camera(std::string tenCam, int maThietBi, float doSang) : ThietBi(tenCam, TrangThai::tat, maThietBi), m_DoSang(doSang) {}
        Camera() {}
        ~Camera() {}
        
        void setDoSang(const float& doSang);
        float getDoSang() {return m_DoSang;}
    private:
        float m_DoSang;
};

#endif