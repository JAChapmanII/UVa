#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T> T fromString(string str) {
	stringstream ss(str);
	T res;
	ss >> res;
	return res;
}

template<typename T> string toString(T val) {
	stringstream ss;
	ss << val;
	return ss.str();
}

bool isPalindrome(string str) {
	if(str.length() <= 1)
		return true;
	for(int i = 0; i <= str.length() / 2; ++i)
		if(str[i] != str[str.length() - 1 - i])
			return false;
	return true;
}

string reverse(string str) {
	string rev; rev.reserve(str.length());
	for(int i = 0; i < str.length(); ++i)
		rev += str[str.length() - 1 - i];
	return rev;
}

int main(int argc, char **argv) {
	int caseCount = 0;
	cin >> caseCount;
	for(int i = 0; i < caseCount; ++i) {
		long num = -1;
		cin >> num;
		long iters = 0;
		while(!isPalindrome(toString(num)) && iters < 2000)
			iters++, num += fromString<long>(reverse(toString(num)));
		cout << iters << " " << num << endl;
	}
	return 0;
}

