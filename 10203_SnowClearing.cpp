#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
using namespace std;

struct Edge {
	long sx, sy;
	long ex, ey;
	static Edge read(string l) {
		Edge e;
		stringstream ss(l);
		ss >> e.sx;
		ss >> e.sy;

		ss >> e.ex;
		ss >> e.ey;
		return e;
	}
	double d() {
		long dx = ex - sx, dy = ey - sy;
		return sqrt(dx*dx + dy*dy);
	}
	long hours() {
		double dist = d();
		return (dist / 10000);
	}
	double left() {
		double dist = d();
		dist -= ((long)(dist / 10000))*10000;
		return dist;
	}
	string toString() {
		stringstream ss;
		ss << "[" << sx << ", " << sy << "] <-> [" << ex << ", " << ey << "] "
			<< d() << " -- " << hours() << " " << left() << endl;
		return ss.str();
	}
};

int main(int argc, char **argv) {
	int kases;
	string l;
	getline(cin, l);

	stringstream ss(l);
	ss >> kases;
	//cout << "kases: " << kases << endl;

	getline(cin, l);

	bool first = true;
	for(int k = 0; k < kases; ++k) {
		vector<Edge> edges;
		long hours = 0;
		double left = 0;

		// get and ignore location
		getline(cin, l);
		//cout << "loc: " << l << endl;

		getline(cin, l);
		while(!cin.eof() && cin.good() && !l.empty()) {
			//cout << "l: \"" << l << "\"" << endl;
			Edge e = Edge::read(l);
			edges.push_back(e);
			hours += e.hours();
			left += e.left();
			//cout << e.toString() << endl;

			getline(cin, l);
		}
		//cout << "left: " << left << endl;
		long minutes = left * 60 / 10000 + .5;
		while(minutes >= 60)
			hours++, minutes -= 60;
		if(!first)
			cout << endl;
		else
			first = false;
		if(minutes < 10)
			cout << hours << ":0" << minutes << endl;
		else
			cout << hours << ":" << minutes << endl;
	}
	getline(cin, l);
}

