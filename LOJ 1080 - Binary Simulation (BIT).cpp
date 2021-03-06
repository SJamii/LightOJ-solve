//LOJ 1080 - Binary Simulation (BIT)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define pb push_back

long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... anst)
{
    print(first);
    print(anst ...) ;
}

/*direction array*/

/***4 moves***/
/*
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
*/
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/

/*direction array ends*/

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

int ara[Max];
int tree[Max];
int n;
char s[Max];

void update(int idx, int val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx = idx + (idx & -idx);
    }
}

//start = 1
int query(int idx)
{
    int sum = 0;

    while(idx > 0)
    {
        sum += tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int k=1; k<=t; k++)
    {
        printf("Case %d:\n", k);
        scanf("%s", s);
        n = strlen(s);

        memset(tree, 0, sizeof(tree));
        int q;
        scanf("%d", &q);

        while(q--)
        {
            getchar();

            char ch;
            scanf("%c", &ch);

            if(ch=='I')
            {
                int x, y;
                scanf("%d %d", &x, &y);
                update(x, 1);
                update(y+1, -1);
            }
            else
            {
                int ind;
                scanf("%d", &ind);

                int val = query(ind);

                if(val % 2 == 0)
                    printf("%c\n", s[ind-1]);
                else
                {
                    if(s[ind-1] == '0')
                        printf("1\n");
                    else
                        printf("0\n");
                }
            }
        }
    }
    return 0;
}
