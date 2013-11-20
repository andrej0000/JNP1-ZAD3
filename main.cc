#include "sejf.h"
#include "kontroler.h"
#include <assert.h>
#include <iostream>
#include <utility>
using std::cout;
using std::cin;
using std::endl;
using std::swap;

int main(){
	Sejf s("kupa", 2);
	Sejf s2("dupa", 0);
	swap(s, s2);
	cout << "s[0]: " <<(char) s2[0] << endl;
	cout << "s[5]: " <<(char) s2[5] << endl;
	cout << "s[1]: " <<(char) s2[1] << endl;
	cout << "s[1]: " <<(char) s2[1] << endl;


	Sejf a("test0", 3);
	Sejf b("kopia");

	swap(a, b);
	assert(a[0] == (int)'k');
	assert(a[1] == (int)'o');
	assert(a[2] == (int)'p');
	assert(a[3] == (int)'i');
	assert(a[4] == (int)'a');
	for(int i = 5; i < 42; ++i)
	    assert(a[4] == (int)'a');
	assert(a[0] == -1);

	assert(b[0] == (int)'t');
	assert(b[2] == (int)'s');
	assert(b[4] == (int)'0');
	assert(b[0] == -1);
	return 0;
}
