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
	int n, q;
	cin >> n >> q;
	vi A(n);
	rep(i,0,n) cin >> A[i];
	sort(A.begin(), A.end());

	rep(i,0,q) {
		int query;
		cin >> query;
		if (query > A[n-1]) {
			cout << "POSITIVE" << endl;
			continue;
		}
		else if (query < A[0]) {
			if (n%2 == 0) cout << "POSITIVE" << endl;
			else cout << "NEGATIVE" << endl;
			continue;
		}
		int l = 0;
		int h = n-1;
		int m;
		while (l <= h) {
			m = (l+h)/2;
			//cout << "m is " << m << endl;
			if (m >= n-1) break;
			if (A[m] <= query && A[m+1] >= query) {
				int np = n-m-1;
				if (A[m] == query || A[m+1] == query) cout << "0" << endl;
				else if (np%2 == 0) cout << "POSITIVE" << endl;
				else cout << "NEGATIVE" << endl;
				break;
			}
			else if (A[m] < query && A[m+1] < query) {
				l = m+1;
			}
			else if (A[m] > query && A[m+1] > query) {
				h = m-1;
			}
		}
	}
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}