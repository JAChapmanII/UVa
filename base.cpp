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

int main(int argc, char **argv) {
	return 0;
}

