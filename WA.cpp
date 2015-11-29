/**
* 添加需要测试的文件程序
* add solution you get WA
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <string>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N=5+1e5,MOD=7+1e9;
int n,m;
int tot,ord,root;
struct edge
{
    int to,next;
}e[2*N];
int head[N],son[N],sz[N],fa[N],dep[N],T[N],top[N];
int ans[N], idx[N];
vector<int> G[N];
void init()
{
    tot = ord = 0;
    root = 1;
    fa[root] = dep[root] = 0;
    memset(son, -1, sizeof(son));
    memset(head, -1, sizeof(head));
    for(int i = 0;i < N;i ++) G[i].clear();
}
void addedge(int u,int v)
{
    e[tot].to = v, e[tot].next = head[u], head[u] = tot++;
}
void dfs(int u)
{
    sz[u] = 1;
    for(int i = head[u];i != -1;i = e[i].next) {
        int v = e[i].to;
        if(v == fa[u]) continue;
        fa[v] = u, dep[v] = dep[u] + 1;
        dfs(v);
        if(son[u] == -1) son[u] = v;
        else if(sz[son[u]] < sz[v]) son[u] = v;
        sz[u] += sz[v];
    }
}
void buildTree(int u,int tp)
{
    T[u] = ++ord, idx[ord] = u, top[u] = tp;
    if(son[u] != -1) {
        buildTree(son[u],top[u]);
    }
    for(int i = head[u];i != -1;i = e[i].next) {
        int v = e[i].to;
        if(v != fa[u] && v != son[u]) {
            buildTree(v,v);
        }
    }
}
void dfs_init()
{
    dfs(root);
    buildTree(root,root);
}
void findIndex(int u,int v,int id)
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(f1,f2), swap(u,v);
        }
        G[T[f1]].PB(id), G[T[u] + 1].PB(-id);
        u = fa[f1], f1 = top[u];
    }
    if(dep[u] > dep[v]) swap(u,v);
    G[T[u]].PB(id), G[T[v] + 1].PB(-id);
}
struct MinV {  
    int id, mx;
}tree[4*N];

void pushup(int rt)  
{
    int ls = rt<<1, rs = rt<<1|1;
    if(tree[rs].mx > tree[ls].mx)  
        tree[rt].id = tree[rs].id;
    else tree[rt].id = tree[ls].id;
    tree[rt].mx = max(tree[ls].mx,tree[rs].mx);  
}

void build(int rt,int L,int R)  
{    
    if(L == R) {  
        tree[rt].id = L;
        tree[rt].mx = 0;  
        return;  
    }
    int mid = (L + R) >> 1;  
    build(rt<<1, L, mid);  
    build(rt<<1|1, mid+1, R);  
    pushup(rt);
}  
void update(int rt, int L, int R, int loc, int x)
{
    if (L == R) {
        tree[rt].mx += x;
        // cout << L << " " << tree[rt].mx << endl;
        return ;
    }
    int mid = (L + R) / 2, ls = rt<<1, rs = rt<<1|1;
    if(loc <= mid) update(ls, L, mid, loc, x);
    else update(rs, mid+1, R, loc, x);
    pushup(rt);
}

int main()
{
    int u,v,id,M;
    while(scanf("%d%d",&n,&m) == 2) {
        if(n == 0 && m == 0) break;
        init();
        for(int i = 1;i < n;i ++) {
            scanf("%d%d",&u,&v);
            addedge(u,v), addedge(v,u);
        }
        dfs_init();
        M = 1;
        while(m --){
            scanf("%d%d%d",&u,&v,&id);
            findIndex(u,v,id);
            M = max(M,id);
        }
        M ++;
        build(1,1,M);
        for(int i = 1;i <= ord;i ++) {
            int dz = G[i].size();
            for(int j = 0;j < dz;j ++) {
                int p = G[i][j];
                if(p > 0) {
                    update(1,1,M,p,1);
                }
                else {
                    update(1,1,M,-p,-1);
                }
            }
            if(tree[1].mx == 0) ans[idx[i]] = 0;
            else ans[idx[i]] = tree[1].id;
        }

        for(int i = 1;i <= n;i ++) {
            printf("%d\n",ans[i]);
        }
    }
    //system("pause");
    return 0;
}