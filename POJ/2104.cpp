#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int B=1000;
const int maxn=100000+10;

int n,m;
int a[maxn],b[maxn];
vector<int> buk[maxn/B];

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
			buk[i/B].push_back(a[i]);
		}
		
		sort(b,b+n);
		for(i=0;i<n/B;i++)
			sort(buk[i].begin(),buk[i].end());
		while(m--){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			int L=-1,R=n-1;
			while(R-L>1){
				int M=(L+R)/2;
				int x=b[M];
				int tl=l-1,tr=r,c=0;	//这里用tl=l，tr=r+1就错。。。。。
				
				
				while(tl<tr && tl%B!=0)
					if(a[tl++]<=x) c++;
				while(tl<tr && tr%B!=0)
					if(a[--tr]<=x) c++;
				while(tl<tr){
					int t=tl/B;
					c+=upper_bound(buk[t].begin(),buk[t].end(),x)-buk[t].begin();
					tl+=B;
				}
				if(c>=k)
					R=M;
				else
					L=M;
			}
			printf("%d\n",b[R]);
		}
	}
	return 0;
}

