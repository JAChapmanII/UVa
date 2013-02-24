#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	int count;
	cin >> count;
	while(!cin.eof() && cin.good()) {
		bool *hitMap = new bool[count - 1];
		for(int i = 0; i < count; ++i)
			hitMap[i] = false;

		int n, ln, d;
		cin >> ln;
		for(int i = 1; i < count; ++i) {
			cin >> n;
			d = abs(ln - n);
			if(d > 0 && d < count)
				hitMap[d - 1] = true;
			ln = n;
		}

		bool jolly = true;
		if(count > 1)
			for(int i = 0; i < count - 1 && jolly; ++i) {
				jolly &= hitMap[i];
			}

		if(jolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

		delete[] hitMap;
		cin >> count;
	}

	return 0;
}

