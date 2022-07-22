/// Given array a find the maximum sum s which is sum of elements of k length subsegment of array a.
/// Solution in O(n).

#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100 + 8;

int a[N];


int main()
{
    int n, k, ans = 0;
  
    cin >> n >> k;

    for ( int i = 1; i <= n; i++ ) cin >> a[i];

    int l = 1, r = k;

    for ( int i = 1; i <= k; i++ ) ans += a[i];
    int sum = ans;

    while ( r <= n ) {
        sum -= a[l];
        l++, r++;
        if ( r > n ) break;
        sum += a[r];

        ans = max ( ans, sum );
    }

    cout << ans << endl;
}
