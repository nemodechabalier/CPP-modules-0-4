#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"


class Animal
{
protected:

	std::string _type;

public:

	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	std::string getType(void) const;
	void setType(const std::string &new_type);

	virtual void makeSound() const=0;
};


#endif