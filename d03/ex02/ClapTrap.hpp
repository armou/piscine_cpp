#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

    public:
        ClapTrap ( void );
        ClapTrap ( std::string name );
        ClapTrap ( ClapTrap const & src );
        ~ClapTrap ( void );

        ClapTrap &	operator=( ClapTrap const & rhs );


        int             rangedAttack(std::string const & target);
        int             meleeAttack(std::string const & target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        std::string     getName() const;


    protected:
        int             getHitPoints() const;
        int             getMaxHitPoints() const;
        int             getEnergyPoints() const;
        int             getMaxEnergyPoints() const;
        int             getLevel() const;
        int             getMeleeADmg() const;
        int             getRangedADmg() const;
        int             getArmorDmgReduc() const;
        int             _hitPoints;
        int             _maxHitPoints;
        int             _energyPoints;
        int             _maxEnergyPoints;
        int             _level;
        int             _meleeADmg;
        int             _rangedADmg;
        int             _armorDmgReduc;
        std::string     _name;
        

        void            setName(std::string name);

    private:

        void            _init();
        void            _init( ClapTrap const & rhs );


};

#endif