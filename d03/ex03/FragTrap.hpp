#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        FragTrap ( void );
        FragTrap ( std::string name );
        FragTrap ( FragTrap const & src );
        ~FragTrap ( void );

        FragTrap &	operator=( FragTrap const & rhs );


        int             rangedAttack(std::string const & target);
        int             meleeAttack(std::string const & target);
        // void            takeDamage(unsigned int amount);
        // void            beRepaired(unsigned int amount);
        int             vaulthunter_dot_exe(std::string const & target);
        int             getSpecial1ADmg() const;
        int             getSpecial2ADmg() const;
        int             getSpecial3ADmg() const;

    private:
        void            _init();
        void            _init( FragTrap const & rhs );
        int             _specialAttack1(std::string const & target);
        int             _specialAttack2(std::string const & target);
        int             _specialAttack3(std::string const & target);
        typedef int     (FragTrap::* _funcPtr)(std::string const & target);
        _funcPtr        _array[5];
        int             _special1ADmg;
        int             _special2ADmg;
        int             _special3ADmg;

};

#endif