#ifndef SEJF_H
#define SEJF_H
#include <string>
#include "kontroler.h"

const int DOMYSLNE_DOSTEPY = 42;
const int MAX_DOSTEPY = 1000000;

using std::string;

class Kontroler;

class Sejf {
	friend class Kontroler;
	private:
		int dostep;
		std::string napis;
		bool czy_wlamanie;
		bool czy_manipulacja;
	public:
		Sejf(const string  &str, int liczba = DOMYSLNE_DOSTEPY); //constructor
		Sejf(Sejf&& mv); //Move constructor
		~Sejf(); //destruktor
		Kontroler kontroler();
		void operator=(Sejf&& mv);
		void operator+=(int liczba);
		void operator*=(int liczba);
		void operator-=(int liczba);
		int16_t operator[](int index);
		friend std::ostream & operator<<(std::ostream & out, const Kontroler & kontroler);
};

#endif
