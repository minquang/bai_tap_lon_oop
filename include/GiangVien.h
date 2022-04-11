#ifndef GIANGVIEN_H
#define GIANGVIEN_H

#include "pch.h"

#include <vector>
#include <memory>

#include "SinhVien.h"
#include "BangDiem.h"

struct ThongTinGiangVien {
    int mgv;
    std::string hoTen;

    ThongTinGiangVien() : mgv(0), hoTen("") {}
    ThongTinGiangVien(int mgv, std::string hoTen) : mgv(mgv), hoTen(hoTen) {}
};


using V_GIANGVIEN = std::vector<ThongTinGiangVien>;

class GiangVien {
    public:
        GiangVien() = delete;
        GiangVien(GiangVien&) = delete;
        GiangVien(GiangVien&&) = delete;
        GiangVien(std::shared_ptr<V_GIANGVIEN> giangVien, std::shared_ptr<V_SINHVIEN> sinhVien, std::shared_ptr<V_BANGDIEM> bangDiem) 
        : m_SinhVien(sinhVien), m_GiangVien(giangVien), m_BangDiem(bangDiem) {}
        ~GiangVien() {}

        int setDuLieu();

        int suaThongTinGiangVien(int mgv);

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
        std::shared_ptr<V_BANGDIEM> m_BangDiem;
};

#endif