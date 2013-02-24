#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T> string toString(T arg) {
	stringstream ss;
	ss << arg;
	return ss.str();
}

long carries(long a, long b) {
	string as = toString(a), bs = toString(b);
	while(as.length() < 16)
		as = "0" + as;
	while(bs.length() < as.length())
		bs = "0" + bs;

	long carries = 0;
	long carry = 0;
	for(long i = as.length() - 1; i >= 0; --i) {
		if((as[i] - '0') + (bs[i] - '0') + carry > 9) {
			carry = 1;
			carries++;
		} else
			carry = 0;
	}
	return carries;
}

int main(int argc, char **argv) {
	long a, b;
	cin >> a;
	cin >> b;
	while(a != 0 || b != 0) {

		long c = carries(a, b);
		if(c == 0)
			cout << "No carry operation." << endl;
		else if(c == 1)
			cout << "1 carry operation." << endl;
		else
			cout << c << " carry operations." << endl;

		cin >> a;
		cin >> b;
	}
	return 0;
}

