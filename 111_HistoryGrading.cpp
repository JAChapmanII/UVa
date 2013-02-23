#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> list;
map<int, int> places;

vector<unsigned> after;

bool isAfter(int i, int j) {
	return after[i] & (0x1 << j);
}

int score(int min = -1, int start = 0) {
	if(start >= list.size())
		return 0;
	int s = 0;
	for(int i = start; i < list.size(); ++i)
		if(isAfter(list[i], min))
			s = max(s, 1 + score(list[i], i + 1));
	return s;
}

int main(int argc, char **argv) {
	int count;
	cin >> count;
	for(int i = 0; i < count; ++i) {
		int n;
		// i-th is in n-th place
		cin >> n;
		places[n] = (i + 1);
	}
	for(int i = 1; i <= count; ++i)
		after.push_back(0x0);
	for(int i = 1; i <= count; ++i) {
		unsigned as = 0x0;
		for(int j = 1; j < i; ++j)
			as |= (0x1 << places[j]);
		after[places[i]] = as;
	}

	while(!cin.eof() && cin.good()) {
		list.clear();
		for(int i = 0; i < count; ++i)
			list.push_back(-1);
		for(int i = 0; i < count; ++i) {
			int n;
			cin >> n;
			if(!cin.good())
				return 0;
			list[n - 1] = (i + 1);
		}
		int s = 0;
		for(int i = 0; i < count; ++i)
			s = max(s, 1 + score(list[i], i + 1));
		cout << s << endl;
	}
	return 0;
}

