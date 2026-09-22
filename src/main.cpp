#include <iostream>
#include <func.h>
#include <cmath>

int main(int, char**)
{
    std::cout << " 已知观察点为：（12，13）" << "\n";

    std::cout << "请输入三维点的xyz坐标" << "\n";
    double point_x {getValue( "Point_x") } ;
    double point_y {getValue( "Point_y") } ;
    double point_z {getValue( "Point_z") } ;


    std::cout << "请输入相机内参" << "\n";
    double fx {getValue("横轴变化参数")};
    double fy {getValue("纵轴变化参数")};
    double cx {getValue("横轴平移参数")};
    double cy {getValue("纵轴平移参数")};

    std::cout << "相机外参R为" << "\n"
    <<"|- -1 0 0 -|\n"
    <<"|  0 -1 0  |\n"
    <<"|  0  0 1  |\n"
    ;
    std::cout << "外参T为" << "\n"
    << "|- 7 -|\n"
    << "|  11 |\n"
    << "|- 5 -|\n";
    
    //计算相机坐标系下的点坐标
    //展开即Xc=-Xw+7 ，Yc=-Yw+11 ,Zc=Zw+5
    point_x = point_x * (-1) + 7 ;
    point_y = point_y * (-1) + 11;
    point_z = point_z * (1)  + 5 ;

    //判断point_z是否为正
    if (point_z <= 0) 
        std::cout << "输入有问题，出现非正深度";

    if (point_z <= 0)
        return 0;

    //计算像素坐标系下的坐标
    double u {point_x * fx / point_z + cx};
    double v {point_y * fy / point_z + cy};
    
    
    std::cout << "像素坐标系下的坐标为（" << u << "," << v << ")" ;

    //计算像素欧式距离

    double d {std::hypot(u - 12,v - 13)} ;
    std::cout << "像素欧式距离是" << d << "\n";
    return 0;
}