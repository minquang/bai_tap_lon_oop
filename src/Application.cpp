#include <Application.h>

#include <csv.h>
#include <CsvFile.h>

void Application::run() {
    GiangVien giangVien(m_GiangVien, m_SinhVien, m_BangDiem);
    giangVien.suaThongTinGiangVien(543263);
    std::cout << m_GiangVien.get()->at(0).hoTen << std::endl;
    luuDuLieu();
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
    }
    return 0;
}