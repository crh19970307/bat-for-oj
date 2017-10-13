#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100008;
int N;
int a[maxn];
void old()
{
	int cnt[3]={0};
 	int time[3]={0};
 	int waittime=0;
 	for(int i=0;i<N;++i)
 	{
 		cnt[i%3]++;
 	}
 	for(int i=0;i<3;++i)
 	{
 		for(int j=0;j<cnt[i];j++)
 		{
 			waittime+=a[3*j+i]*(cnt[i]-j-1);
 			time[i]+=a[3*j+i];
 		}
 	}
 	sort(time,time+3,greater<int>());
 	cout<<waittime<<' '<<max(max(time[0],time[1]),time[2])<<endl;
 	return;
}
void neww()
{
	int resttime[3]={0};
	resttime[0]=a[0];
	resttime[1]=a[1];
	resttime[2]=a[2];
	int time=0;
	int waittime=0;

	for(int i=3;i<N;++i)
 	{
 		int gap=min(min(resttime[0],resttime[1]),resttime[2]);
 		// cout<<gap;
 		waittime+=(N-i)*gap;
 		time+=gap;
 		for(int j=0;j<3;++j)
 			resttime[j]-=gap;

 		for(int j=0;j<3;++j)
 			if(resttime[j]==0)
 			{
 				resttime[j]+=a[i];
 				break;
 			}
 	}
/* 	for(int i=0;i<3;++i)
 		cout<<resttime[i]<<endl;*/

 	time+=max(max(resttime[0],resttime[1]),resttime[2]);
 	cout<<waittime<<' '<<time<<endl;
}

int main()
 {
 	cin>>N;
 	for(int i=0;i<N;++i)
 		cin>>a[i];
 	
 	old();
 	neww();

 	
 	return 0;


 }