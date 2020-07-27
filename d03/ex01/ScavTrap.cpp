#include "ScavTrap.hpp"


ScavTrap::ScavTrap ( void ) {
    this->_init();
    this->_name = "Bob the Default ScavTrap";
    std::cout << this->_name << " enter the arena." << std::endl;
    return;
}

ScavTrap::ScavTrap ( std::string name ) {
    this->_init();
    this->_name = name;
    std::cout << this->_name << " enter the arena." << std::endl;
    return;
}

ScavTrap::ScavTrap ( ScavTrap const & src ) {
    std::cout << this->_name << " : CLONING" << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap ( void ) {
    std::cout << this->_name  << " : AUTO DESTRUCTION" << std::endl;
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
    // std::cout << "Assignation" << std::endl;
    this->_init(rhs);
    return *this;
}

int    ScavTrap::rangedAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a ranged attack. Sniping in progress..." << std::endl;
    return this->_rangedADmg;
}

int    ScavTrap::meleeAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a melee attack. BOUH ! I'm right here !" << std::endl;
    return this->_meleeADmg;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
    } else if (amount - this->_armorDmgReduc == 0) {
        std::cout << this->_name << " take 0 damage. GG.";
    } else {
        this->_hitPoints = this->_hitPoints - (amount - this->_armorDmgReduc);
        if (this->_hitPoints < 0) {
            this->_hitPoints = 0;
        }
        if (this->_hitPoints <= 0) {
            std::cout << this->_name << " dig his own grave before lying on the floor. RIP" << std::endl;
        } else {
            std::cout << this->_name << " take " << amount << " damage. Thanks to his lucky screwdriver he reduce taken damages by ";
            std::cout << this->_armorDmgReduc << ". Tis but a scratch" << std::endl;
            std::cout << this->_name << " now has " << this->_hitPoints << " hp." << std::endl;
        }
    }
}

void    ScavTrap::beRepaired(unsigned int amount) {
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
    }
    std::cout << this->_name << " tinker his armor with his lucky screwdriver to repair  " << amount << " hp.";
    std::cout << " He has now " << this->_hitPoints << " hp." << std::endl;
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
    // std::cout << this->_name << " take 20 damage. " << std::endl;
}

void    ScavTrap::_challenge3( void ) {
    std::cout << this->_name << " tries to climb stairs. The worst enemy. " << std::endl;
    this->takeDamage(50);
    // std::cout << this->_name << " take 50 damage. " << std::endl;
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

int     ScavTrap::getHitPoints() const{
    return this->_hitPoints;
}

int     ScavTrap::getMaxHitPoints() const{
    return this->_maxHitPoints;
}

int     ScavTrap::getEnergyPoints() const{
    return this->_energyPoints;
}

int     ScavTrap::getMaxEnergyPoints() const{
    return this->_maxEnergyPoints;
}

std::string    ScavTrap::getName() const{
    return this->_name;
}

int     ScavTrap::getLevel() const{
    return this->_level;
}

int     ScavTrap::getMeleeADmg() const{
    return this->_meleeADmg;
}

int     ScavTrap::getRangedADmg() const{
    return this->_rangedADmg;
}

int     ScavTrap::getArmorDmgReduc() const{
    return this->_armorDmgReduc;
}