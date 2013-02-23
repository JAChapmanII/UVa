#include <iostream>
#include <vector>
using namespace std;

enum Color { C_BLUE, C_RED, C_UNDEF };

bool ok(Color here, Color there) {
	if(there == C_UNDEF)
		return true;
	if(here != there)
		return true;
	return false;
}
Color invert(Color here) {
	switch(here) {
		case C_BLUE: return C_RED;
		case C_RED: return C_BLUE;
	}
	cerr << "oh poop" << endl;
}

struct Node {
	bool visited;
	Color color;
	vector<int> ns;

	Node() : visited(false), color(C_UNDEF), ns() { }
};

int main(int argc, char **argv) {
	int nodeCount;
	cin >> nodeCount;
	while(nodeCount != 0) {
		int edgeCount;
		cin >> edgeCount;
		int first, second;

		vector<Node> nodes;
		for(int i = 0; i < nodeCount; ++i)
			nodes.push_back(Node());

		for(int i = 0; i < edgeCount; ++i) {
			cin >> first;
			cin >> second;
			nodes[first].ns.push_back(second);
			nodes[second].ns.push_back(first);
		}

		vector<int> q;
		q.push_back(0);
		nodes[0].color = C_BLUE;
		bool canColor = true;
		while(!q.empty() && canColor) {
			int n = q[0];
			q.erase(q.begin());
			if(nodes[n].visited)
				continue;
			nodes[n].visited = true;
			for(int i = 0; i < nodes[n].ns.size(); ++i) {
				int m = nodes[n].ns[i];
				if(ok(nodes[n].color, nodes[m].color)) {
					nodes[m].color = invert(nodes[n].color);
					q.push_back(m);
				} else {
					canColor = false;
					break;
				}
			}
			if(!canColor)
				break;
		}

		if(canColor)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;

		cin >> nodeCount;
	}
	return 0;
}

