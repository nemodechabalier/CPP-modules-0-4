#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"



class MateriaSource : public IMateriaSource {

private:
	AMateria** _materia;
	int _countMateria;

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource& other);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const& type);
};