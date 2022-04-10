#ifndef GIANGVIEN_H
#define GIANGVIEN_H

#include "pch.h"

struct ThongTinGiangVien {
    int mgv;
    std::string hoTen;
    int maBoMon;
    std::string tenBoMon;

    ThongTinGiangVien() {}
};

class GiangVien {
    public:
        GiangVien() {}
        GiangVien(int mgv, std::string tenGiangVien, int maBoMon, std::string tenBoMon) {}
        ~GiangVien() {}

        void nhap();
        void chinhSuaThongTin();
        void nhapDiem();
        void xuat();

    private:
        ThongTinGiangVien m_GiangVien;
};

#endif