#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define N 100001

ll min_cost(vector<pair<int,int>> (&G)[N], int root, ll prevsum) {

	//cout << root << endl;
	if (G[root].empty()) return prevsum;

	vector<ll> sums;
	for (auto child : G[root]) {
		sums.push_back(min_cost(G,child.first,prevsum+child.second));
	}
	return *min_element(sums.begin(), sums.end())+prevsum;
}

int main() {
	int t;
	cin >> t;

	while (t-- > 0) {
		int n;
		cin >> n;

		vector<pair<int,int>> G[N];
		for (int i=0; i<n-1; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			G[a].push_back({b,w});
		}

		cout << min_cost(G,1,0) << endl;
	}

	return 0;
}