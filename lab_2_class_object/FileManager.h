#pragma once
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Rental.h"
#include "Client.h"

class FileManager final
{
public:
	static void saveVehicles(const std::vector<std::shared_ptr<Vehicle>>& vehicles);
	static void loadVehicles(std::vector<std::shared_ptr<Vehicle>>& vehicles);
	static void saveRentals(const std::vector<std::shared_ptr<Rental>>& rentals);
	static void loadRentals(std::vector<std::shared_ptr<Rental>>& rentals, std::vector<std::shared_ptr<Client>>& clients, std::vector<std::shared_ptr<Vehicle>>& vehicles);
	static void saveClients(const std::vector<std::shared_ptr<Client>>& clients);
	static void loadClients(std::vector<std::shared_ptr<Client>>& clients);
};

