#ifndef KONTROLER_H
#define KONTROLER_H
#include "sejf.h"
#include <string>
#include <iostream>

class Sejf;

class Kontroler {
	friend class Sejf;

	public:
		friend std::ostream & operator<<(std::ostream & out, const Kontroler & kontroler);
		operator bool() const;
	private:
		Kontroler(Sejf *s);
		Sejf *sejf;

};


#endif
