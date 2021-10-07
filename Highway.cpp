#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */

    if(auto* my_car = dynamic_cast<Car*>(v))
    {
        my_car->closeWindows();
    }

    else if(auto* my_motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        my_motorcycle->lanesplitAndRace();
    }

    else if(auto* my_truck = dynamic_cast<SemiTruck*>(v))
    {
        my_truck->flashLights();
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 
    trucks pull over, but cars and bikes try to evade!!
    */

    if(auto* my_car = dynamic_cast<Car*>(v))
    {
        my_car->tryToEvade();
    }

    else if(auto* my_motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        my_motorcycle->tryToEvade();
    }

    else if (auto* my_truck = dynamic_cast<SemiTruck*>(v))
    {
        my_truck->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}

void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
