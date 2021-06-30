#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int t;
	cin >> t;
	while (t != 0) {
		vi A(t+2);
		rep(i,1,t+1) cin >> A[i];
		stack<int> S;
		ll ans = 0;
		A[0] = A[t+1] = 0;
		rep(i,0,t+2) {
			while (!S.empty() && A[i] < A[S.top()]) {
				int h = A[S.top()];
				S.pop();
				ll a = (((ll)1)*h)*(i-S.top()-1);
				ans = max(ans,a);
			}
			S.push(i);
		}
		cout << ans << endl;
		cin >> t;
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