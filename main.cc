#include "sejf.h"
#include "kontroler.h"
#include <iostream>
#include <utility>
using std::cout;
using std::cin;
using std::endl;
using std::swap;

int main(){
	Sejf s("kupa", 2);
	Sejf s2("dupa", -3);
	swap(s, s2);
	cout << "s[0]: " <<(char) s[0] << endl;
	cout << "s[5]: " <<(char) s[5] << endl;
	cout << "s[1]: " <<(char) s[1] << endl;
	cout << "s[1]: " <<(char) s[1] << endl;
}
