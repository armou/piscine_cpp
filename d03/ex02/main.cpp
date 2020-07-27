#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    // FragTrap    instance("Kiki");
    // ScavTrap    jean("Jean");
    // ClapTrap    godzilla("GodZilla");
    ClapTrap*    rick(0);
    FragTrap*    eustache = new FragTrap;

    // jean.challengeNewcomer();
    // jean.takeDamage(godzilla.meleeAttack(jean.getName()));
    // godzilla.beRepaired(20);
    // godzilla.takeDamage(instance.vaulthunter_dot_exe(godzilla.getName()));
    // godzilla = jean;
    rick = eustache;
    std::cout << eustache->getName() << std::endl;
    std::cout << rick->getName() << std::endl;
    // godzilla.takeDamage(instance.vaulthunter_dot_exe(godzilla.getName()));

    return 0;
}