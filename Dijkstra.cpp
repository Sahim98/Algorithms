#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
using ld = long double;
using ll = long long;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define br cout<<'\n'; 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL
#define lcm(a, b) a /__gcd(a, b)*b
#define digit(n) floor(log10(n))+1
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define case(x) cout<< "Case "<<x<< ": ";
#define ver(expression) cout << (expression ? "YES\n" : "NO\n")
#define fast {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define prec(precision,value) cout<<fixed<<setprecision(precision)<<value<<endl
 

#define bug(args...) do {cerr << #args << " : "; dbg(args); } while(0)
void dbg () {cerr << endl;}
template <typename T>
void dbg( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>
void dbg( T arg, const hello &... rest) {cerr << arg << ' '; dbg(rest...);}
 
 
 
template <typename T>ostream& operator<<(ostream& os, const vector<T>& v){
os << "[";for (int i = 0; i < v.size(); ++i) {os << v[i];
if (i != v.size() - 1)os << ", ";}os << "]\n";return os;}
 
template <typename T>ostream& operator<<(ostream& os, const set<T>& v){
os << "[";for (auto it : v) {os << it;if (it != *v.rbegin())os << ", ";}
os << "]\n";return os;}
 


int main(){
    fast
    int n , m; 
    cin >> n >> m ;
    vector<pair<int,int>> edge[n+1] ;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w ; 

        cin >> u >> v >> w ;

        edge[u].pb({v,w}) ;
        edge[v].pb({u,w}) ;
    }

    int source ; 

    cin >> source ; 

    vector<int>dis(n+1,inf) ; 

    set<pair<int,int>> s ; 

    dis[source] = 0 ;

    s.insert({0,source}) ;

    while(!s.empty())
    {
        auto x = *(s.begin()) ; 

        s.erase(x) ;

        for(auto i : edge[x.second])//i = edge,weight
        {
            if(dis[i.first] > dis[x.second]+i.second)
            {
                s.erase({dis[i.first],i.first}) ; 
                dis[i.first] = dis[x.second] + i.second ;
                s.insert({dis[i.first],i.first}) ;
            }
        }
    }
    
    cout << "Weight of the node 1.....n:\n" ; 

    for(int i = 1 ; i <= n ; i++) cout << dis[i] << ' ' ;
    
    br       
}

