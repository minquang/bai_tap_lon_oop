#include <GiangVien.h>

#include <iostream>

int GiangVien::suaThongTinGiangVien(int mgv)
{
    int count = 0;
    for(auto it = m_GiangVien.get()->begin(); it != m_GiangVien.get()->end(); it++) {
        if(it.base()->mgv == mgv) {
            tryAgain:
            std::cout << "nhap ma giang vien: " << std::endl;
            int mgvTamThoi;
            std::cin >> mgvTamThoi;
            if(mgv != mgvTamThoi) {
                for(auto it1 = m_GiangVien.get()->begin(); it1 != m_GiangVien.get()->end(); it1++) {
                    if(mgvTamThoi == it1.base()->mgv) {
                        std::cout << "ma giang vien da ton tai" << std::endl;
                        goto tryAgain;
                    }
                }
            }
            it.base()->mgv = mgvTamThoi;
            std::cout << "nhap ten giang vien: " << std::endl;
            std::cin >> it.base()->hoTen;
            count++;
        }
    }
    if(count == 0) {
        std::cout << "khong tim thay giang vien" << std::endl;
        return -1;
    }
    return 0;
}

int GiangVien::nhapDiem()
{

}

int GiangVien::nhapDiem(int msv)
{
    for(auto it = m_BangDiem.get()->begin(); it != m_BangDiem.get()->end(); it++) {
        if(it.base()->msv == msv) {
            std::cout << "nhap diem chuyen can: " << std::endl;
            std::cin >> it.base()->diemChuyenCan;
            std::cout << "nhap diem kiem tra: " << std::endl;
            std::cin >> it.base()->diemKiemTra;
            std::cout << "nhap diem thi: " << std::endl;
            std::cin >> it.base()->diemThi;
            it.base()->tinhDiemTrungBinh();
        }
    }
    return 0;
}


int GiangVien::xuatDiem()
{

}

int GiangVien::xuatDiem(int msv)
{

}


int GiangVien::chinhSuaThongTinSV(int msv)
{
    for(auto it = m_SinhVien.get()->begin(); it != m_SinhVien.get()->end(); it++) {
        if(it.base()->msv == msv) {
            std::cout << "nhap ho ten SV: " << std::endl;
            std::cin >> it.base()->hoTen;
            std::cout << "nhap ma SV: " << std::endl;
            std::cin >> it.base()->msv;
        }
    }
    return 0;
}

int GiangVien::xoaSinhVien(int msv)
{
    for(auto it = m_SinhVien.get()->begin(); it != m_SinhVien.get()->end(); it++) {
        if(it.base()->msv == msv) {
            it.base()->hoTen = "";
            it.base()->msv = 0;
            it.base()->namSinh = 0;
            it.base()->thangSinh = 0;
            it.base()->ngaySinh = 0;
            m_SinhVien.get()->erase(it);
        }
    }
    return 0;
}