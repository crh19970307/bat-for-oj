/**
* 添加产生随机数据的文件
* add solution which you get DATA
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxn=5+1e5,MOD=7+1e9;
int a[maxn];
//产生 [L,R] 内随机数
int R(int L,int R)
{
	return L + rand()%(R-L+1);
}
int main()
{
    srand(time(0));
    int n = R(1,10);
    int m = R(1,5);
    printf("%d ", n);
    printf("%d\n", m);
    for(int i = 1;i <= n;i ++) a[i] = i;
    random_shuffle(a+1,a+1+n);
    for(int i = 1;i < n;i ++) {
        printf("%d %d\n",a[i],a[i+1]);
    }
    
    while(m --){
        int u = R(1,n), v = R(1,n);
        int tp = R(1,10);
        printf("%d %d %d\n",u,v,tp);
    }
    printf("0 0\n");
    //system("pause");
    return 0;
}