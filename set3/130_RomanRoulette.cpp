#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	int n, k;
	cin >> n;
	cin >> k;
	while(!(n == 0 && k == 0)) {
		int startAt = 2;
		for(startAt = 0; startAt <= n; ++startAt) {
			vector<int> left;
			for(int i = 0; i < n; ++i)
				left.push_back(i + 1);

			int t = startAt - 1;
			while(left.size() > 1) {
				t = (t + k) % left.size();
				int target = t;

				int replace = t;
				for(int z = 0; z < k; ++z) {
					replace = (replace + 1) % left.size();
					if(replace == target)
						replace = (replace + 1) % left.size();
				}

				left[target] = left[replace];
				left.erase(left.begin() + replace);
				if(replace < target)
					t--;
			}
			if(left[0] == 1) {
				break;
			}
		}

		cout << (startAt + 1) << endl;

		cin >> n;
		cin >> k;
	}
	return 0;
}

