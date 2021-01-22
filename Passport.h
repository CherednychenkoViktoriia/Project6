#pragma once
#include <string>
#include <iostream>

class Passport
{
public:
	
	Passport(const std::string& name, const std::string& dateOfBirth,
		const std::string& nationality, const std::string& dateOfIssue,
		uint32_t authority, uint32_t RNTRC) :
		m_name(name),
		m_dateOfBirth(dateOfBirth),
		m_nationality(nationality),
		m_dateOfIssue(dateOfIssue),
		m_authority(authority),
		m_RNTRC(RNTRC)
	{
		std::cout << "Passport\n";
	}

	Passport(const Passport& other):
		m_name(other.m_name),
		m_dateOfBirth(other.m_dateOfBirth),
		m_nationality(other.m_nationality),
		m_dateOfIssue(other.m_dateOfIssue),
		m_authority(other.m_authority),
		m_RNTRC(other.m_RNTRC)
	{	
		std::cout << "Passport(const Passport& other)\n";
	}

	Passport(Passport&& other) = delete;

	Passport& operator=(const Passport& other) = delete;
	
	Passport& operator=( Passport&& other) = delete;

	~Passport()
	{
		std::cout << "~Passport()\n";
	}

	const std::string& GetName() const {
		return m_name;
	}

	uint32_t GetRNTRC() const {
		return m_RNTRC;
	}

private:
	std::string m_name;
	std::string m_dateOfBirth;
	std::string m_nationality;
	std::string m_dateOfIssue;
	uint32_t m_authority = 0;
	uint32_t m_RNTRC = 0;
};