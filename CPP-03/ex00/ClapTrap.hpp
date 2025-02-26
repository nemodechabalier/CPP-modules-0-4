#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <climits>

class ClapTrap
{
private:

	std::string _name;
	int _hit_point;
	int _energy_point;
	int _attack_damage;

public:

	ClapTrap();
	ClapTrap(const std::string &name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);

	std::string get_name();
	int get_hit_point();
	int get_energy_point();
	int get_attack_damage();

	void set_name(const std::string &name);
	void set_hit_point(int nb);
	void set_energy_point(int nb);
	void set_attack_damage(int nb);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};



#endif