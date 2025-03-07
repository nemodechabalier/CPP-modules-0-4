#include "MateriaSource.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

MateriaSource::MateriaSource() : _materia(NULL), _countMateria(0) {
	//std::cout << "MateriaSource: default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	if (other._countMateria) {
		_materia = new AMateria * [_countMateria];
		for (int i = 0; i < _countMateria; i++)
			_materia[i] = other._materia[i]->clone();
	}
	else
		_materia = NULL;
	//std::cout << "MateriaSource: copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		if (other._countMateria) {
			_materia = new AMateria * [_countMateria];
			for (int i = 0; i < _countMateria;i++)
				_materia[i] = other._materia[i]->clone();
		}
		else
			_materia = NULL;
	}
	//std::cout << "MateriaSource: copy assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _countMateria; i++)
		delete _materia[i];
	delete[] _materia;
	//std::cout << "MateriaSource: default destructor called" << std::endl;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void MateriaSource::learnMateria(AMateria* materia) {
	if (materia == NULL)
		return;
	AMateria** new_Materia = new AMateria * [_countMateria + 1];
	for (int i = 0; i < _countMateria ;i++)
		new_Materia[i] = _materia[i];
	new_Materia[_countMateria] = materia;
	_countMateria += 1;
	delete[] _materia;
	_materia = new_Materia;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < _countMateria; i++) {
		if (_materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}