#include "ClapTrap.hpp"


ClapTrap::ClapTrap ( void ) {
    this->_init();
    this->_name = "Rick the Default ClapTrap";
    std::cout << this->_name << "(ClapTrap) : Introduction." << std::endl;
    return;
}

ClapTrap::ClapTrap ( std::string name ) {
    this->_init();
    this->_name = name;
    std::cout << this->_name << "(ClapTrap) : Introduction." << std::endl;
    return;
}

ClapTrap::ClapTrap ( ClapTrap const & src ) {
    std::cout << "(ClapTrap) : BLIP BLIP!!!" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap ( void ) {
    std::cout << this->_name << "(ClapTrap): Bye bye." << std::endl;
    return;
}

void ClapTrap::_init ( void ) {
    srand(time(NULL));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeADmg = 30;
    this->_rangedADmg = 20;
    this->_armorDmgReduc = 5;
}

void ClapTrap::_init ( ClapTrap const & rhs ) {
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

ClapTrap & 	ClapTrap::operator= ( ClapTrap const & rhs ) {
    std::cout << "(ClapTrap) Assignation operator called" << std::endl;
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeADmg = rhs.getMeleeADmg();
    this->_rangedADmg = rhs.getRangedADmg();
    this->_armorDmgReduc = rhs.getArmorDmgReduc();
    this->_name = rhs.getName();
    return *this;
}

int    ClapTrap::rangedAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a ranged attack." << std::endl;
    return this->_rangedADmg;
}

int    ClapTrap::meleeAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a melee attack." << std::endl;
    return this->_meleeADmg;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
    } else if (amount - this->_armorDmgReduc == 0) {
        std::cout << this->_name << " take 0 damage.";
    } else {
        this->_hitPoints = this->_hitPoints - (amount - this->_armorDmgReduc);
        if (this->_hitPoints < 0) {
            this->_hitPoints = 0;
        }
        if (this->_hitPoints <= 0) {
            std::cout << this->_name << " shut down. RIP" << std::endl;
        } else {
            std::cout << this->_name << " take " << amount << " damage. Reduced by ";
            std::cout << this->_armorDmgReduc << std::endl;
            std::cout << this->_name << " now has " << this->_hitPoints << " hp." << std::endl;
        }
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
    }
    std::cout << this->_name << " get repaired of  " << amount << " hp.";
    std::cout << " He has now " << this->_hitPoints << " hp." << std::endl;
}

int     ClapTrap::getHitPoints() const{
    return this->_hitPoints;
}

int     ClapTrap::getMaxHitPoints() const{
    return this->_maxHitPoints;
}

int     ClapTrap::getEnergyPoints() const{
    return this->_energyPoints;
}

int     ClapTrap::getMaxEnergyPoints() const{
    return this->_maxEnergyPoints;
}

std::string    ClapTrap::getName() const{
    return this->_name;
}

int     ClapTrap::getLevel() const{
    return this->_level;
}

int     ClapTrap::getMeleeADmg() const{
    return this->_meleeADmg;
}

int     ClapTrap::getRangedADmg() const{
    return this->_rangedADmg;
}

int     ClapTrap::getArmorDmgReduc() const{
    return this->_armorDmgReduc;
}

void    ClapTrap::setName(std::string name) {
    this->_name = name;
}