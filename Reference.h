#pragma once
#include <string>
#include <iostream>
#include "Passport.h"
#include "Currency.h"

class Reference 
{
public:

	Reference(Passport& client, Currency& finances):
		m_client(&client),
		m_finances(&finances)
	{
		std::cout << "Reference\n";
		m_nameOfClient = m_client->GetName();
		m_RNTRCOfClient = m_client->GetRNTRC();
		m_incomeTax = (m_finances->GetHryvnia() * 20 / 100) + (m_finances->GetKopeck() * 20 / 100);
		std::cout << m_nameOfClient << " " << m_RNTRCOfClient << " " << m_incomeTax << std::endl;
	}

	Reference(const Reference& other)
	{
		std::cout << "Reference(const Reference& other)\n";
		m_client = other.m_client;
		m_finances = other.m_finances;
		m_nameOfClient = other.m_nameOfClient;
		m_RNTRCOfClient = other.m_RNTRCOfClient;
		m_incomeTax = other.m_incomeTax;
		std::cout << m_nameOfClient << " " << m_RNTRCOfClient << " " << m_incomeTax << std::endl;
	}

	Reference(Reference&& other) noexcept 
	{
		std::cout << "Reference(Reference&& other)\n";
		m_client = other.m_client;
		m_finances = other.m_finances;
		m_nameOfClient = other.m_nameOfClient;
		m_RNTRCOfClient = other.m_RNTRCOfClient;
		m_incomeTax = other.m_incomeTax;
		other.m_client = nullptr;
		other.m_finances = nullptr;
		other.m_nameOfClient = "";
		other.m_RNTRCOfClient = 0;
		other.m_incomeTax = 0;
		std::cout << m_nameOfClient << " " << m_RNTRCOfClient << " " << m_incomeTax << std::endl;
	}

	Reference& operator=(const Reference& other) 
	{
		std::cout << "Reference& operator=(const Reference& other)\n";
		m_client = other.m_client;
		m_finances = other.m_finances;
		m_nameOfClient = other.m_nameOfClient;
		m_RNTRCOfClient = other.m_RNTRCOfClient;
		m_incomeTax = other.m_incomeTax;
		std::cout << m_nameOfClient << " " << m_RNTRCOfClient << " " << m_incomeTax << std::endl;
		return *this;
	}

	Reference& operator=(Reference&& other) noexcept 
	{
		std::cout << "Reference& operator=(Reference&& other)\n";
		m_client = other.m_client;
		m_finances = other.m_finances;
		m_nameOfClient = other.m_nameOfClient;
		m_RNTRCOfClient = other.m_RNTRCOfClient;
		m_incomeTax = other.m_incomeTax;
		other.m_client = nullptr;
		other.m_finances = nullptr;
		other.m_nameOfClient = "";
		other.m_RNTRCOfClient = 0;
		other.m_incomeTax = 0;
		std::cout << m_nameOfClient << " " << m_RNTRCOfClient << " " << m_incomeTax << std::endl;
		return *this;
	}

	~Reference()
	{
		std::cout << "~Reference()\n";
	}

private:
	Passport* m_client = nullptr;
	Currency* m_finances = nullptr;
	std::string m_nameOfClient;
	uint32_t m_RNTRCOfClient = 0;
	uint32_t m_incomeTax = 0;
};