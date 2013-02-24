#include <iostream>
#include <string>
using namespace std;

long convert(string sbin) {
	long num = 0, base = 2;
	for(int i = sbin.length() - 1; i >= 0; --i) {
		num += (sbin[i] - '0') * (base - 1);
		base *= 2;
	}
	return num;
}

int main(int argc, char **argv) {
	string in;
	cin >> in;
	while(in != (string)"0") {
		cout << convert(in) << endl;
		cin >> in;
	}
	return 0;
}

