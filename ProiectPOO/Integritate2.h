#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;

class Integritate2 {
private:
	string ecuatie;
public:
	Integritate2() {
		ecuatie = "";
	}
	Integritate2(string ecuatie) {
		this->ecuatie = ecuatie;
	}
	bool verificareIntegritateUltimSemn(string ecuatie) {
		int ul = ecuatie.length();
		if (ecuatie[ul - 1] == '-' || ecuatie[ul - 1] == '+' || ecuatie[ul - 1] == '^' || ecuatie[ul - 1] == '#' || ecuatie[ul - 1] == '*' || ecuatie[ul - 1] == '/') {
			return false;
		}
		else {
			return true;
		}
	}
	bool verificareIntegritateSemne(string ecuatie) {
		for (int i = 0; i < ecuatie.length(); i++) {
			if (!(ecuatie[i] >= '0' && ecuatie[i] <= '9') && !(ecuatie[i] == '.') && !(ecuatie[i] == '[') && !(ecuatie[i] == ']') && !(ecuatie[i] == '(') && !(ecuatie[i] == ')') && !(ecuatie[i + 1] >= '0' && ecuatie[i + 1] <= '9') && !(ecuatie[i + 1] == '.') && !(ecuatie[i + 1] == '[') && !(ecuatie[i - +1] == ']') && !(ecuatie[i + 1] == '(') && !(ecuatie[i + 1] == ')')) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	Integritate2(const Integritate2& m)
	{
		if (m.ecuatie != "")
		{
			ecuatie = m.ecuatie;
		}
		else
		{
			ecuatie = "";
		}
	}
	~Integritate2()
	{
		if (ecuatie != "")
		{
			ecuatie = "";
		}
	}
	Integritate2& operator=(const Integritate2& m) {
		if (this != &m) {
			if (m.ecuatie != "")
			{
				ecuatie = m.ecuatie;
			}
			else
			{
				ecuatie = "";
			}
		}
		return *this;
	}
	friend istream& operator>>(istream& in, Integritate2& m)
	{
		string buffer;
		cout << "Ecuatie: ";

		in >> buffer;
		m.setEcuatie(buffer.c_str());
		return in;
	}
	friend ostream& operator<<(ostream& out, Integritate2 m)
	{
		if (m.ecuatie != "")
		{
			out << "Ecuatie: " << m.ecuatie << endl;
		}
		else
		{
			out << "Ecuatie: " << endl;
		}
		return out;
	}
	string getEcuatie()
	{
		return ecuatie;
	}

	void setEcuatie(string _ecuatie)
	{
		if (_ecuatie != "")
		{
			ecuatie = _ecuatie;
		}
	}
};

