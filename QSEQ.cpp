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
#define maxn 2000006
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "QSEQ"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
int dd[maxn];
int a[maxn];
ll pos[maxn];
int x, y, m;
ll l, r;
ll bef;
int q;
int sol(ll x)
{
    if (x <= r) return a[x];
    ll s = (x - bef) % (r - l + 1ll);
    if (s == 0) return a[r];
    return a[bef + s];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> a[0] >> x >> y >> m >> q;
    dd[a[0]] = 1;

    for (int i = 1; i <= m; i ++)
    {
        a[i] = (a[i - 1] * x + y) % m;
        if (!dd[a[i]])
        {
            pos[a[i]] = 1ll * i;
            dd[a[i]] = 1;
        }
        else {
            l = pos[a[i]] ;
            r = 1ll * i - 1ll;
            break;
        }
    }
    bef = l - 1;
    while(q --)
    {
        ll x; cin >> x;
        cout << sol(x) << " ";
    }
}
