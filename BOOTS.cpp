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
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "BOOTS"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
struct data1{
    int pos, dep;
};
struct data2{
    int pos, dep, dis;
};
bool cmp1(data1 a, data1 b)
{
    return a.dep < b.dep;
}
bool cmp2(data2 a, data2 b)
{
    return a.dep < b.dep;
}
data1 vtr[maxn];
data2 bts[maxn];
int n;
int m;
int pre[maxn], nxt[maxn];
bool res[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> vtr[i].dep;
        vtr[i].pos = i;
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    for (int i = 1; i <= m; i ++)
    {
        cin >> bts[i].dep >> bts[i].dis;
        bts[i].pos = i;
    }
    sort(vtr + 1, vtr + n + 1, cmp1);
    sort(bts + 1, bts + m + 1, cmp2);
    int dist = 1;
    int j = n;
    for (int i = m; i ; i --)
    {
        int pos = bts[i].pos;
        while(j >= 1 && vtr[j].dep > bts[i].dep)
        {
            int c = vtr[j].pos;
            nxt[pre[c]] = nxt[c];
            pre[nxt[c]] = pre[c];
            dist = max(dist, nxt[c] - pre[c]);
            j --;
        }
        res[pos] = (dist <= bts[i].dis);
    }
   for (int i = 1; i <= m; i ++) cout << res[i] << "\n";
}

