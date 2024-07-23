/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:56:55 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/23 11:26:32 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (nullptr);
    
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        new (&horde[i]) Zombie(name);
    return (horde);
}
