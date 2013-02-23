#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int height, width;
int *board;

#define MINE -7
#define BLANK -8

int isMine(int i, int j) {
	if(i < 0 || i >= height)
		return 0;
	if(j < 0 || j >= width)
		return 0;
	if(board[i * width + j] == MINE)
		return 1;
	return 0;
}
int countAround(int i, int j) {
	return
		isMine(i - 1, j - 1) +
		isMine(i - 1, j - 0) +
		isMine(i - 1, j + 1) +

		isMine(i - 0, j - 1) +
		isMine(i - 0, j - 0) +
		isMine(i - 0, j + 1) +

		isMine(i + 1, j - 1) +
		isMine(i + 1, j - 0) +
		isMine(i + 1, j + 1);
}

int main(int argc, char **argv) {
	cin >> height;
	cin >> width;
	int caseNumber = 1;
	while(height != 0 && width != 0) {
		if(caseNumber > 1)
			cout << endl;
		board = new int[width * height];

		string row;
		for(int i = 0; i < height; ++i) {
			cin >> row;
			for(int j = 0; j < width; ++j)
				board[i * width + j] = (row[j] == '*') ? MINE : BLANK;
		}

		cout << "Field #" << caseNumber << ":" << endl;
		for(int i = 0; i < height; ++i) {
			for(int j = 0; j < width; ++j) {
				if(isMine(i, j) == 0) {
					board[i * width + j] = countAround(i, j);
					cout << (char)(board[i * width + j] + '0');
				} else
					cout << "*";
			}
			cout << endl;
		}


		delete board;
		cin >> height;
		cin >> width;
		caseNumber++;
	}
	return 0;
}

