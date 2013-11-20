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
/*using std::string;
using std::cout;
using std::cin;
using std::endl;*/

int init_dostep(int d)
{
	assert(d > 0);
	if (d < 0 || d > MAX_DOSTEPY)
		d = DOMYSLNE_DOSTEPY;
	return d;
}

Sejf::Sejf(const string & str, int liczba) : napis(move(str)), dostep(init_dostep(liczba)), czy_wlamanie(false), czy_manipulacja(false)
{
	if (debug)
		cout << "Constructor Sejf(string, int)" << endl;
}

Sejf::Sejf(Sejf&& mv) : napis(move(mv.napis)), dostep(mv.dostep), czy_wlamanie(mv.czy_wlamanie), czy_manipulacja(mv.czy_manipulacja)
{
	if (debug)
		cout << "Move constructor Sejf(Sejf&&)" << endl;
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
	if (tmp > dostep){
        this->dostep = tmp;
        czy_manipulacja = true;
    }
}

void Sejf::operator-=(int liczba)
{
	int tmp = liczba - this->dostep;
	if (tmp < dostep && tmp >= 0){
        this->dostep = tmp;
        czy_manipulacja = true;
    }
}

void Sejf::operator*=(int liczba)
{

	int tmp = liczba * this->dostep;
	if (tmp > dostep){
        this->dostep = tmp;
        czy_manipulacja = true;
	}

}

int16_t Sejf::operator[](unsigned int index)
{
	if (debug)
		cout << "operator[" << index << "] dostep " << this->dostep << endl;
	if (dostep == 0){
		czy_wlamanie = true;
		return -1;
	}
	if (index < 0 || index >= this->napis.size())
		return -1;

	dostep--;
	return (short)this->napis.at(index);
}

Kontroler Sejf::kontroler()
{
	return Kontroler(this);
}
