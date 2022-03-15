#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;

class Integritate {
private:
	string ecuatie;
public:
	Integritate() {
		ecuatie = "";
	}
	Integritate(string ecuatie) {
		this->ecuatie = ecuatie;
	}
	bool verificareIntegritate0(string ecuatie) {
		if (ecuatie != "inf") {
			return true;
		}
		else {
			return false;
		}
	}
	bool verificareIntegritateParanteze(string ecuatie) {
		int t = 0;
		int q = 0;
		int t1 = 0;
		int q1 = 0;
		for (int i = 0; i < ecuatie.length(); i++) {
			if (ecuatie[i] == '[') {
				t++;
			}
			if (ecuatie[i] == ']') {
				q++;
			}
			if (ecuatie[i] == '(') {
				t1++;
			}
			if (ecuatie[i] == ')') {
				q1++;
			}
		}
		if (t != q || q1 != t1) {
			return false;
		}
		else {
			return true;
		}
	}
	Integritate(const Integritate& m)
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
	~Integritate()
	{
		if (ecuatie != "")
		{
			ecuatie = "";
		}
	}
	Integritate& operator=(const Integritate& m) {
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
	friend istream& operator>>(istream& in, Integritate& m)
	{
		string buffer;
		cout << "Ecuatie: ";

		in >> buffer;
		m.setEcuatie(buffer.c_str());
		return in;
	}
	friend ostream& operator<<(ostream& out, Integritate m)
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