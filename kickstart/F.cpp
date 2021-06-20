#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;

int main() {
	int n, k;
	cin >> n >> k;
	vi A(n);

	ll ans = 1;
	for (int i=0; i<n; i++) cin >> A[i];
	int num = count(A.begin(), A.end(), 1);

	int n1 = 0;
	int n0 = 0;
	for (int i=0; i<n; i++) {
		if (A[i]) {
			if (n0 != 0) {
				n0++;
				ans = ((ans%MOD)*(n0%MOD))%MOD;
				n0 = 0;
			}
			n1++;
		}
		else {
			if (n1%k == 0 && n1 != 0 && n1 != num) {
				n0++;
			}
		}
	}
	if (n0 != 0) {
		n0++;
		ans = ((ans%MOD)*(n0%MOD))%MOD;
		n0 = 0;
	}

	cout << ans << endl;

	return 0;
}