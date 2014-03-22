
#include <iostream>
#include <vector>

using namespace std;

/***********************************************************/
/* Program used erathosthenes sieve algo to precalculate   */
/* first 15000 prime numbers.                              */
/***********************************************************/

bool is_prime(int num) {
	for(int i = 3; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void primes(vector<int>& a) {
	int temp[163842];
	for (int i = 0; i <= 163841; i++) {
		temp[i] = i;
	}
	for (int i = 2; i <= 163841; i++) {
		if (temp[i] != -1) {
			a.push_back(i);
			for (int j = 2*i; j <= 163841; j+=i)
				temp[j] = -1;
		}
	}
}

int main() {
	int n, k;
	vector<int> a;
	primes(a);
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> n;
		cout << a[n-1] << endl;
	}
	return 0;
}
