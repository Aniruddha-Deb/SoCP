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

struct Comp{
    bool operator()(pi& a, pi& b) {
        return a.second < b.second;
    }
};

void solve() {
	int n;
	cin >> n;
	priority_queue<pi,vector<pi>,Comp> Q;
	map<int,int> freq;
	rep(i,0,n) {
		int temp;
		cin >> temp;
		freq[temp] += 1;
	}
	for (auto p : freq) {
		Q.push(p);
	}
	int size = n;
	while (Q.size() >= 2) {
		// get 2 largest frequency elements and subtract 1 from each
		pi p1 = Q.top();
		Q.pop();
		pi p2 = Q.top();
		Q.pop();
		p1.second--;
		p2.second--;
		size -= 2;
		if (p1.second) Q.push(p1);
		if (p2.second) Q.push(p2);
	}

	cout << size << endl;
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