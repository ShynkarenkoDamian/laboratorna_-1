#ifndef VIP_CLIENT
#define VIP_CLIENT

#include "Client.h"

class VIPClient : public Client
{
private:
	int discountRate;
	double loyaltyPoints;
public:
	VIPClient();
	VIPClient(std::string name, std::string license, std::string phone, int rate, double points);
	VIPClient(const VIPClient& other);
	VIPClient(VIPClient&& other) noexcept;
	~VIPClient();

	void showInfo() const override;

	VIPClient& operator=(const VIPClient& other);
};

#endif