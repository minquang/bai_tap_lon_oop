#include <ThietBi.h>
#include <cmath>

#include <Camera.h>
#include <DieuHoa.h>
#include <Cua.h>

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


int QLThietBi::dieuChinhThietBi(int maThietBi)
{
    for(auto it = m_ThietBi.begin(); it != m_ThietBi.end(); it++) {
        std::shared_ptr<ThietBi> thietbi = *it;
        if(std::floor(static_cast<float>(it.base()->get()->getMaThietBi())/100) == 11) {
            std::shared_ptr<Camera> test = std::dynamic_pointer_cast<Camera>(thietbi);
            test.get()->setDoSang(3.5f);
        }
    }
}

int QLThietBi::thayDoiThongSoThietBi(int maThietBi)
{

}
