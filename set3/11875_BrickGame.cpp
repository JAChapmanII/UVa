#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	int kases;
	cin >> kases;
	for(int k = 1; k <= kases; ++k) {
		int count;
		cin >> count;

		vector<int> ages;
		for(int i = 0; i < count; ++i) {
			int a;
			cin >>  a;
			ages.push_back(a);
		}

		cout << "Case " << k << ": " << ages[count / 2] << endl;
	}
	return 0;
}

