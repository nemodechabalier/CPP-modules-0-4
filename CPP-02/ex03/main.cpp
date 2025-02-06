#include "Point.hpp"

int main(void) {
    Point A(3, 2);
    Point B(5, 3);
    Point C(2, 4);
    Point point1(3, 3);
    Point point2(0, 0);
    std::cout << "Point A = " << A.get_x().toFloat() << " , " << A.get_y().toFloat() << std::endl;
    std::cout << "Point B = " << B.get_x().toFloat() << " , " << B.get_y().toFloat() << std::endl;
    std::cout << "Point C = " << C.get_x().toFloat() << " , " << C.get_y().toFloat() << std::endl;
    std::cout << "Point A = " << point1.get_x().toFloat() << " , " << point1.get_y().toFloat() << std::endl;
    std::cout << "Point A = " << point2.get_x().toFloat() << " , " << point2.get_y().toFloat() << std::endl;
    if (bsp(A, B, C, point1))
        std::cout << "Le point 1 fait partie du triangle" << std::endl;
    else
        std::cout << "Le point 1 ne fait pas partie du triangle" << std::endl;
    if (bsp(A, B, C, point2))
        std::cout << "Le point 2 fait partie du triangle" << std::endl;
    else
        std::cout << "Le point 2 ne fait pas partie du triangle" << std::endl;
}