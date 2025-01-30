# ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{

private:

    int _nb;
    static const int _nbBits;

public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed &operator=(const Fixed& other);

    void setRawBits(int const raw);
    int getRawBits() const;
};



#endif