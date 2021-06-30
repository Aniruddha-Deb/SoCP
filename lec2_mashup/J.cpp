#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool lower_precedence(char c, char o) {
	if (c == '(' || c == ')' || o == '(' || o == ')') return false;
	string p = "+-*/^";
	return p.find(c) < p.find(o);
}

void solve() {
	string s;
	cin >> s;
	vector<char> rpn;
	stack<char> op;

	for (int i=0; i<s.length(); i++) {
		char c = s[i];
		if (!op.empty() && (lower_precedence(c, op.top()) || c == ')')) {
			while (!op.empty() && op.top() != '(') {
				char o = op.top();
				rpn.push_back(o);
				op.pop();
			}
			if (!op.empty() && op.top() == '(') {
				op.pop();
			}
		}
		if (isalpha(c)) {
			rpn.push_back(c);
		}
		else if (c != ')'){
			op.push(c);
		}
	}
	while (!op.empty()) {
		char o = op.top();
		rpn.push_back(o);
		op.pop();
	}


	for (char c : rpn) cout << c;
	cout << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}