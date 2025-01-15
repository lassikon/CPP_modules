/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:41 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 12:40:25 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data = {42, "Test Data", 3.14f};

  // Serialize the pointer to the Data object
  uintptr_t raw = Serializer::serialize(&data);

  // Deserialize the raw uintptr_t back to a Data* pointer
  Data *deserializedData = Serializer::deserialize(raw);

  std::cout << "Original Data:" << std::endl;
  std::cout << "  ID: " << data.id << ", Name: " << data.name
            << ", Value: " << data.value << std::endl;

  std::cout << "Deserialized Data:" << std::endl;
  std::cout << "  ID: " << deserializedData->id
            << ", Name: " << deserializedData->name
            << ", Value: " << deserializedData->value << std::endl;

  if (&data == deserializedData) {
    std::cout << "Serialization and deserialization succeeded!" << std::endl;
  } else {
    std::cout << "Error: Pointers do not match!" << std::endl;
  }

  return 0;
}