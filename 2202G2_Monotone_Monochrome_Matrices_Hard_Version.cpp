#include <algorithm>
#include <iostream>
 
using namespace std;
 
const int N = 2000000;
 
int aa[N], bb[N], cc[N], kk[N];
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int n, q; cin >> n >> q;
		int x = 0;
		for (int i = 0; i < n; i++)
			aa[i] = 0;
		for (int j = 0; j < n; j++)
			bb[j] = 0;
		for (int a = 0; a < n; a++)
			cc[a] = 0;
		for (int c = 0; c < n; c++)
			kk[c] = 0;
		while (q--) {
			int i, j; cin >> i >> j, i--, j--;
			if (kk[cc[aa[i]]])
				x--;
			kk[cc[aa[i]]]--;
			if (kk[cc[aa[i]]])
				x++;
			cc[aa[i]]++;
			if (kk[cc[aa[i]]])
				x--;
			kk[cc[aa[i]]]++;
			if (kk[cc[aa[i]]])
				x++;
			aa[i]++;
			if (kk[bb[j]])
				x--;
			kk[bb[j]]++;
			if (kk[bb[j]])
				x++;
			bb[j]++;
			if (kk[bb[j]])
				x--;
			kk[bb[j]]--;
			if (kk[bb[j]])
				x++;
			cout << (!x ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}