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
	vi A(n);
	vi B(m);
	ll Asum = 0;
	ll Bsum = 0;
	rep(i,0,n) {
		cin >> A[i];
		Asum += A[i];
	}
	rep(i,0,m) {
		cin >> B[i];
		Bsum += B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	if (Asum > Bsum) {
		cout << 0 << endl; 
		return;
	}

	int i,j;
	for (i=0,j=m-1; i<n && j>=0 && Asum <= Bsum; i++,j--) {
		Asum = Asum - A[i] + B[j];
		Bsum = Bsum + A[i] - B[j];
	}

	if (Asum <= Bsum) cout << "-1" << endl;
	else cout << i << endl;
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