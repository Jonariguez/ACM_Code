#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int bit[maxn][maxn],n;

void add(int i,int j,int v){
    while(i<=n){
        int temp=j;
        while(temp<=n){
            bit[i][temp]+=v;
            temp+=temp&(-temp);
        }
        i+=i&(-i);
    }
}

int sum(int i,int j){
    int res=0;
    while(i>0){
        int temp=j;
        while(temp>0){
            res+=bit[i][temp];
            temp-=temp&(-temp);
        }
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,T,m;
    int x,y,x1,y1,x2,y2;
    char s[3];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(bit,0,sizeof(bit));
        while(m--){
            scanf("%s",s);
            if(s[0]=='Q'){
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(x,y)%2);
            }
            else if(s[0]=='C'){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x2+1,y1,-1);
                add(x1,y2+1,-1);
                add(x2+1,y2+1,1);
            }
        }
        if(T)
            printf("\n");
    }
    return 0;
}
