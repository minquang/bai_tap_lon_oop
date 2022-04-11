#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "pch.h"

#include <vector>

struct ThongTinSinhVien {
    int msv;
    std::string hoTen;
    int ngaySinh, thangSinh, namSinh;

    ThongTinSinhVien() = delete;
    ThongTinSinhVien(int msv, std::string hoTen, int ngaySinh, int thangSinh, int namSinh) 
        : msv(msv), hoTen(hoTen), ngaySinh(ngaySinh), thangSinh(thangSinh), namSinh(namSinh) { }
};

using V_SINHVIEN = std::vector<ThongTinSinhVien>;

class SinhVien {
    public: 
        SinhVien() {}
        ~SinhVien() {}

    private:
        V_SINHVIEN m_SinhVien;
};

#endif