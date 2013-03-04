#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	string a, b;
	cin >> a;
	while(!cin.eof() && cin.good()) {
		cin >> b;

		map<int, map<int, int> > m;
		for(int i = 0; i <= a.length(); i++)
			m[i][0] = 0;
		for(int i = 0; i <= b.length(); i++)
			m[0][i] = 0;

		for(int i = 1; i <= a.length(); ++i)
			for(int j = 1; j <= b.length(); ++j) {
				if(a[i - 1] == b[j - 1])
					m[i][j] = max(m[i - 1][j - 1] + 1, max(m[i - 1][j], m[i][j - 1]));
				else
					m[i][j] = max(m[i - 1][j], m[i][j - 1]);
			}

		if(m[a.length()][b.length()] == min(a.length(), b.length()))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cin >> a;
	}
}

