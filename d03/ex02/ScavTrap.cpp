#include "ScavTrap.hpp"


ScavTrap::ScavTrap ( void ) : ClapTrap() {
    this->_init();
    this->_name = "Bob the Default ScavTrap";
    std::cout << this->_name << "(ScavTrap) enter the arena." << std::endl;
    return;
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap ( name ) {
    this->_init();
    this->_name = name;
    std::cout << this->_name << "(ScavTrap) enter the arena." << std::endl;
    return;
}

ScavTrap::ScavTrap ( ScavTrap const & src ) : ClapTrap ( src ) {
    std::cout << this->_name << "(ScavTrap) : CLONING" << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap ( void ) {
    std::cout << this->_name  << "(ScavTrap) : AUTO DESTRUCTION" << std::endl;
    return;
}

void ScavTrap::_init ( void ) {
    srand(time(NULL));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeADmg = 20;
    this->_rangedADmg = 15;
    this->_armorDmgReduc = 3;
    this->_array[0] = &ScavTrap::_challenge1;
    this->_array[1] = &ScavTrap::_challenge2;
    this->_array[2] = &ScavTrap::_challenge3;
    this->_array[3] = &ScavTrap::_challenge4;
    this->_array[4] = &ScavTrap::_challenge5;
}

void ScavTrap::_init ( ScavTrap const & rhs ) {
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeADmg = rhs.getMeleeADmg();
    this->_rangedADmg = rhs.getRangedADmg();
    this->_armorDmgReduc = rhs.getArmorDmgReduc();
    this->_name = rhs.getName();
}

ScavTrap & 	ScavTrap::operator= ( ScavTrap const & rhs ) {
    std::cout << "(ScavTrap) Assignation" << std::endl;
    this->_init(rhs);
    return *this;
}

int    ScavTrap::rangedAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    ClapTrap::rangedAttack(target);
    std::cout << "Sniping in progress..." << std::endl;
    return this->_rangedADmg;
}

int    ScavTrap::meleeAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    ClapTrap::meleeAttack(target);
    std::cout << "BOUH ! I'm right here !" << std::endl;
    return this->_meleeADmg;
}

void     ScavTrap::challengeNewcomer( void ) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
    } else {
        (((*this).*_array[(rand()%5)])());
    }
}

void    ScavTrap::_challenge1( void ) {
    std::cout << this->_name << " tries to count until 10. So impressive he manage to repair himself in the process. " << std::endl;
    this->beRepaired(30);
}

void    ScavTrap::_challenge2( void ) {
    std::cout << this->_name << " tries to fuck itself. It fails. Miserably. ";
    this->takeDamage(20);
}

void    ScavTrap::_challenge3( void ) {
    std::cout << this->_name << " tries to climb stairs. The worst enemy. " << std::endl;
    this->takeDamage(50);
}

void    ScavTrap::_challenge4( void ) {
    std::cout << this->_name << " tries to eat 10 bubblegums. Somehow the bubblegum add a layer to his armor. ";
    this->_armorDmgReduc += 2;
    std::cout << this->_name << " gain 2 armor. " << std::endl;
}

void    ScavTrap::_challenge5( void ) {
    std::cout << this->_name << " tries to sew his screwdriver to his head to become a unicorn." << std::endl;
    this->_meleeADmg += 10;
    std::cout << this->_name << " gain 10 melee attack damage." << std::endl;
}