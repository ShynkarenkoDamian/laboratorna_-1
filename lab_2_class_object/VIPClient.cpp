#include "VIPClient.h"

VIPClient::VIPClient() : Client("unknown","unknown","unknown"), discountRate(0), loyaltyPoints(0)
{}

VIPClient::VIPClient(std::string name, std::string license, std::string phone, int rate, double points) 
	: Client (name,license,phone), discountRate(rate), loyaltyPoints(points)
{}

VIPClient::VIPClient(const VIPClient& other)
	: Client(other), discountRate(other.discountRate), loyaltyPoints(other.loyaltyPoints)
{}

VIPClient::VIPClient(VIPClient&& other) noexcept
	: Client(std::move(other)), discountRate(other.discountRate), loyaltyPoints(other.loyaltyPoints)
{
	other.discountRate = 0;
	other.loyaltyPoints = 0;
}

VIPClient::~VIPClient()
{}

VIPClient& VIPClient::operator=(const VIPClient& other)
{
	if (this != &other)
	{
		Client::operator=(other);
		discountRate = other.discountRate;
		loyaltyPoints = other.loyaltyPoints;
	}
	return *this;
}

