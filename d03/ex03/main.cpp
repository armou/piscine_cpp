#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void) {
    FragTrap    instance("Kiki");
    ScavTrap    jean("Jean");
    ClapTrap    godzilla("GodZilla");
    NinjaTrap    riki("Rikimaru");
    NinjaTrap    riko("Riko");

    riki.ninjaShoeBox(godzilla);
    riki.ninjaShoeBox(jean);
    riki.ninjaShoeBox(instance);
    riki.ninjaShoeBox(riko);
    jean.challengeNewcomer();
    jean.takeDamage(godzilla.meleeAttack(jean.getName()));
    godzilla.beRepaired(20);
    godzilla.takeDamage(instance.vaulthunter_dot_exe(godzilla.getName()));
    godzilla = jean;
    godzilla.takeDamage(instance.vaulthunter_dot_exe(godzilla.getName()));

    return 0;
}