#include <string>
#include <iostream>
#include <assert.h>
#include "sejf.h"
#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

using namespace std;

Sejf::Sejf(const string & str, int liczba) : napis(str), czy_wlamanie(false), czy_manipulacja(false)
{
	if (debug)
		cout << "Constructor Sejf(string, int)" << endl;
    assert(liczba >= 0);
	if (liczba > MAX_DOSTEPY)
		liczba = DOMYSLNE_DOSTEPY;
	this->dostep = liczba;
}

Sejf::Sejf(Sejf&& mv)
{
	if (debug)
		cout << "Move constructor Sejf(Sejf&&)" << endl;
	this->napis = move(mv.napis);
}

Sejf::~Sejf()
{
	if (debug)
		cout << "Destructor ~Sejf()" << endl;
}

void Sejf::operator=(Sejf&& mv)
{
	if (this != &mv){
		this->napis = move(mv.napis);
		this->dostep = mv.dostep;

	}
}

void Sejf::operator+=(int liczba)
{
	int tmp = liczba + this->dostep;
	if (tmp >= dostep){
        this->dostep = tmp;
        czy_manipulacja = true;
    }
}

void Sejf::operator-=(int liczba)
{
	int tmp = this->dostep - liczba;
	if (tmp <= dostep && tmp >= 0){
        this->dostep = tmp;
        czy_manipulacja = true;
    }
}

void Sejf::operator*=(int liczba)
{

	int tmp = liczba * this->dostep;
	if (tmp >= dostep){
        this->dostep = tmp;
        czy_manipulacja = true;
	}

}

int16_t Sejf::operator[](int index)
{
	if (debug)
		cout << "operator[" << index << "] dostep " << this->dostep << endl;
	if (dostep == 0){
		czy_wlamanie = true;
		return -1;
	}
	if (index < 0 || (unsigned int) index >= this->napis.size())
		return -1;

	dostep--;
	return (short)this->napis.at(index);
}

Kontroler Sejf::kontroler()
{
	return Kontroler(this);
}
