#include <Application.h>

#include <csv.h>

void Application::run() {

}

int Application::nhapDuLieu() {
    io::CSVReader<2> in("../test/giangvien.csv");
    in.read_header(io::ignore_extra_column, "HoTen", "MGV");
    std::string hoTen;
    int MGV;
    while(in.read_row(hoTen, MGV)){
        std::cout << hoTen << "\t" << MGV << std::endl;
    }
}