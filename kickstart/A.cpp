#include <bits/stdc++.h>
using namespace std;

bool ispat(string s) {
	if (s.length() <= 1) return true;
	else if (s.substr(0,s.length()/2).compare(s.substr(s.length()-s.length()/2, s.length()/2)) == 0 && 
		ispat(s.substr(0,s.length()/2)) && ispat(s.substr(s.length()-s.length()/2, s.length()/2))) {
		return true;
	}
	else return false;
}

int main() {

	int t;
	cin >> t;
	while (t-- > 0) {
		string s;
		cin >> s;
		if (ispat(s)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}