#pragma once
#include <vector>
#include <memory>
#include "Vehicle.h"

class FileManager final
{
public:
	static void saveVehicles(const std::vector<std::shared_ptr<Vehicle>>& vehicles);
	static void loadVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles);

};

