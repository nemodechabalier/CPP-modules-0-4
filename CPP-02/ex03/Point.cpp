#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    //std::cout << "default Point constructor" << std::endl;
}

Point::~Point() {
    //std::cout << "default Point destructor" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    //std::cout << "float Point constructor" << std::endl;
}


Point::Point(const Point& other) : _x(other._x.toFloat()), _y(other._y.toFloat()) {
}

const Fixed& Point::get_x() const {
    return _x;
}

const Fixed& Point::get_y() const {
    return _y;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        return *this;
    }
    //    (Fixed)this->_x = other._x;
    //    (Fixed)this->_y = other._y;
    return *this;
}
