#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>

class ScavTrap {

    public:
        ScavTrap ( void );
        ScavTrap ( std::string name );
        ScavTrap ( ScavTrap const & src );
        ~ScavTrap ( void );

        ScavTrap &	operator=( ScavTrap const & rhs );


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
        int             getArmorDmgReduc() const;

        void             challengeNewcomer( void );

    private:
        void            _init();
        void            _init( ScavTrap const & rhs );
        void             _challenge1( void );
        void             _challenge2( void );
        void             _challenge3( void );
        void             _challenge4( void );
        void             _challenge5( void );
        typedef void     (ScavTrap::* _funcPtr)( void );
        _funcPtr        _array[5];

        int             _hitPoints;
        int             _maxHitPoints;
        int             _energyPoints;
        int             _maxEnergyPoints;
        int             _level;
        std::string     _name;
        int             _meleeADmg;
        int             _rangedADmg;
        int             _armorDmgReduc;

};

#endif