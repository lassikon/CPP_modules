/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:56:12 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 15:06:00 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm> // find
#include <stdexcept>

template <typename T> int easyfind(T &container, int value) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), value);

  if (it != container.end()) {
    return *it;
  }

  throw std::runtime_error("Value not found in the container");
}