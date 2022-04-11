#include <Application.h>

#include <csv.h>
#include <CsvFile.h>
#include <cmath>

#include <Camera.h>
#include <Cua.h>
#include <DieuHoa.h>
#include <MayChieu.h>

void Application::run() {
    GiangVien giangVien(m_GiangVien, m_SinhVien, m_BangDiem);
    bool isExit = false;
    int option; //biến lưu lại lựa chọn người dùng
    do {
        std::cout << "\033[2J\033[1;1H"; // clear screen
        std::cout <<"___LOP HOC THONG MINH___:" << std::endl
                <<"1. giang vien" << std::endl
                <<"2. van hanh thiet bi" << std::endl
                <<"3. tai lau du lieu" << std::endl
                <<"4. luu du lieu" << std::endl
                <<"5. thoat" << std::endl
                <<"----------------------------"<< std::endl << std::endl 
                <<"lua chon: ";
        std::cin >> option; 
        std::string tenSinhVien; 
        switch (option) {
            case 1:
                int option_giangvien;
                bool isExit_giangvien;
                do {
                    isExit_giangvien = false;
                    std::cout << "\033[2J\033[1;1H"; // clear screen
                    std::cout << "___GIANG VIEN___" << std::endl 
                            << "1. Diem danh" << std::endl
                            << "2. Nhap diem" << std::endl
                            << "3. Them sinh vien" << std::endl
                            << "4. Xoa sinh vien" << std::endl
                            << "5. Chinh sua thong tin sinh vien" << std::endl
                            << "6. Chinh sua thong tin giang vien" << std::endl
                            << "7. Quay lai" << std::endl
                            <<"----------------------------"<< std::endl << std::endl 
                            <<"lua chon: ";
                    std::cin >> option_giangvien;
                    switch(option_giangvien) {
                        int msv;
                        int mgv;
                        int ngaySinh, thangSinh, namSinh, c;
                        case 1:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Diem danh__" << std::endl;
                            std::cout << "nhap msv: ";
                            std::cin >> msv;
                            c = 0;
                            for(auto i = m_SinhVien.get()->begin(); i != m_SinhVien.get()->end(); i++) {
                                if(msv == i.base()->msv) {
                                    std::cout << "co mat" << std::endl;
                                    c++;
                                }
                            }
                            if(c == 0) {
                                std::cout << "khong tim thay sinh vien" << std::endl;
                            }
                            break;
                        case 2:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Nhap diem__" << std::endl;
                            std::cout << "nhap msv: ";
                            std::cin >> msv;
                            giangVien.nhapDiem(msv);
                            break;
                        case 3:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Them sinh vien__" << std::endl;
                            std::cout << "nhap msv: ";
                            std::cin >> msv;
                            std::cout << "nhap ten sinh vien: ";
                            std::cin >> tenSinhVien;
                            std::cout << "nhap ngay, thang, nam sinh: ";
                            std::cin >> ngaySinh >> thangSinh >> namSinh;
                            m_SinhVien.get()->emplace_back(ThongTinSinhVien(msv, tenSinhVien, ngaySinh, thangSinh, namSinh));
                            m_BangDiem.get()->emplace_back(ThongTinBangDiem(msv, 0, 0, 0));
                            break;
                        case 4:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Xoa sinh vien__" << std::endl;
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            giangVien.xoaSinhVien(msv);
                            break;
                        case 5:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Chinh sua thong tin sinh vien__" << std::endl;
                            std::cout << "nhap msv" << std::endl;
                            std::cin >> msv;
                            giangVien.chinhSuaThongTinSV(msv);
                            break;
                        case 6:
                            std::cout << "\033[2J\033[1;1H"; // clear screen
                            std::cout << "__Chinh sua thong tin giang vien__" << std::endl;
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
                int option_vanhanhthietbi;
                bool isExit_vanhanhthietbi;
                do {
                    isExit_vanhanhthietbi = false;
                    std::cout << "\033[2J\033[1;1H"; // clear screen
                    std::cout << "___VAN HANH THIET BI___" << std::endl 
                            << "1. dieu chinh thiet bi" << std::endl
                            << "2. chinh sua thong so thiet bi" << std::endl
                            << "3. them thiet bi" << std::endl
                            << "4. Quay lai" << std::endl
                            <<"----------------------------"<< std::endl << std::endl 
                            <<"lua chon: ";
                    std::cin >> option_vanhanhthietbi;
                    std::string tenThietBi; 
                    switch (option_vanhanhthietbi)
                    {
                        int maThietBi; int trangThai; float doSang; float amLuong; int nhietDo;
                    case 1:
                        std::cout << "\033[2J\033[1;1H"; // clear screen
                        std::cout << "__Dieu chinh thiet bi__" << std::endl;
                        std::cout << "nhap ma thiet bi: ";
                        std::cin >> maThietBi;
                        m_QLThietBi.dieuChinhThietBi(maThietBi);
                        break;
                    case 2:
                        std::cout << "\033[2J\033[1;1H"; // clear screen
                        std::cout << "__Chinh sua thong so thiet bi__" << std::endl;
                        std::cout << "nhap ma thiet bi: ";
                        std::cin >> maThietBi;
                        m_QLThietBi.thayDoiThongSoThietBi(maThietBi);
                        break;
                    case 3:
                        std::cout << "\033[2J\033[1;1H"; // clear screen
                        std::cout << "__Them thiet bi__" << std::endl;
                        std::cout << "nhap ma thiet bi: ";
                        std::cin >> maThietBi;
                        std::cout << "nhap ten thiet bi: ";
                        std::cin >> tenThietBi;
                        std::cout << "nhap trang thai: ";
                        std::cin >> trangThai;
                        if(std::floor((float)maThietBi/100) == 11) {
                            std::cout << "nhap do sang: ";
                            std::cin >> doSang;
                        }
                        else if(std::floor((float)maThietBi/100) == 12) {
                            
                        }
                        else if(std::floor((float)maThietBi/100) == 13) {
                            std::cout << "nhap nhiet do: ";
                            std::cin >> nhietDo;
                        }
                        else if(std::floor((float)maThietBi/100) == 14) {
                            std::cout << "nhap do sang: ";
                            std::cin >> doSang;
                        }
                        else {
                            std::cout << "ma thiet bi khong hop le" << std::endl;
                        }
                        m_QLThietBi.themThietBi(maThietBi, tenThietBi, trangThai, doSang, amLuong, nhietDo);
                        break;
                    case 4:
                        isExit_vanhanhthietbi = true;
                        break;
                    default:
                        isExit_vanhanhthietbi = true;
                        break;
                    }

                } while(!isExit_vanhanhthietbi);
                break;
            case 3:
                if(nhapDuLieu() == 0) {
                    std::cout << "tai lai du lieu thanh cong" << std::endl;
                }
                else {
                    std::cout << "tai lai du lieu that bai" << std::endl;
                }
                break;
            case 4:
                if(luuDuLieu() == 0) {
                    std::cout << "luu du lieu thanh cong" << std::endl;
                }
                else {
                    std::cout << "luu du lieu that bai" << std::endl;
                }
                break;
            case 5:
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

    io::CSVReader<6> in2(DATAPATH "thietbi.csv");
    in2.read_header(io::ignore_extra_column, "MaThietBi", "TenThietBi", "TrangThai", "DoSang", "AmLuong", "NhietDo");
    int maThietBi; std::string tenThietBi; int trangThai; float doSang; float amLuong; int nhietDo;
    while(in2.read_row(maThietBi, tenThietBi, trangThai, doSang, amLuong, nhietDo)){
        m_QLThietBi.themThietBi(maThietBi, tenThietBi, trangThai, doSang, amLuong, nhietDo);
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

        csvfile csv2(DATAPATH "thietbi.csv");
        // Header
        csv2 << "MaThietBi" << "TenThietBi" << "TrangThai" << "DoSang" << "AmLuong" << "NhietDo" << endrow;
        // Data
        for(auto it = m_QLThietBi.getDL().begin(); it != m_QLThietBi.getDL().end(); it++) {
            int id = std::floor(static_cast<float>(it.base()->get()->getMaThietBi())/100);
            int trangthai = 0;
            if (it.base()->get()->getTrangThai() == TrangThai::bat) {
                trangthai = 1;
            }
            if(id == 11) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(thietbi);
                csv2 << it.base()->get()->getMaThietBi()
                    << it.base()->get()->getTenThietBi()
                    << trangthai
                    << camera.get()->getDoSang()
                    << ""
                    << "" << endrow;
            }
            else if(id == 12) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Cua> cua = std::dynamic_pointer_cast<Cua>(thietbi);
                csv2 << it.base()->get()->getMaThietBi()
                    << it.base()->get()->getTenThietBi()
                    << trangthai
                    << ""
                    << ""
                    << "" << endrow;
            }
            else if(id == 13) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<DieuHoa> dieuHoa = std::dynamic_pointer_cast<DieuHoa>(thietbi);
                csv2 << it.base()->get()->getMaThietBi()
                    << it.base()->get()->getTenThietBi()
                    << trangthai
                    << ""
                    << ""
                    << dieuHoa.get()->getNhietDo() << endrow;
            }
            else if(id == 14) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<MayChieu> mayChieu = std::dynamic_pointer_cast<MayChieu>(thietbi);
                csv2 << it.base()->get()->getMaThietBi()
                    << it.base()->get()->getTenThietBi()
                    << trangthai
                    << mayChieu.get()->getDoSang()
                    << ""
                    << "" << endrow;
            }
        } 
        
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception was thrown: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}