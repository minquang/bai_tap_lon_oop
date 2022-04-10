#ifndef GIANGVIEN_H
#define GIANGVIEN_H

#include "pch.h"

#include <vector>
#include <memory>

#include "SinhVien.h"

struct ThongTinGiangVien {
    int mgv;
    std::string hoTen;

    ThongTinGiangVien() {}
};

using V_GIANGVIEN = std::vector<ThongTinGiangVien>;

class GiangVien {
    public:
        GiangVien() {}
        GiangVien(std::shared_ptr<V_SINHVIEN> sinhVien, std::shared_ptr<V_GIANGVIEN> giangVien) : m_SinhVien(sinhVien), m_GiangVien(giangVien) {}
        ~GiangVien() {}

        int setDuLieu();

        int nhapDiem();
        int nhapDiem(int msv);

        int xuatDiem();
        int xuatDiem(int msv);

        int chinhSuaThongTinSV(int msv);
        int xoaSinhVien(int msv);

    private:
        void LuuDuLieu();
        std::shared_ptr<V_SINHVIEN> m_SinhVien;
        std::shared_ptr<V_GIANGVIEN> m_GiangVien;
};

#endif