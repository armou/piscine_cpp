#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

    public:
        ScavTrap ( void );
        ScavTrap ( std::string name );
        ScavTrap ( ScavTrap const & src );
        ~ScavTrap ( void );

        ScavTrap &	operator=( ScavTrap const & rhs );


        int             rangedAttack(std::string const & target);
        int             meleeAttack(std::string const & target);
        void             challengeNewcomer( void );

    private:
        void             _init();
        void             _init( ScavTrap const & rhs );
        void             _challenge1( void );
        void             _challenge2( void );
        void             _challenge3( void );
        void             _challenge4( void );
        void             _challenge5( void );
        typedef void     (ScavTrap::* _funcPtr)( void );
        _funcPtr        _array[5];

};

#endif