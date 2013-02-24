#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

string toLower(string str) {
	string res;
	res.reserve(str.length());
	for(int i = 0; i < str.length(); ++i)
		res += (tolower(str[i]));
	return res;
}

string sort(string str) {
	vector<char> w;
	for(int i = 0; i < str.length(); ++i)
		w.push_back(str[i]);
	sort(w.begin(), w.end());
	string s;
	s.reserve(str.length());
	for(int i = 0; i < w.size(); ++i)
		s += w[i];
	return s;
}

int main(int argc, char **argv) {
	string line;
	getline(cin, line);

	vector<string> words;
	map<string, string> wmap;
	map<string, long> count;

	while(line != (string)"#") {
		stringstream ss(line);
		string word;
		while(ss >> word) {
			string l = toLower(word);
			words.push_back(l);
			wmap[l] = word;
			count[sort(l)]++;
		}
		getline(cin, line);
	}

	vector<string> lwords;
	for(int i = 0; i < words.size(); ++i)
		if(count[sort(words[i])] == 1)
			lwords.push_back(words[i]);

	vector<string> res;
	for(int i = 0; i < lwords.size(); ++i)
		res.push_back(wmap[lwords[i]]);

	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}

