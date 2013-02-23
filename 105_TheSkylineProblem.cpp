#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char **argv) {
	// 0 = -.5; 1 = .5; 2 = 1.5; etc
	vector<int> heights(10020, 0);
	int first, height, last;
	int maxRight = 0;
	//int minLeft = 99999;
	while(!cin.eof() && cin.good()) {
		cin >> first;
		cin >> height;
		cin >> last;

		int left, right;
		left = min(first, last);
		right = max(first, last);
		maxRight = max(maxRight, right);
		//minLeft = min(minLeft, left);

		// middle,
		for(int i = left + 1; i <= right; ++i)
			heights[i] = max(heights[i], height);
	}

	int x = 1;
	bool fst = true;
	while(x <= maxRight) {
		// look for up
		while(heights[x + 1] == heights[x]) ++x;
		if(!fst)
			// print height
			cout << heights[x] << " ";
		else
			fst = false;
		// print x loc
		if(heights[x + 1] > heights[x])
			cout << (x + 0) << " ";
		else
			cout << x << " ";
		x++;
	}
	cout << "0" << endl;
	return 0;
}

