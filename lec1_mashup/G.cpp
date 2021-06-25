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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pi> A;
	vector<vi> ans(n,vi(m,0));
	for (int i=0; i<n*m; i++) {
		int temp;
		cin >> temp;
		A.push_back({temp,i/m});
	}

	sort(A.begin(), A.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	int pos = 0;
	for (int i=0; i<m; i++) {
		ans[A[i].second][pos++] = A[i].first;
	}

	vi ctrs(n,0);
	for (int i=m; i<n*m; i++) {
		while (ctrs[A[i].second] < m && ans[A[i].second][ctrs[A[i].second]] != 0) ctrs[A[i].second]++;
		ans[A[i].second][ctrs[A[i].second]] = A[i].first;
	}
	
	for (auto v : ans) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
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