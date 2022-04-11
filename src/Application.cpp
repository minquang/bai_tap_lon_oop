#include <Application.h>

#include <csv.h>
#include <CsvFile.h>
#include <cmath>

void Application::run() {
    GiangVien giangVien(m_GiangVien, m_SinhVien, m_BangDiem);
    bool isExit = false;
    int option; //biến lưu lại lựa chọn người dùng
    do {
        std::cout <<"___LOP HOC THONG MINH___:" << std::endl
                <<"1. giang vien" << std::endl
                <<"2. sinh vien" << std::endl
                <<"3. van hanh thiet bi" << std::endl
                <<"4. tu dong dieu khien thiet bi" << std::endl
                <<"5. luu du lieu" << std::endl
                <<"6. thoat" << std::endl
                <<"----------------------------"<< std::endl << std::endl 
                <<"lua chon: ";
        std::cin >> option; 
        switch (option) {
            case 1:
                int option_giangvien;
                bool isExit_giangvien;
                do {
                    isExit_giangvien = false;
                    std::cout << "___GIANG VIEN___" << std::endl 
                            << "1. Diem danh" << std::endl
                            << "2. Nhap diem" << std::endl
                            << "3. Them sinh vien" << std::endl
                            << "4. Xoa sinh vien" << std::endl
                            << "5. Chinh sua thong tin sinh vien" << std::endl
                            << "6. Chinh sua thong tin giao vien" << std::endl
                            << "7. Quay lai" << std::endl
                            <<"----------------------------"<< std::endl << std::endl 
                            <<"lua chon: ";
                    std::cin >> option_giangvien;
                    switch(option_giangvien) {
                        int msv;
                        int mgv;
                        case 1:
                            std::cout << "diem danh" << std::endl;
                            break;
                        case 2:
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            giangVien.nhapDiem(msv);
                            break;
                        case 3:
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            std::cout << "them sinh vien" << std::endl;
                            break;
                        case 4:
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            giangVien.xoaSinhVien(msv);
                            break;
                        case 5:
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            giangVien.chinhSuaThongTinSV(msv);
                            break;
                        case 6:
                            std::cout << "nhap mgv" << std::endl;
                            std::cin >> mgv;
                            giangVien.suaThongTinGiangVien(mgv);
                            break;
                        case 7:
                            isExit_giangvien = true;
                            break;
                        default:
                            isExit_giangvien = true;
                            break;
                    }
                } while(!isExit_giangvien);
                
                break;
            case 2:
                
                break;
            case 3:
                int option_vanhanhthietbi;
                bool isExit_vanhanhthietbi;
                do {
                    isExit_vanhanhthietbi = false;
                    std::cout << "___VAN HANH THIET BI___" << std::endl 
                            << "1. dieu chinh thiet bi" << std::endl
                            << "2. chinh sua thiet bi" << std::endl
                            << "3. Quay lai" << std::endl
                            <<"----------------------------"<< std::endl << std::endl 
                            <<"lua chon: ";

                } while(!isExit_vanhanhthietbi);
                break;
            case 4:
                break;
            case 5:
                if(luuDuLieu() == 0) {
                    std::cout << "luu du lieu thanh cong" << std::endl;
                }
                else {
                    std::cout << "luu du lieu that bai" << std::endl;
                }
                break;
            case 6:
                isExit = true;
                break;
            default:
                isExit = true;
                break;
        }
    } while (!isExit);
}


int Application::nhapDuLieu() {
    io::CSVReader<2> in(DATAPATH "giangvien.csv");
    in.read_header(io::ignore_extra_column, "HoTen", "MGV");
    std::string hoTen; int MGV;
    while(in.read_row(hoTen, MGV)){
        m_GiangVien.get()->emplace_back(ThongTinGiangVien(MGV, hoTen));
    }
    
    io::CSVReader<9> in1(DATAPATH "sinhvien.csv");
    in1.read_header(io::ignore_extra_column, 
                    "TenSinhVien", 
                    "MSV", 
                    "NgaySinh", 
                    "ThangSinh", 
                    "NamSinh", 
                    "DiemChuyenCan", 
                    "DiemGiuaKi", 
                    "DiemCuoiKi", 
                    "DiemTongKet");
    std::string TenSinhVien; int MSV; int NgaySinh; int ThangSinh; int NamSinh; 
    float DiemChuyenCan; float DiemGiuaKi; float DiemCuoiKi; float DiemTongKet;
    while(in1.read_row(TenSinhVien,
                        MSV, NgaySinh,
                        ThangSinh,
                        NamSinh,
                        DiemChuyenCan,
                        DiemGiuaKi,
                        DiemCuoiKi,
                        DiemTongKet)){
        
        m_SinhVien.get()->emplace_back(ThongTinSinhVien(MSV, TenSinhVien, NgaySinh, ThangSinh, NamSinh));
        m_BangDiem.get()->emplace_back(ThongTinBangDiem(MSV, DiemChuyenCan, DiemGiuaKi, DiemCuoiKi));
    }
    return 0;
}


int Application::luuDuLieu() {
    try
    {
        csvfile csv(DATAPATH "giangvien.csv");
        // Header
        csv << "HoTen" << "MGV" << endrow;
        // Data
        for(auto it = m_GiangVien.get()->begin(); it != m_GiangVien.get()->end(); it++) {
            csv << it.base()->hoTen << it.base()->mgv << endrow;
        }

        csvfile csv1(DATAPATH "sinhvien.csv");
        // Header
        csv1 << "TenSinhVien" << "MSV" << "NgaySinh" << "ThangSinh" << "NamSinh" << "DiemChuyenCan" << "DiemGiuaKi" << "DiemCuoiKi" << "DiemTongKet" << endrow;
        // Data
        for(int i = 0; i < m_SinhVien.get()->size(); i++) {
            m_SinhVien.get()->at(i);
            m_BangDiem.get()->at(i);
            csv1 << m_SinhVien.get()->at(i).hoTen 
                << m_SinhVien.get()->at(i).msv 
                << m_SinhVien.get()->at(i).ngaySinh 
                << m_SinhVien.get()->at(i).thangSinh
                << m_SinhVien.get()->at(i).namSinh
                << m_BangDiem.get()->at(i).diemChuyenCan
                << m_BangDiem.get()->at(i).diemKiemTra
                << m_BangDiem.get()->at(i).diemThi
                << m_BangDiem.get()->at(i).diemTrungBinh << endrow;
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception was thrown: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}