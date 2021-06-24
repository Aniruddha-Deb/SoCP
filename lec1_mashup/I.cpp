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

int minimize(vector<pi> &A, int i, ll csum, ll expsum) {
	if (csum >= expsum) return 0;
	if (i >= A.size()) return -1;
	else {
		vi costs;
		for (int j=i; j<A.size(); j++) {
			costs.push_back(minimize(A,i+1,csum-A[i].first,expsum));
		}
		return A[i].second + minimize(A,i+1,csum-A[i].first, expsum);
	}
}

void solve() {
	// code here
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