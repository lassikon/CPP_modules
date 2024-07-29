/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:26 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/29 19:30:13 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();

        ClapTrap&   operator=(const ClapTrap& other);

        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};