#ifndef CUA_H
#define CUA_H

#include "pch.h"
#include "ThietBi.h"

class Cua : public ThietBi {
    public:
        Cua() {}
        Cua(std::string tenCua, int maThietBi, int trangThai)
         : ThietBi(tenCua, TrangThai::tat, maThietBi) {}
        ~Cua() {}

    private:

};

#endif 