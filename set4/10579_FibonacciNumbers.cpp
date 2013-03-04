#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
using namespace std;

struct Num {
	string d;
	Num() : d("0") { }
	Num(string id) : d(id) { }
	Num operator+(const Num& rhs) const {
		string a = d, b = rhs.d;
		while(a.length() < b.length())
			a = "0" + a;
		while(b.length() < a.length())
			b = "0" + b;
		//cout << "a: " << a << ", b: " << b << endl;
		string res;
		int carry = 0;
		for(int i = a.length() - 1; i >= 0; --i) {
			int p = (a[i] - '0') + (b[i] - '0'), z = p + carry;
			if(z > 9)
				carry = 1, z -= 10;
			else
				carry = 0;
			res = (char)(z + '0') + res;
		}
		if(carry == 1)
			res = '1' + res;
		return Num(res);
	}
};

map<int, Num> ans;

bool inMap(int n) {
	return (ans.find(n) != ans.end());
}
Num get(int n) {
	if(!inMap(n))
		ans[n] = get(n - 1) + get(n - 2);
	return ans[n];
}

int main(int argc, char **argv) {
	int n;
	cin >> n;

	ans[1] = Num("1");
	ans[2] = Num("1");
	ans[3] = Num("2");

	while(!cin.eof() && cin.good()) {
		cout << get(n).d << endl;

		cin >> n;
	}
}

