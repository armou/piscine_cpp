#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>

class FragTrap {

    public:
        FragTrap ( void );
        FragTrap ( std::string name );
        FragTrap ( FragTrap const & src );
        ~FragTrap ( void );

        FragTrap &	operator=( FragTrap const & rhs );


        int            rangedAttack(std::string const & target);
        int            meleeAttack(std::string const & target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        int             getHitPoints() const;
        int             getMaxHitPoints() const;
        std::string     getName() const;
        int             getEnergyPoints() const;
        int             getMaxEnergyPoints() const;
        int             getLevel() const;
        int             getMeleeADmg() const;
        int             getRangedADmg() const;
        int             getSpecial1ADmg() const;
        int             getSpecial2ADmg() const;
        int             getSpecial3ADmg() const;
        int             getArmorDmgReduc() const;

        int             vaulthunter_dot_exe(std::string const & target);

    private:
        void            _init();
        void            _init( FragTrap const & rhs );
        int             _specialAttack1(std::string const & target);
        int             _specialAttack2(std::string const & target);
        int             _specialAttack3(std::string const & target);
        bool            _checkAliveStatus() const;
        typedef int     (FragTrap::* _funcPtr)(std::string const & target);
        _funcPtr        _array[5];

        int             _hitPoints;
        int             _maxHitPoints;
        int             _energyPoints;
        int             _maxEnergyPoints;
        int             _level;
        std::string     _name;
        int             _meleeADmg;
        int             _rangedADmg;
        int             _special1ADmg;
        int             _special2ADmg;
        int             _special3ADmg;
        int             _armorDmgReduc;

};

#endif