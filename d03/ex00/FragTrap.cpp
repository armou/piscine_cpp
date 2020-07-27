#include "FragTrap.hpp"



FragTrap::FragTrap ( void ) {
    this->_init();
    this->_name = "Eustache the Default FragTrap";
    std::cout << this->_name << " : Hello noobs." << std::endl;
    return;
}

FragTrap::FragTrap ( std::string name ) {
    this->_init();
    this->_name = name;
    std::cout << this->_name << " : Hello noobs." << std::endl;
    return;
}

FragTrap::FragTrap ( FragTrap const & src ) {
    std::cout << "MULTIPLY !!!" << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap ( void ) {
    std::cout << this->_name << " dies. Sad." << std::endl;
    return;
}

void FragTrap::_init ( void ) {
    srand(time(NULL));
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeADmg = 30;
    this->_rangedADmg = 20;
    this->_special1ADmg = 40;
    this->_special2ADmg = 45;
    this->_special3ADmg = 70;
    this->_armorDmgReduc = 5;
    this->_array[0] = &FragTrap::meleeAttack;
    this->_array[1] = &FragTrap::rangedAttack;
    this->_array[2] = &FragTrap::_specialAttack1;
    this->_array[3] = &FragTrap::_specialAttack2;
    this->_array[4] = &FragTrap::_specialAttack3;
}

void FragTrap::_init ( FragTrap const & rhs ) {
    this->_hitPoints = rhs.getHitPoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeADmg = rhs.getMeleeADmg();
    this->_rangedADmg = rhs.getRangedADmg();
    this->_special1ADmg = rhs.getSpecial1ADmg();
    this->_special2ADmg = rhs.getSpecial2ADmg();
    this->_special3ADmg = rhs.getSpecial3ADmg();
    this->_armorDmgReduc = rhs.getArmorDmgReduc();
    this->_name = rhs.getName();
}

FragTrap & 	FragTrap::operator= ( FragTrap const & rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    this->_init(rhs);
    return *this;
}

int    FragTrap::rangedAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a ranged attack. Target the eyes !" << std::endl;
    return this->_rangedADmg;
}

int    FragTrap::meleeAttack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    std::cout << this->_name << " attacks " << target << " with a melee attack. In your teeth !" << std::endl;
    return this->_meleeADmg;
}

void    FragTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
    } else if (amount - this->_armorDmgReduc == 0) {
        std::cout << this->_name << " take 0 damage. EZ.";
    } else {
        this->_hitPoints = this->_hitPoints - (amount - this->_armorDmgReduc);
        if (this->_hitPoints < 0) {
            this->_hitPoints = 0;
        }
        if (this->_hitPoints <= 0) {
            std::cout << this->_name << " fall on the floor and gently dies while singing a lullaby. RIP" << std::endl;
        } else {
            std::cout << this->_name << " take " << amount << " damage. Thanks to his shiny armor he reduce taken damages by ";
            std::cout << this->_armorDmgReduc << ".  OUCH ! It hurts like mofo." << std::endl;
            std::cout << this->_name << " now has " << this->_hitPoints << " hp." << std::endl;
        }
    }
}

void    FragTrap::beRepaired(unsigned int amount) {
    this->_hitPoints += amount;
    if (this->_hitPoints > this->_maxHitPoints) {
        this->_hitPoints = this->_maxHitPoints;
    }
    std::cout << this->_name << " pray to SkyNet and get repaired of  " << amount << " hp.";
    std::cout << " He has now " << this->_hitPoints << " hp." << std::endl;
}

int     FragTrap::vaulthunter_dot_exe(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << this->_name << " is already dead." << std::endl;
        return 0;
    }
    if (this->_energyPoints < 25) {
        std::cout << this->_name << " has not enough energy to use his special Kung-Fu" << std::endl;
    } else {
        this->_energyPoints -= 25;
        if (this->_energyPoints < 0) {
            this->_energyPoints = 0;
        }
        return(((*this).*_array[(rand()%5)])(target));
    }
    return 0;
}

int    FragTrap::_specialAttack1(std::string const & target) {
    std::cout << this->_name << " launch a sneaky attack by revealing to " << target << " his private parts.";
    std::cout << " The attack does " << this->_special1ADmg << " damage." << std::endl;
    return this->_special1ADmg;
}

int    FragTrap::_specialAttack2(std::string const & target) {
    std::cout << this->_name << " empty his tank shamelessly on " << target << ". The smell is horrible !!!";
    std::cout << " The attack does " << this->_special2ADmg << " damage." << std::endl;
    return this->_special2ADmg;  
}

int    FragTrap::_specialAttack3(std::string const & target) {
    std::cout << this->_name << " use energy to launch his special attack on " << target << " : VIETNAMESE GATTLING CHOPSTICKS GUN!!";
    std::cout << " CRITICAL HIT ! The attack does " << this->_special3ADmg << " damage." << std::endl;
    return this->_special3ADmg;  
}

int     FragTrap::getHitPoints() const{
    return this->_hitPoints;
}

int     FragTrap::getMaxHitPoints() const{
    return this->_maxHitPoints;
}

int     FragTrap::getEnergyPoints() const{
    return this->_energyPoints;
}

int     FragTrap::getMaxEnergyPoints() const{
    return this->_maxEnergyPoints;
}

std::string    FragTrap::getName() const{
    return this->_name;
}

int     FragTrap::getLevel() const{
    return this->_level;
}

int     FragTrap::getMeleeADmg() const{
    return this->_meleeADmg;
}

int     FragTrap::getRangedADmg() const{
    return this->_rangedADmg;
}

int     FragTrap::getSpecial1ADmg() const{
    return this->_special1ADmg;
}

int     FragTrap::getSpecial2ADmg() const{
    return this->_special2ADmg;
}

int     FragTrap::getSpecial3ADmg() const{
    return this->_special3ADmg;
}

int     FragTrap::getArmorDmgReduc() const{
    return this->_armorDmgReduc;
}