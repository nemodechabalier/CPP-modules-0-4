#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>



class WrongAnimal
{
protected:

	std::string _type;

public:

	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType(void) const;
	void setType(const std::string &new_type);

	void makeSound() const;
};


#endif