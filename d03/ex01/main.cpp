#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    FragTrap    instance("Eustache");
    FragTrap    target("Buddha");
    FragTrap    toto("Toto");
    ScavTrap    bob;
    ScavTrap    jean("Jean");

    bob.challengeNewcomer();
    bob.challengeNewcomer();
    bob.challengeNewcomer();
    bob.challengeNewcomer();
    bob.challengeNewcomer();
    jean.takeDamage(bob.meleeAttack(jean.getName()));
    bob.takeDamage(jean.rangedAttack(bob.getName()));
    target.takeDamage(instance.vaulthunter_dot_exe(target.getName()));
    toto.takeDamage(instance.vaulthunter_dot_exe(toto.getName()));
    target.beRepaired(20);
    toto = target;
    target.takeDamage(instance.vaulthunter_dot_exe(target.getName()));
    toto.takeDamage(instance.vaulthunter_dot_exe(toto.getName()));
    target.takeDamage(instance.vaulthunter_dot_exe(target.getName()));
    target.takeDamage(instance.vaulthunter_dot_exe(target.getName()));

    return 0;
}