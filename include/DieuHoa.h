#ifndef DIEUHOA_H
#define DIEUHOA_H

#include "pch.h"
#include "ThietBi.h"

class DieuHoa : public ThietBi {
    private:
        DieuHoa() {}
        DieuHoa(std::string tenDieuHoa, int nhietDo) : ThietBi(tenDieuHoa, TrangThai::tat) 
        {
            nhietDo = m_NhietDo;
        }
        ~DieuHoa() {}
    
        void setNhietDo(int nhietDo);
        int getNhietDo();
    public:
        int m_NhietDo;
};

#endif