#include <iostream>

#include <ThietBi.h>

main() {
    std::cout << "hello world" << std::endl;

    ThietBi thietBi("quat", TrangThai::nghi);
    
    std::cout << thietBi.getTenThietBi() << std::endl;
    if(thietBi.getTrangThai() == TrangThai::nghi) {
        std::cout << "trang thai nghi" << std::endl;
    }
}