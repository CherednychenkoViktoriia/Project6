#pragma once
#include <string>
#include <iostream>

class Currency
{
public:
	
	Currency(uint32_t hryvnia, uint32_t kopeck) :
		m_hryvnia(hryvnia),
		m_kopeck(kopeck)
	{
		std::cout << "Currency\n";
	}

	Currency(const Currency& other) = delete;

	Currency(Currency&& other) noexcept
	{
		std::cout << "Currency(Currency&& other)\n";
		m_hryvnia = other.m_hryvnia;
		m_kopeck = other.m_kopeck;
		other.m_hryvnia = 0;
		other.m_kopeck = 0;
	}

	Currency& operator=(const Currency& other) = delete;

	Currency& operator=(Currency&& other) noexcept
	{
		std::cout << "Currency& operator=(Currency&& other)\n";
		m_hryvnia = other.m_hryvnia;
		m_kopeck = other.m_kopeck;
		return *this;
	}

	uint32_t GetHryvnia() const {
		return m_hryvnia;
	}

	uint32_t GetKopeck() const {
		return m_kopeck;
	} 

	~Currency() 
	{
		std::cout << "~Currency\n";
	}

private:
	uint32_t m_hryvnia = 0;
	uint32_t m_kopeck = 0;
};