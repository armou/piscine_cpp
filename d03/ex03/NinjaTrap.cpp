#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap ( void ) : ClapTrap() {
    this->_init();
    this->_name = "Rikimaru the Default NinjaTrap";
    std::cout << this->_name << "(NinjaTrap) : So smooth." << std::endl;
    return;
}

NinjaTrap::NinjaTrap ( std::string name ) : ClapTrap(name) {
    this->_init();
    this->_name = name;
    std::cout << this->_name << "(NinjaTrap) : So smooth." << std::endl;
    return;
}

NinjaTrap::NinjaTrap ( NinjaTrap const & src ) : ClapTrap(src) {
    std::cout << "(NinjaTrap) : ITADAKIMASU !!!" << std::endl;
    *this = src;
    return;
}

NinjaTrap::~NinjaTrap ( void ) {
    std::cout << this->_name << "(NinjaTrap) HARA-KIRI" << std::endl;
    return;
}

void NinjaTrap::_init ( void ) {
    srand(time(NULL));
    this->_hitPoints = 60;
    this->_maxHitPoints = 60;
    this->_energyPoints = 120;
    this->_maxEnergyPoints = 120;
    this->_level = 1;
    this->_meleeADmg = 60;
    this->_rangedADmg = 5;
    this->_armorDmgReduc = 0;
}

void NinjaTrap::_init ( NinjaTrap const & rhs ) {
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

NinjaTrap & 	NinjaTrap::operator= ( NinjaTrap const & rhs ) {
    std::cout << "(NinjaTrap) Assignation" << std::endl;
    this->_init(rhs);
    return *this;
}

int    NinjaTrap::rangedAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    ClapTrap::rangedAttack(target);
    std::cout << "Shuriken !" << std::endl;
    return this->_rangedADmg;
}

int    NinjaTrap::meleeAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    ClapTrap::meleeAttack(target);
    std::cout << "A shadow in the dark !" << std::endl;
    return this->_meleeADmg;
}

void     NinjaTrap::ninjaShoeBox(ClapTrap & target) {
    std::cout << "ClapTrap are so easy to predict..." << std::endl;
    target.takeDamage(100);

}

void     NinjaTrap::ninjaShoeBox(FragTrap & target) {
    std::cout << this->_name << " knows FragTrap's weaknesses. BackStab !" << std::endl;
    target.takeDamage(80);
    
}

void     NinjaTrap::ninjaShoeBox(ScavTrap & target) {
    std::cout << this->_name << " attacks " << target.getName() << ". It's not very effective..." << std::endl;
    target.takeDamage(5);

}

void     NinjaTrap::ninjaShoeBox(NinjaTrap & target) {

    std::cout << this->_name << " attacks his fellow NinjaTrap " << target.getName() << " with full force." << std::endl;
    target.takeDamage(200);
    this->takeDamage(200);
}