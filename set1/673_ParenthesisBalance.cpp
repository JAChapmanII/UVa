#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	int caseCount;
	cin >> caseCount;
	cin.ignore(1000, '\n');
	for(int i = 0; i < caseCount; ++i) {
		string ps;
		getline(cin, ps);
		vector<char> stack;
		bool invalid = false;
		for(int j = 0; !invalid && j < ps.length(); ++j) {
			//cout << j << ": " << ps[j] << "   " << stack.size() << endl;
			switch(ps[j]) {
				case '(': case '[': stack.push_back(ps[j]); break;
				case ')':
					if(stack.empty())
						invalid = true;
					else if(stack.back() != '(') 
						invalid = true;
					else
						stack.pop_back();
					break;
				case ']':
					if(stack.empty())
						invalid = true;
					else if(stack.back() != '[') 
						invalid = true;
					else
						stack.pop_back();
					break;
			}
		}
		//cout << "stack.size: " << stack.size() << endl;
		if(invalid || !stack.empty())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}

