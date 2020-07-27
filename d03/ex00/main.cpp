#include "FragTrap.hpp"

int main(void) {
    FragTrap    instance("Eustache");
    FragTrap    target("Buddha");
    FragTrap    toto("Toto");

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