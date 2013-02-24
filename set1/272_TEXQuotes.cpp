#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	string line;
	bool state = true;
	bool first = true;
	while(!cin.eof() && cin.good()) {
		if(!first)
			cout << endl;
		else
			first = false;
		getline(cin, line);
		string alt;
		alt.reserve(line.length());
		for(int i = 0; i < line.length(); ++i)
			switch(line[i]) {
				case '"':
					alt += state ? "``" : "''";
					state = !state;
					break;
				default:
					alt += line[i];
			}
		cout << alt;
	}
	return 0;
}

