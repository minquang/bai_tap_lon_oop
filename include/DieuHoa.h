#ifndef DIEUHOA_H
#define DIEUHOA_H

#include "pch.h"
#include "ThietBi.h"

class DieuHoa : public ThietBi {
    public:
        DieuHoa() {}
        DieuHoa(std::string tenDieuHoa, int nhietDo, int maThietBi) : ThietBi(tenDieuHoa, TrangThai::tat, maThietBi) 
        {
            m_NhietDo = nhietDo;
        }
        ~DieuHoa() {}
    
        int setNhietDo(int nhietDo);
        int getNhietDo();
    private:
        float m_NhietDo;
};

#endif