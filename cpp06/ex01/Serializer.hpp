/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:21:55 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 12:32:37 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint> // uintptr_t

#include "Data.hpp"

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer() = delete;
  ~Serializer() = delete;
  Serializer(const Serializer &src) = delete;
  Serializer &operator=(const Serializer &src) = delete;
};