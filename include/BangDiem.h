#ifndef BANGDIEM_H
#define BANGDIEM_H

#include "pch.h"

#include <vector>

struct ThongTinBangDiem {
    int msv;
    float diemChuyenCan;
    float diemKiemTra;
    float diemThi;
    float diemTrungBinh;

    ThongTinBangDiem() : diemChuyenCan(0.f), diemKiemTra(0.f), diemThi(0.f), diemTrungBinh(0.f), msv(0) {}
    ThongTinBangDiem(int msv, float diemChuyenCan = 0.f, float diemKiemTra = 0.f, float diemThi = 0.f)
        : diemChuyenCan(diemChuyenCan), 
        diemKiemTra(diemKiemTra),
        diemThi(diemThi) ,
        msv(msv) {
            tinhDiemTrungBinh();
        }

    void tinhDiemTrungBinh() {
        diemTrungBinh = diemChuyenCan*0.1 + diemKiemTra*0.2 + diemThi*0.7;
    }
};

using V_BANGDIEM = std::vector<ThongTinBangDiem>;

class BangDiem {
    public:
        BangDiem() {}
        ~BangDiem() {}
    private:

};

#endif