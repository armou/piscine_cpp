#ifndef NINJATRAP_H
# define NINJATRAP_H

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

    public:
        NinjaTrap ( void );
        NinjaTrap ( std::string name );
        NinjaTrap ( NinjaTrap const & src );
        ~NinjaTrap ( void );

        NinjaTrap &	operator=( NinjaTrap const & rhs );


        int             rangedAttack(std::string const & target);
        int             meleeAttack(std::string const & target);
        void             ninjaShoeBox(ClapTrap & target);
        void             ninjaShoeBox(FragTrap & target);
        void             ninjaShoeBox(ScavTrap & target);
        void             ninjaShoeBox(NinjaTrap & target);

    private:
        void            _init();
        void            _init( NinjaTrap const & rhs );
};

#endif