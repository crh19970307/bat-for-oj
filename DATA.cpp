/**
* 添加产生随机数据的文件
* add solution which you get DATA
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include<iostream>
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
    for(int i=0;i<100;++i)
        rand();
    int N=R(0,100000);
    cout<<N<<endl;
    for(int i=0;i<N;++i)
        cout<<R(0,1000)<<' ';
        // R(1,100);
    //system("pause");
    return 0;
}