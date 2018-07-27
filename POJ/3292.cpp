#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef __int64 ll;

const int maxh=1000001;

ll p[100000],r[260000],tot,cnt;
bool is[maxh+10];
ll ans[maxh+10];

void pre_solve(){
	ll i,j,k;
	tot=0;
	for(i=1;i<=maxh;i+=4)
		r[tot++]=i;
	memset(is,0,sizeof(is));
	k=1;
	for(i=5;i<=maxh;i+=4){
		if(!is[i]){
			if(i*i>maxh) continue;
			for(j=k;j<tot && i*r[j]<=maxh;j++)
				is[i*r[j]]=1;
		}
		k++;
	}
	cnt=0;
	for(i=1;i<tot;i++)
		if(!is[r[i]])
			p[cnt++]=r[i];
	memset(is,0,sizeof(is));
		for(i=0;i<cnt;i++){
			if(p[i]*p[i]>maxh) break;
			for(j=i;p[j]*p[i]<=maxh;j++)
				is[p[j]*p[i]]=1;
		}
	ll count=0;
	for(i=1;i<=maxh;i++){
		if(is[i])
			count++;
		ans[i]=count;
	}

}

int main()
{
	ll i,t,h;
	pre_solve();
	while(scanf("%I64d",&h),h){
		printf("%I64d %d\n",h,ans[h]);
		/*
		ans=0;
		for(i=0;i<cnt;i++){
			if(p[i]*p[i]>h) break;
			t=upper_bound(p+i,p+cnt,h/p[i])-(p+i);
			ans+=t;
		}
		printf("%I64d\n",ans);*/
	}






	return 0;
}