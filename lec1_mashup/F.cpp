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
	ll n, k, x;
	cin >> n >> k >> x;
	vector<ll> A(n);

	rep(i,0,n) cin >> A[i];

	sort(A.begin(), A.end());
	vector<ll> D(n-1);
	rep(i,0,n-1) D[i] = A[i+1] - A[i];
	sort(D.begin(), D.end());

	// rep(i,0,n-1) cout << D[i] << " ";
	// cout << endl;

	int i = 0;
	for (i=0; i<n-1 && k >= 0; i++) {
		if (D[i] > x) {
			k -= ((D[i]-1)/x);
			if (k < 0) break;
		}
	}

	cout << n-i << endl;
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