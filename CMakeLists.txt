cmake_minimum_required(VERSION 3.5)

project(bai_tap_lon_oop)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(thirdparty/fast-cpp-csv-parser)

add_executable(bai_tap_lon_oop
    src/main.cpp
    include/pch.h
    src/pch.cpp
    src/Application.cpp
    src/ThietBi.cpp
    src/Camera.cpp
    src/Cua.cpp
    src/DieuHoa.cpp
    src/MayChieu.cpp
    src/GiangVien.cpp
    src/SinhVien.cpp
    src/BangDiem.cpp
)