#include <iostream>
#include <vector>
#include <map>

/***************************************************************/
/* Biggest prime number in a given range is the least trivial  */
/* number in that range. If we don't find one then we do a     */
/* brute force algorithm on array of all odd numbers in that   */
/* range. Otherwise it is set of single even number which is   */
/* set to be least trivial number.							   */
/* Special case is when number 1 is lower limit. In that case  */
/* no 1 is declared as least trivial.                          */
/***************************************************************/
using namespace std;

void erathostenes_sieve(vector<int>& a) {
	for(int i = 2; i <= a.size()/2; i++) {
		for(int j = 2*i; j < a.size(); j+=i)
			a[j] = -1;
	}
}

double calc_ratio(int num) {
	int sum = 1;

	for(int i = 3; i <= num/2; i+=2) {
		if (num % i == 0)
			sum += i;
	}

	return (double)sum/num;
}

int find_min_trivial(vector<int> &odd) {
	map<int, double> trivials;
	int min_trivial = odd.at(0);
	for(int i = 0; i < odd.size(); i++) {
		double ratio = calc_ratio(odd[i]);
		trivials.insert(pair<int, double>(odd[i], ratio));
		if (trivials.find(min_trivial)->second > ratio) {
			min_trivial = odd[i];
		}
	}
	return min_trivial;
}

int main() {
	int min, max, min_trivial;
	vector<int> a;
	vector<int> odd;
	cin >> min >> max;

	for(int i = 0; i <= max; i++) {
		a.push_back(i);
	}
	erathostenes_sieve(a);

	min_trivial = max;
	int priority = -1;

	if (min == 1) {
		cout << 1;
	}
	else {
		for(int i = max; i >=min; i--) {
			if (a[i] != -1) {
				min_trivial = i;
				priority = 1;
				break;
			}
			else if (i % 2 != 0 && priority <= 0) {
				min_trivial = i;
				odd.push_back(i);
				priority = 0;
			}
			else if (priority == -1) {
				min_trivial = i;
			}
		}
		if (priority == 0)
			cout << find_min_trivial(odd);
		else
			cout << min_trivial;
	}

	return 0;
}