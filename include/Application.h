#ifndef APPLICATION_H
#define APPLICATION_H

#include "pch.h"

#include <memory>
#include <array>

#include "GiangVien.h"
#include "BangDiem.h"
#include "SinhVien.h"

#define DATAPATH "../data/"

class Application {
    public:
        Application() {
            m_GiangVien = std::make_shared<V_GIANGVIEN>();
            m_SinhVien = std::make_shared<V_SINHVIEN>();
            m_BangDiem = std::make_shared<V_BANGDIEM>();
            nhapDuLieu();
        }
        ~Application() {}

        void run();

    private:
        int nhapDuLieu();
        int luuDuLieu();

        std::shared_ptr<V_GIANGVIEN> m_GiangVien;
        std::shared_ptr<V_SINHVIEN> m_SinhVien;
        std::shared_ptr<V_BANGDIEM> m_BangDiem;
};

#endif