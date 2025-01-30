#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _nb(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Fixed::Fixed(const Fixed& other) : _nb(other._nb) {
//     std::cout << "Copy constructor called" << std::endl;
// }

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
