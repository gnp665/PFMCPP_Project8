#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) { }

SemiTruck::~SemiTruck() = default;
SemiTruck::SemiTruck(const SemiTruck&) = default;
SemiTruck& SemiTruck::operator=(const SemiTruck&) = default;

void SemiTruck::flashLights()
{
    setSpeed(55);
    std::cout << name << ": Flashing the Headlights." << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": Roger, 10-4 Good Buddy!" << std::endl;
}
