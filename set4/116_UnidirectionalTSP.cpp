#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int width, height;
/*
bool before(vector<int> a, vector<int> b) {
	for(int i = 0; i < a.size(); ++i)
		if(a[i] > b[i])
			return false;
	return true;
}
*/
int compare(vector<int> a, vector<int> b) {
	for(int i = 0; i < a.size(); ++i)
		if(a[i] > b[i])
			return 1;
		else if(a[i] < b[i])
			return -1;
	return 0;
}


/*
struct T {
	int r;
	int v;
	T(int a, int b) : r(a), v(b) { }
	bool operator<(const T &rhs) const {
		if(v > rhs.v)
			return false;
		if(r < rhs.r)
			return true;
		return false;
	}
};

vector<int> getPath(map<int, map<int, int> > m, int rs, int cs = width - 2) {
	vector<int> list;

	int r = rs;
	list.insert(list.begin(), r + 1);
	if(cs == -1)
		return list;

	int c = cs;
	vector<T> ts;
	ts.push_back(T(r, m[r][c]));
	ts.push_back(T(((r - 1 + height) % height), m[((r - 1 + height) % height)][c]));
	ts.push_back(T(((r + 1 + height) % height), m[((r + 1 + height) % height)][c]));
	sort(ts.begin(), ts.end());

	vector<int> sub = getPath(m, ts[0].r, cs - 1);
	if(ts[1].v == ts[0].v) {
		vector<int> sub2 = getPath(m, ts[1].r, cs - 1);
		if(before(sub2, sub))
			sub = sub2;
	}
	if(ts[2].v == ts[0].v) {
		vector<int> sub2 = getPath(m, ts[2].r, cs - 1);
		if(before(sub2, sub))
			sub = sub2;
	}

	sub.push_back(r + 1);
	//list.insert(list.begin(), sub.begin(), sub.end());

	return sub;
}
*/

int main(int argc, char **argv) {
	cin >> height;
	cin >> width;

	while(!cin.eof() && cin.good()) {
		map<int, map<int, int> > w;
		for(int r = 0; r < height; ++r)
			for(int c = 0; c < width; ++c) {
				int z;
				cin >> z;
				w[r][c] = z;
			}

		/*
		for(int r = 0; r < height; ++r) {
			for(int c = 0; c < width; ++c) {
				cout << w[r][c] << " ";
			}
			cout << endl;
		}
		*/

		map<int, map<int, int> > m;
		map<int, map<int, vector<int> > > p;
		for(int i = 0; i < height; ++i) {
			vector<int> path;
			path.push_back(i + 1);
			m[i][0] = w[i][0];
			p[i][0] = path;
		}

		int hp1 = height + 1, hm1 = height - 1;
		for(int j = 1; j < width; ++j)
			for(int i = 0; i < height; ++i) {
				int a = (i + hm1) % height, b = i, c = (i + hp1) % height,
					 jm1 = j - 1;

				m[i][j] = m[a][jm1];
				vector<int> path = p[a][jm1];
				//int toAdd = a;

				if(m[b][jm1] < m[i][j]) {
					m[i][j] = m[b][jm1];
					//toAdd = b;
					path = p[b][jm1];
				} else if(m[b][jm1] == m[i][j]) {
					vector<int> tmp = p[b][jm1];
					//int cmp = compare(tmp, path);
					if(before(tmp, path)) {
						m[i][j] = m[b][jm1];
						//toAdd = b;
						path = tmp;
					}
				}

				if(m[c][jm1] < m[i][j]) {
					m[i][j] = m[c][jm1];
					//toAdd = c;
					path = p[c][jm1];
				} else if(m[c][jm1] == m[i][j]) {
					vector<int> tmp = p[c][jm1];
					if(before(tmp, path)) {
						m[i][j] = m[c][jm1];
						//toAdd = c;
						path = tmp;
					}
				}

				m[i][j] += w[i][j];
				path.push_back(i + 1);
				p[i][j] = path;
			}

		/*
		cout << endl;
		for(int r = 0; r < height; ++r) {
			for(int c = 0; c < width; ++c) {
				cout << m[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		int minn = m[0][width - 1], minI = 0;
		vector<int> l = p[0][width - 1 ];
		for(int i = 1; i < height; ++i) {
			if(m[i][width - 1] < minn) {
				minI = i;
				minn = m[i][width - 1];
				l = p[i][width - 1];
			} else if(m[i][width - 1] == minn) {
				vector<int> tmp = p[i][width - 1];
				if(before(tmp, l)) {
					minI = i;
					minn = m[i][width - 1];
					l = p[i][width - 1];
				}
			}
			/*
			if(m[i][width - 1] < minn) {
				minI = i;
				minn = m[i][width - 1];
				l = getPath(m, i);
			} else if(m[i][width - 1] == minn) {
				vector<int> tmp = getPath(m, i);
				if(before(tmp, l)) {
					minI = i;
					minn = m[i][width - 1];
					l = tmp;
				}
			}
			*/
		}
		//cout << "minI: " << minI << endl;

		stringstream ss;
		for(int i = 0; i < l.size(); ++i)
			ss << l[i] << " ";
		string s = ss.str();

		cout << s.substr(0, s.length() - 1) << endl;
		cout << minn << endl;

		cin >> height;
		cin >> width;
	}
}

