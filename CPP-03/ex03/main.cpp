#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main() {
    //{ 
    //    std::cout << "test ClapTrap :\n" << std::endl;
        
    //    ClapTrap robot("Robo");
    //    ClapTrap test(robot);

    //    robot.attack("Enemy");
    //    robot.takeDamage(5);
    //    robot.beRepaired(3);
    //    robot.takeDamage(1);
    //    robot.attack("Another Enemy");
    //    robot.beRepaired(5);
    //    robot.takeDamage(10);
    //    robot.beRepaired(5);

    //    robot.set_attack_damage(10);
    //    robot.set_energy_point(10);
    //    robot.set_hit_point(0);
    //    robot.set_name("Robo");

    //    std::cout << "\ntest canonique forme:" << std::endl << std::endl;
    //    std::cout << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;

    //    test.set_attack_damage(5);
    //    test.set_energy_point(100);
    //    test.set_hit_point(100);
    //    test.set_name("test");

    //    test = robot;

    //    std::cout << std::endl << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;
    //}
    //{
    //    std::cout << std::endl << std::endl << "test ScacTrap :\n" << std::endl;
    //    ScavTrap robot("Robo");
    //    ScavTrap test(robot);

    //    robot.attack("Enemy");
    //    robot.guardGate();
    //    robot.takeDamage(5);
    //    robot.beRepaired(3);
    //    robot.guardGate();
    //    robot.takeDamage(1);
    //    robot.attack("Another Enemy");
    //    robot.beRepaired(5);
    //    robot.takeDamage(100);
    //    robot.beRepaired(5);
    //    robot.guardGate();

    //    robot.set_attack_damage(10);
    //    robot.set_energy_point(10);
    //    robot.set_hit_point(0);
    //    robot.set_name("Robo");

    //    std::cout << "\ntest canonique forme:" << std::endl << std::endl;
    //    std::cout << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;

    //    test.set_attack_damage(5);
    //    test.set_energy_point(100);
    //    test.set_hit_point(100);
    //    test.set_name("test");

    //    test = robot;

    //    std::cout << std::endl << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;
    //}
    //{
    //    std::cout << std::endl << std::endl << "test FragTrap :" << std::endl << std::endl;
    //    FragTrap robot("Robo");
    //    FragTrap test(robot);

    //    robot.attack("Enemy");
    //    robot.highFivesGuys();
    //    robot.takeDamage(5);
    //    robot.beRepaired(3);
    //    robot.highFivesGuys();
    //    robot.takeDamage(1);
    //    robot.attack("Another Enemy");
    //    robot.beRepaired(5);
    //    robot.takeDamage(100);
    //    robot.beRepaired(5);
    //    robot.highFivesGuys();

    //    robot.set_attack_damage(10);
    //    robot.set_energy_point(10);
    //    robot.set_hit_point(0);
    //    robot.set_name("Robo");

    //    std::cout << "\ntest canonique forme:" << std::endl << std::endl;
    //    std::cout << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;

    //    test.set_attack_damage(5);
    //    test.set_energy_point(100);
    //    test.set_hit_point(100);
    //    test.set_name("test");

    //    test = robot;

    //    std::cout << std::endl << "name = " << test.get_name() << std::endl;
    //    std::cout << "hit point = " << test.get_hit_point() << std::endl;
    //    std::cout << "energy point = " << test.get_energy_point() << std::endl;
    //    std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;
    //}
    std::cout << std::endl << std::endl << "test DiamondTrap :" << std::endl << std::endl;
        DiamondTrap robot("Robo");
        DiamondTrap test(robot);

        std::cout << std::endl << "name = " << robot.get_name() << std::endl;
        std::cout << "hit point = " << robot.get_hit_point() << std::endl;
        std::cout << "energy point = " << robot.get_energy_point() << std::endl;
        std::cout << "attack damage = " << robot.get_attack_damage() << std::endl << std::endl;

        robot.whoAmI();
        robot.attack("Enemy");
        robot.highFivesGuys();
        robot.takeDamage(5);
        robot.beRepaired(3);
        robot.highFivesGuys();
        robot.takeDamage(1);
        robot.attack("Another Enemy");
        robot.beRepaired(5);
        robot.takeDamage(100);
        robot.beRepaired(5);
        robot.highFivesGuys();

        robot.set_attack_damage(10);
        robot.set_energy_point(10);
        robot.set_hit_point(0);
        robot.set_name("Robo");

        std::cout << "\ntest canonique forme:" << std::endl << std::endl;
        std::cout << "name = " << test.get_name() << std::endl;
        std::cout << "hit point = " << test.get_hit_point() << std::endl;
        std::cout << "energy point = " << test.get_energy_point() << std::endl;
        std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;

        test.set_attack_damage(5);
        test.set_energy_point(100);
        test.set_hit_point(100);
        test.set_name("test");

        test = robot;

        std::cout << std::endl << "name = " << test.get_name() << std::endl;
        std::cout << "hit point = " << test.get_hit_point() << std::endl;
        std::cout << "energy point = " << test.get_energy_point() << std::endl;
        std::cout << "attack damage = " << test.get_attack_damage() << std::endl << std::endl;
    {

    }
    return 0;
}
