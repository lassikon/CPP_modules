/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:01:02 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 14:06:49 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef> // size_t

template <typename T, typename F> void iter(T *array, size_t len, F func) {
  for (size_t i = 0; i < len; ++i) {
    func(array[i]);
  }
}