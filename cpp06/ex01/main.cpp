/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:41 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 12:43:46 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void greenMessage(std::string message) {
  std::cout << "\033[32m" << message << "\033[0m\n";
}

static void redMessage(std::string message) {
  std::cout << "\033[31m" << message << "\033[0m\n";
}

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
    greenMessage("Serialization and deserialization succeeded!");
  } else {
    redMessage("Error: Pointers do not match!");
  }

  return 0;
}