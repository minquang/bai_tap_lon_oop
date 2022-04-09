#include <ThietBi.h>

void ThietBi::nhap()
{
    std::cout << "nhap ten thiet bi: " << std::endl;
    std::cin >> m_TenThietBi;
    fflush(stdin);
}

void ThietBi::xuat()
{
    std::cout << "ten thiet bi: " << m_TenThietBi << std::endl;
}


int ThietBi::setTrangThai(TrangThai trangThai)
{
    trangThai = m_TrangThai;
}

TrangThai ThietBi::getTrangThai()
{
    return m_TrangThai;
}


int ThietBi::setTenThietBi(std::string tenThietBi)
{
    tenThietBi = m_TenThietBi;
}

std::string ThietBi::getTenThietBi()
{
    return m_TenThietBi;
}



