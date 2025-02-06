#include "Fixed.hpp"
std::ostream& operator<<(std::ostream& out, const Fixed& other);


const int Fixed::_nbBits = 8;


Fixed::Fixed() : _nb(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _nb(value) {
    _nb = value << _nbBits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    _nb = roundf(value * 256);
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_nb = other.getRawBits();
    return *this;
}


void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_nb = raw;
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_nb;
}

float Fixed::toFloat() const {
    return _nb / 256.0f;
}

int Fixed::toInt() const {
    return _nb >> _nbBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& other) {
    out << other.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const {
    return this->_nb > other._nb;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_nb < other._nb;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_nb >= other._nb;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_nb <= other._nb;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_nb == other._nb;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_nb != other._nb;
}

Fixed Fixed::operator++() {
    this->_nb += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_nb += 1;
    return temp;
}

Fixed Fixed::operator--() {
    this->_nb -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_nb -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return(a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return(a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return(a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return(a > b ? a : b);
}

