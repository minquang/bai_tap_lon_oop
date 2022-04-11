#ifndef THIETBI_H
#define THIETBI_H

#include "pch.h"

#include <vector>
#include <memory>

enum class TrangThai {bat, tat};

class ThietBi {
    public:
        ThietBi() {}
        ThietBi(std::string tenThietBi, TrangThai trangThai, int maThietBi) : m_TenThietBi(tenThietBi), m_TrangThai(trangThai), m_MaThietBi(maThietBi) {}
        virtual ~ThietBi() {}

        void nhap();
        void xuat();

        int setTrangThai(TrangThai trangThai);
        TrangThai getTrangThai();

        int setTenThietBi(std::string tenThietBi);
        std::string getTenThietBi();

        int getMaThietBi() {return m_MaThietBi;}

    protected:
        std::string m_TenThietBi;
        TrangThai m_TrangThai;
        int m_MaThietBi;
};

class QLThietBi {
    public:
        QLThietBi() {}
        ~QLThietBi() {}

        void themThietBi(ThietBi thietBi);

        int dieuChinhThietBi(int maThietBi);
        int thayDoiThongSoThietBi(int maThietBi);
        int themThietBi(int maThietBi, std::string tenThietBi, int trangThai, float doSang, float amLuong, int nhietDo);

        std::vector<std::shared_ptr<ThietBi>>& getDL() {return m_ThietBi;}
    private:
        std::vector<std::shared_ptr<ThietBi>> m_ThietBi;
};

#endif