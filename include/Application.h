#ifndef APPLICATION_H
#define APPLICATION_H

#include "pch.h"

#include "memory"

#include "GiangVien.h"
#include "BangDiem.h"
#include "SinhVien.h"

class Application {
    public:
        Application() {
            nhapDuLieu();
        }
        ~Application() {}

        void run();

    private:
    int nhapDuLieu();

    std::shared_ptr<V_GIANGVIEN> m_GiangVien;
    std::shared_ptr<V_SINHVIEN> m_SinhVien;
};

#endif