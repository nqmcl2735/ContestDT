//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll, ll>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 1000005
#define MOD
#define Task "FRIENDS"
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, q;
vii ke[maxn];
ll h[maxn];
ll d[maxn];
const ll lg = 20;
ll SpT[lg][maxn];
void Init(){
    cin >> n;
    for(ll i = 1; i < n; i ++){
        ll v, w;
        cin >> v >> w;
        ke[i + 1].PB({v, w});
        ke[v].PB({i + 1, w});
    }
}

void DFS(ll u){
    for(pii x : ke[u]){
        ll v = x.F;
        ll w = x.S;
        if(v == SpT[0][u]) continue;
        d[v] = d[u] + w;
        h[v] = h[u] + 1;
        SpT[0][v] = u;
        for(ll i = 1; i < lg; i++) SpT[i][v] = SpT[i-1][SpT[i-1][v]];
        DFS(v);
    }
}

ll lca(ll u, ll v){
    if(h[u] < h[v]) swap(u, v);
    ll k = h[u] - h[v];
    for(ll i = lg - 1; i >= 0; i--){
        if(k & (1 << i)) u = SpT[i][u];
    }
    if(u == v) return u;
    for(ll i = lg - 1; i >= 0; i--){
        if(SpT[i][u] != SpT[i][v]){
            u = SpT[i][u];
            v = SpT[i][v];
        }
    }
    return SpT[0][u];
}

void Sol(){
    DFS(1);
    cin >> q;
    while(q --){
        ll u, v, w;
        cin >> u >> v;
        cin >> w;
        ll dis = min(d[u] + d[v] - 2 * d[lca(u, v)], w);
        ll res = min(d[u] + dis, d[v] + dis + w);
        cout << res << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
    Init();
    Sol();
}
