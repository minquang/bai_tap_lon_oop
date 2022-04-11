#include <ThietBi.h>
#include <cmath>

#include <Camera.h>
#include <DieuHoa.h>
#include <Cua.h>
#include <MayChieu.h>

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
    return 0;
}

TrangThai ThietBi::getTrangThai()
{
    return m_TrangThai;
}


int ThietBi::setTenThietBi(std::string tenThietBi)
{
    tenThietBi = m_TenThietBi;
    return 0;
}

std::string ThietBi::getTenThietBi()
{
    return m_TenThietBi;
}




void QLThietBi::themThietBi(ThietBi thietBi)
{
    m_ThietBi.push_back(std::make_shared<ThietBi>(thietBi));
}

int QLThietBi::themThietBi(int maThietBi, std::string tenThietBi, int trangThai, float doSang, float amLuong, int nhietDo)
{
    int id = std::floor((float)maThietBi/100);
    switch (id)
    {
    case 11:
        m_ThietBi.push_back(std::make_shared<Camera>(tenThietBi, maThietBi, doSang));
        break;
    case 12:
        m_ThietBi.push_back(std::make_shared<Cua>(tenThietBi, maThietBi, trangThai));
        break;
    case 13:
        m_ThietBi.push_back(std::make_shared<DieuHoa>(tenThietBi, nhietDo, maThietBi));
        break;
    case 14:
        m_ThietBi.push_back(std::make_shared<MayChieu>(maThietBi, tenThietBi, doSang));
        break;
    default:
        break;
    }

}


int QLThietBi::dieuChinhThietBi(int maThietBi)
{
    int id = std::floor(static_cast<float>(maThietBi)/100);
    int count = 0;
    if(id == 11) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(thietbi);
                int doSang;
                int trangThai;
                std::cout << "nhap do sang(1 - 10): ";
                std::cin >> doSang;
                std::cout << "nhap trang thai: " << std::endl
                        << "1. Bat" << std::endl
                        << "2. Tat" << std::endl;
                std::cin >> trangThai;
                if(trangThai == 1) {
                    camera.get()->setTrangThai(TrangThai::bat);
                }
                else if(trangThai == 2) {
                    camera.get()->setTrangThai(TrangThai::tat);
                }
                camera.get()->setDoSang(doSang);
                count++;
            }
        }
    }
    else if(id == 12) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Cua> cua = std::dynamic_pointer_cast<Cua>(thietbi);
                int trangThai;
                std::cout << "nhap trang thai: " << std::endl
                        << "1. Bat" << std::endl
                        << "2. Tat" << std::endl;
                std::cin >> trangThai;
                if(trangThai == 1) {
                    cua.get()->setTrangThai(TrangThai::bat);
                }
                else if(trangThai == 2) {
                    cua.get()->setTrangThai(TrangThai::tat);
                }
                count++;
            }
        }
    }
    else if(id == 13) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<DieuHoa> dieuHoa = std::dynamic_pointer_cast<DieuHoa>(thietbi);
                int nhietDo;
                int trangThai;
                std::cout << "nhap nhiet do(16 - 30): ";
                std::cin >> nhietDo;
                std::cout << "nhap trang thai: " << std::endl
                        << "1. Bat" << std::endl
                        << "2. Tat" << std::endl;
                std::cin >> trangThai;
                if(trangThai == 1) {
                    dieuHoa.get()->setTrangThai(TrangThai::bat);
                }
                else if(trangThai == 2) {
                    dieuHoa.get()->setTrangThai(TrangThai::tat);
                }
                dieuHoa.get()->setNhietDo(nhietDo);
                count++;
            }
        }
    }
    else if(id == 14) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<MayChieu> mayChieu = std::dynamic_pointer_cast<MayChieu>(thietbi);
                int doSang;
                int trangThai;
                std::cout << "nhap do sang(1 - 10): ";
                std::cin >> doSang;
                std::cout << "nhap trang thai: " << std::endl
                        << "1. Bat" << std::endl
                        << "2. Tat" << std::endl;
                std::cin >> trangThai;
                if(trangThai == 1) {
                    mayChieu.get()->setTrangThai(TrangThai::bat);
                }
                else if(trangThai == 2) {
                    mayChieu.get()->setTrangThai(TrangThai::tat);
                }
                mayChieu.get()->setDoSang(doSang);
                count++;
            }
        }
    }
    else {
        std::cout << "khong tin thay du lieu" << std::endl;
    }
    if(count = 0) {
        std::cout << "khong tin thay du lieu" << std::endl;
    }
}

int QLThietBi::thayDoiThongSoThietBi(int maThietBi)
{
    int id = std::floor(static_cast<float>(maThietBi)/100);
    int count = 0;
    if(id == 11) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(thietbi);
                std::string tenThietBi;
                std::cout << "nhap ten thiet bi: ";
                std::cin >> tenThietBi;
                camera.get()->setTenThietBi(tenThietBi);
                count++;
            }
        }
    }
    else if(id == 12) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<Cua> cua = std::dynamic_pointer_cast<Cua>(thietbi);
                std::string tenThietBi;
                std::cout << "nhap ten thiet bi: ";
                std::cin >> tenThietBi;
                cua.get()->setTenThietBi(tenThietBi);
                count++;
            }
        }
    }
    else if(id == 13) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<DieuHoa> dieuHoa = std::dynamic_pointer_cast<DieuHoa>(thietbi);
                std::string tenThietBi;
                std::cout << "nhap ten thiet bi: ";
                std::cin >> tenThietBi;
                dieuHoa.get()->setTenThietBi(tenThietBi);
                count++;
            }
        }
    }
    else if(id == 14) {
        for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
            if(it.base()->get()->getMaThietBi() == maThietBi) {
                std::shared_ptr<ThietBi> thietbi = *it;
                std::shared_ptr<MayChieu> mayChieu = std::dynamic_pointer_cast<MayChieu>(thietbi);
                std::string tenThietBi;
                std::cout << "nhap ten thiet bi: ";
                std::cin >> tenThietBi;
                mayChieu.get()->setTenThietBi(tenThietBi);
                count++;
            }
        }
    }
    else {
        std::cout << "khong tin thay du lieu" << std::endl;
    }
    if(count = 0) {
        std::cout << "khong tin thay du lieu" << std::endl;
    }
}
