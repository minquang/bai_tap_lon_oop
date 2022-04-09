#ifndef CUA_H
#define CUA_H

#include "pch.h"
#include "ThietBi.h"

class Cua : public ThietBi {
    public:
        Cua() {}
        Cua(std::string tenCua) : ThietBi(tenCua, TrangThai::tat) {}
        ~Cua() {}
    private:

};

#endif 