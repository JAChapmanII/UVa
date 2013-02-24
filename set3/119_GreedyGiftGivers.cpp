#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node {
	string name;
	int toPay;
	int toRecieve;
	vector<string> payTo;
	Node() : name(), toPay(0), toRecieve(0), payTo() { }
};


int main(int argc, char **argv) {
	int pCount;
	cin >> pCount;
	bool first = true;
	while(!cin.eof() && cin.good()) {
		vector<string> names;
		map<string, Node> ps;
		for(int i = 0; i < pCount; ++i) {
			string l;
			cin >> l;
			names.push_back(l);
		}

		for(int i = 0; i < pCount; ++i) {
			string l;
			cin >> l;

			ps[l].name = l;
			cin >> ps[l].toPay;
			int n;
			cin >> n;
			for(int j = 0; j < n; ++j) {
				string to;
				cin >> to;
				ps[l].payTo.push_back(to);
			}
		}
		for(int i = 0; i < pCount; ++i) {
			string here = names[i];
			if(ps[here].payTo.size() > 0) {
				int toEach = ps[here].toPay / ps[here].payTo.size();
				for(int j = 0; j < ps[here].payTo.size(); ++j)
					ps[ps[here].payTo[j]].toRecieve += toEach;
			}
		}

		if(!first)
			cout << endl;
		else
			first = false;


		for(int i = 0; i < pCount; ++i) {
			string here = names[i];
			int left = ps[here].toPay;
			if(ps[here].payTo.size() > 0)
				left = ps[here].toPay % ps[here].payTo.size();
			//cout << "ps.toRecieve: " << ps[here].toRecieve << endl;
			cout << here << " " << -(ps[here].toPay - ps[here].toRecieve - left)
				<< endl;
		}

		cin >> pCount;
	}
	return 0;
}

