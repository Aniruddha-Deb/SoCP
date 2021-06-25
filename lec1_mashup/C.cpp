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
	int n, c;
	cin >> n >> c;
	vi A(n);
	rep(i,0,n) cin >> A[i];
	sort(A.begin(), A.end());

	int l=0;
	int h=MOD-7;
	int m;
	int ans = 0;
	while (l <= h) {
		m  = (l+h)/2;

		// check if it's possible to place cows such that minimum distance is m
		int cowpos = A[0];
		int ncows = 1;
		for (int i=1; i<n; i++) {
			if (A[i] - cowpos >= m) {
				ncows++;
				cowpos = A[i];
			}
		}

		if (ncows < c) {
			h = m-1;
		}
		else {
			ans = m;
			l = m+1;
		}
	}

	cout << ans << endl;

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