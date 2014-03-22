#include <iostream>
#include <cmath>
using namespace std;

/***********************************/
/*     Lagrange square theorem	   */
/***********************************/

int main() {
	int quadrics;
	cin >> quadrics;
	
	int certificates = 0;

	if (quadrics == 0) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i*i <= quadrics; i++) {
		if (i*i == quadrics) {
			cout << 1;
			return 0;
		}
	}

	for(int i = 0; i*i <= quadrics; i++) {
		for(int j = 0; j*j < quadrics; j++) {
			if (i*i + j*j == quadrics) {
				cout << 2;
				return 0;
			}
		}
	}

	for(int i = 0; i*i <= quadrics; i++) {
		for(int j = 0; j*j < quadrics; j++) {
			for(int k = 0; k*k < quadrics; k++) {
				if (i*i + j*j + k*k == quadrics) {
					cout << 3;
					return 0;
				}
			}
		}
	}

	cout << 4;
	return 0;
}