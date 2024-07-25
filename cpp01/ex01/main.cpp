/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:56:32 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 13:55:17 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int         N = 5;
    
    Zombie* horde = zombieHorde(N, "Bert");
    if (horde == nullptr)
        std::cout << "Failed to create zombie horde" << std::endl;
    else
    {
        for (int i = 0; i < N; ++i)
            horde[i].announce();
        delete[] horde;
    }
    return (0);
}
