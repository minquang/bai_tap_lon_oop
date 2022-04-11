#ifndef MAYCHIEU_H
#define MAYCHIEU_H

#include "pch.h"

#include "ThietBi.h"

class MayChieu : public ThietBi {
    public:
        MayChieu() {}
        MayChieu(int maThietBi, std::string tenThietBi, float doSang)
         : ThietBi(tenThietBi, TrangThai::tat, maThietBi), m_DoSang(doSang) {}
        ~MayChieu() {}

        void setDoSang(float doSang);
        float getDoSang() {return m_DoSang;}
    private:
        std::string m_TenThietBi;
        float m_DoSang;
};

#endif