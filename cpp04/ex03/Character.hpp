/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:13:01 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/12 11:42:43 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _inventory[4];

    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        ~Character() override;

        Character&          operator=(const Character& other);

		std::string const & getName() const override;
		void                equip(AMateria* m) override;
		void                unequip(int idx) override;
		void                use(int idx, ICharacter& target) override;
        AMateria*           getInventory(int idx) const;
};

#endif