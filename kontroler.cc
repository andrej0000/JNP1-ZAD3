#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

#include "kontroler.h"

using namespace std;

Kontroler::Kontroler(Sejf *s){
	this->sejf = s;
}

ostream & operator<<(ostream& out, const Kontroler& kontroler)
{
	if (kontroler.sejf->czy_wlamanie){
		out << "ALARM: WLAMANIE\n";
	}
	else if (kontroler.sejf->czy_manipulacja){
		out << "ALARM: ZMANIPULOWANY\n";
	}
	else {
		out << "OK\n";
	}
	return out;
}

Kontroler::operator bool() const
{
	if (sejf->dostep > 0)
		return true;
	else
		return false;
}
