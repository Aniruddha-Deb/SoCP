#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {

	int t;
	cin >> t;
	while (t-- > 0) {
		string s;
		cin >> s;

		ll sum = 0;
		int ctr = 0;
		for (int i=0; i<s.length(); i++) {
			if (!isVowel(s[i])) {
				ctr++;
			}
			else {
				sum += ((ll)ctr)*(ctr+1)/2 ;
				ctr = 0;
			}
		}
		sum += ((ll)ctr)*(ctr+1)/2 ;
		cout << ((ll)s.length())*(s.length()+1)/2 - sum << endl;
	}

	return 0;
}