#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, bool> domap;
struct Pair {
	int i;
	int j;
	Pair(int a, int b) : i(a), j(b) { }
};

bool canEmpty(string w) {
	//cout << w << endl;
	if(domap.find(w) != domap.end())
		return domap[w];
	vector<Pair> pairs;
	int i = 0;
	while(i < w.length()) {
		int j = i;
		while(w[i] == w[j + 1])
			j++;
		pairs.push_back(Pair(i, j));
		//cout << "pair: " << i << ", " << j << endl;
		i = j + 1;
	}
	for(int p = 0; p < pairs.size(); ++p) {
		if(pairs[p].j - pairs[p].i < 1)
			continue;
		string nw = w.substr(0, pairs[p].i) + w.substr(pairs[p].j + 1);
		if(canEmpty(nw)) {
			domap[w] = true;
			return true;
		}
	}
	return false;
}


int main(int argc, char **argv) {
	domap[""] = true;

	int kases;
	cin >> kases;
	for(int k = 0; k < kases; ++k) {
		string w;
		cin >> w;
		if(canEmpty(w))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}
