#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	0 poss.push_back("BCG");
	1 poss.push_back("BGC");
	2 poss.push_back("CBG");
	3 poss.push_back("CGB");
	4 poss.push_back("GBC");
	5 poss.push_back("GCB");
	*/
int moves(int b[], int g[], int c[], int type) {
	switch(type) {
		case 0: return (b[1] + b[2]) + (c[0] + c[2]) + (g[0] + g[1]);
		case 1: return (b[1] + b[2]) + (c[0] + c[1]) + (g[0] + g[2]);

		case 2: return (b[0] + b[2]) + (c[1] + c[2]) + (g[0] + g[1]);
		case 3: return (b[0] + b[1]) + (c[1] + c[2]) + (g[0] + g[2]);

		case 4: return (b[0] + b[2]) + (c[0] + c[1]) + (g[1] + g[2]);
		case 5: return (b[0] + b[1]) + (c[0] + c[2]) + (g[1] + g[2]);
	}
	return (1 << 31);
}

int main(int argc, char **argv) {
	vector<string> poss;
	poss.push_back("BCG");
	poss.push_back("BGC");
	poss.push_back("CBG");
	poss.push_back("CGB");
	poss.push_back("GBC");
	poss.push_back("GCB");

	while(!cin.eof() && cin.good()) {
		int b[3], g[3], c[3];
		for(int i = 0; i < 3; ++i) {
			cin >> b[i];
			if(cin.eof() || !cin.good())
				return 0;
			cin >> g[i];
			cin >> c[i];
		}

		int min = moves(b, g, c, 0), minI = 0;
		for(int i = 1; i < poss.size(); ++i) {
			int s = moves(b, g, c, i);
			if(s < min)
				min = s, minI = i;
		}
		cout << poss[minI] << " " << min << endl;
	}

	return 0;
}

