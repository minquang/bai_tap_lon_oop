#ifndef THIETBI_H
#define THIETBI_H

#include <iostream>
#include <string>

enum class TrangThai {hoatDong, nghi};

class ThietBi {
    public:
        ThietBi() {}
        ThietBi(std::string tenThietBi, TrangThai trangThai) : m_TenThietBi(tenThietBi), m_TrangThai(trangThai) {}
        ~ThietBi() {}

        void nhap();
        void xuat();

        int setTrangThai(TrangThai trangThai);
        TrangThai getTrangThai();

        int setTenThietBi(std::string tenThietBi);
        std::string getTenThietBi();

    private:
        std::string m_TenThietBi;
        TrangThai m_TrangThai;
};

#endif