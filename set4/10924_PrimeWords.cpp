#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

long fromChar(char c) {
	if(c >= 'a' && c <= 'z')
		return c - 'a' + 1;
	return c - 'A' + 27;
}

bool isPrime(long n) {
	switch(n) {
		case 1: case 2: case 3: case 5: case 7: return true;
		default:break;
	}
	long m = sqrt(n) + 1;
	if(m >= n)
		m = n - 1;
	for(int d = 2; d <= m; d++)
		if(n % d == 0)
			return false;
	return true;
}

int main(int argc, char **argv) {
	string word;
	getline(cin, word);
	while(!cin.eof() && cin.good()) {
		long num = 0;
		for(int i = 0; i < word.length(); ++i)
			num += fromChar(word[i]);
		if(isPrime(num))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;

		getline(cin, word);
	}
}

