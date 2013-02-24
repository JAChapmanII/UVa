#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Place {
	int i, j;
	Place(int ii, int ij) : i(ii), j(ij) { }
	Place(string p) {
		i = p[0] - 'a';
		j = p[1] - '1';
	}
	bool valid() {
		if(i < 0 || i >= 8)
			return false;
		if(j < 0 || j >= 8)
			return false;
		return true;
	}
};
struct Board {
	int dist[8][8];
	Board() {
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				dist[i][j] = 999;
	}
	void compute(int i, int j) {
		dist[i][j] = 0;
		vector<Place> q;
		q.push_back(Place(i, j));

		bool v[8][8];
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				v[i][j] = false;

		while(!q.empty()) {
			Place h = q.front();
			q.erase(q.begin());
			if(!h.valid())
				continue;
			if(v[h.i][h.j])
				continue;
			v[h.i][h.j] = true;


			if(Place(h.i - 2, h.j - 1).valid())
				dist[h.i - 2][h.j - 1] = min(dist[h.i - 2][h.j - 1], dist[h.i][h.j] + 1);

			if(Place(h.i - 2, h.j + 1).valid())
				dist[h.i - 2][h.j + 1] = min(dist[h.i - 2][h.j + 1], dist[h.i][h.j] + 1);

			if(Place(h.i + 2, h.j - 1).valid())
				dist[h.i + 2][h.j - 1] = min(dist[h.i + 2][h.j - 1], dist[h.i][h.j] + 1);

			if(Place(h.i + 2, h.j + 1).valid())
				dist[h.i + 2][h.j + 1] = min(dist[h.i + 2][h.j + 1], dist[h.i][h.j] + 1);

			if(Place(h.i - 1, h.j - 2).valid())
				dist[h.i - 1][h.j - 2] = min(dist[h.i - 1][h.j - 2], dist[h.i][h.j] + 1);

			if(Place(h.i + 1, h.j - 2).valid())
				dist[h.i + 1][h.j - 2] = min(dist[h.i + 1][h.j - 2], dist[h.i][h.j] + 1);

			if(Place(h.i - 1, h.j + 2).valid())
				dist[h.i - 1][h.j + 2] = min(dist[h.i - 1][h.j + 2], dist[h.i][h.j] + 1);

			if(Place(h.i + 1, h.j + 2).valid())
				dist[h.i + 1][h.j + 2] = min(dist[h.i + 1][h.j + 2], dist[h.i][h.j] + 1);

			q.push_back(Place(h.i - 2, h.j - 1));
			q.push_back(Place(h.i - 2, h.j + 1));
			q.push_back(Place(h.i + 2, h.j - 1));
			q.push_back(Place(h.i + 2, h.j + 1));
			q.push_back(Place(h.i - 1, h.j - 2));
			q.push_back(Place(h.i + 1, h.j - 2));
			q.push_back(Place(h.i - 1, h.j + 2));
			q.push_back(Place(h.i + 1, h.j + 2));
		}
	}
};


int main(int argc, char **argv) {
	Board boards[8][8];
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			boards[i][j].compute(i, j);

	string from, to;
	cin >> from;
	while(!cin.eof() && cin.good()) {
		cin >> to;

		Place fp(from), tp(to);
		cout << "To get from " << from << " to " << to << " takes "
			<< boards[fp.i][fp.j].dist[tp.i][tp.j] << " knight moves." << endl;

		cin >> from;
	}
	return 0;
}

