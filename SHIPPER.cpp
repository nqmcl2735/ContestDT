//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define Pi 3.141592653589793238
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "SHIPPER"
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int m;
struct data
{
    int x, y;
    ll t;
};
data ong[maxn];
int a, b;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> ong[i].x >> ong[i].y >> ong[i].t;
    for (int i = 1; i <= m; i ++)
    {
        cin >> a >> b;
        ll res = 1ll * abs(a - b);
        for (int j = 1; j <= n; j ++)
        {
            ll sum = 0;
            sum += 1ll * abs(a - ong[j].x) + ong[j].t + 1ll * abs(b - ong[j].y);
            res = min(res, sum);
        }
        cout << res << "\n";
    }
}
