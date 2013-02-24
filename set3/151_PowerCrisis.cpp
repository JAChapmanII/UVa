#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	int N;
	cin >> N;
	while(N != 0) {
		// 12 = N * m % N
		int m = 1;
		vector<int> left_proto;
		for(int i = 0; i < N; ++i)
			left_proto.push_back(i + 1);
		for(m = 1; m < N + 1; ++m) {
			vector<int> left = left_proto;
			int t = 0;
			while(left.size() > 1) {
				left.erase(left.begin() + t);
				t += (m - 1);
				t %= left.size();
			}
			if(left.front() == 13)
				break;
		}
		cout << m << endl;

		cin >> N;
	}
	return 0;
}

