#pragma once

#include "AMateria.hpp"


class Cure : public AMateria
{
private:

public:
	Cure();
	~Cure();
	Cure(const Cure& type);
	Cure& operator=(const Cure& other);

	Cure* clone() const;
	void use(ICharacter& target);
};