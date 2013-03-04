#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	int kases;
	cin >> kases;
	for(int k = 0; k < kases; ++k) {
		int r;
		cin >> r;
		vector<int> ints;
		for(int i = 0; i < r; ++i) {
			int a;
			cin >> a;
			ints.push_back(a);
		}
		sort(ints.begin(), ints.end());
		long total = 0, s = ints[(ints.size() - 1) / 2];
		for(int i = 0; i < ints.size(); ++i)
			total += abs(s - ints[i]);
		cout << total << endl;
	}
}

