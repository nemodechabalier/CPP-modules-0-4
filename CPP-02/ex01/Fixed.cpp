#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _nb(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _nb(value) {
    if (value > INT_MAX >> _nbBits) {
        std::cout << "Error overflow" << std::endl;
    }
    _nb = value << _nbBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    if (value > INT_MAX >> _nbBits) {
        std::cout << "Error overflow" << std::endl;
    }
    _nb = roundf(value * 256);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_nb = other.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_nb = raw;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_nb;
}

float Fixed::toFloat() const {
    return (float(_nb) / (1 << _nbBits));
}

int Fixed::toInt() const {
    return _nb >> _nbBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed& other) {
    out << other.toFloat();
    return out;
}