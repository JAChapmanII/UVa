#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	int kases;
	cin >> kases;

	for(int k = 0; k < kases; ++k) {
		int ccount;
		cin >> ccount;

		vector<int> coins;
		long total = 0;
		for(int i = 0; i < ccount; ++i) {
			int c;
			cin >> c;
			total += c;
			coins.push_back(c);
		}

		//sort(coins.begin(), coins.end());

		map<long, bool> canHit;
		canHit[0] = true;

		for(int i = 0; i < coins.size(); ++i) {
			map<long, bool> nextHit;

			for(map<long, bool>::iterator z = canHit.begin();
					z != canHit.end(); ++z)
				if(canHit[z->first])
					nextHit[z->first + coins[i]] = true;

			for(map<long, bool>::iterator z = nextHit.begin();
					z != nextHit.end(); ++z)
				canHit[z->first] = true;

		}

		long diff = total;
		for(map<long, bool>::iterator z = canHit.begin(); z != canHit.end(); ++z)
			if(abs(total - 2*z->first) < diff) {
				diff = abs(total - 2*z->first);
			}

		cout << diff << endl;
	}
	return 0;
}

