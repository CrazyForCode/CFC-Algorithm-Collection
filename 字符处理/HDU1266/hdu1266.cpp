# include <iostream>
using namespace std;


int findStringEndPosition(char * c) {
	int postion = 0;
	while (*(c+postion) != '\0') {
		postion++;
	}
	return postion;
}

void reverseStringBetween(char * c, int left, int right) {
	if (left > right) {
		return;
	}
	char temp;
	int i;
	int halfLength = (right-left+1) / 2;
	for (i = 0; i < halfLength; ++i) {
		temp = c[left+i];
		c[left+i] = c[right-i];
		c[right-i] = temp;
	}

}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	// 包含符号位
	char numberString[33];
	while(n--) {
		cin >> numberString;
		int startPosition = 0;
		int endPosition = 0;

		if (*numberString == '-') {
			startPosition = 1;
		}

		endPosition = findStringEndPosition(numberString);
		while (*(numberString+endPosition-1) == '0') {
			endPosition--;
		}
		endPosition--;
		// cout << startPosition << endl;
		// cout << endPosition << endl;
		// cout << numberString << endl;
		reverseStringBetween(numberString, startPosition, endPosition);
		cout << numberString << endl;
	}
	return 0;
}

