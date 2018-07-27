/****************
*PID:uva11925
*Auth:Jonariguez
*****************
从后往前确定，我们知道，goal[n]=v前面应该是goal[n-1]=p,
那么就一直循环，如果遇见p就留住它(即和后面的换，然后让后面
那个放到结尾去),然后循环一直遇见v，就停，那么此时p就在v前面了，
然后p去结尾，v再结尾。然后令v=p，然后p=goal[n-2]，继续如此。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int st[maxn],goal[maxn];
vector<int> res;

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        int flag=1;
        scanf("%d",&goal[1]);
        for(i=2;i<=n;i++){
            scanf("%d",&goal[i]);
            if(goal[i]-goal[i-1]!=1) flag=0;
        }
        if(n==1 || flag){
            printf("\n");continue;
        }
        res.clear();
        int head=1,tail=1;
        for(i=1;i<=n;i++)
            st[tail++]=i;
        int p,v;
        for(i=n;i>1;i--){
            v=goal[i];
            p=goal[i-1];
            while(true){
                int x=st[head],y=st[head+1];
                if(x==p && y==v){
                    res.push_back(2);res.push_back(2);
                    st[tail++]=x;st[tail++]=y;head+=2;break;
                 //   printf("?\n");
                }
                if(x==p){
                    while(y!=v){
                        res.push_back(1);res.push_back(2);
                        st[tail++]=y;head++;y=st[head+1];
                    }
                    res.push_back(2);res.push_back(2);
                 //   printf("??\n");
                    st[tail++]=x;st[tail++]=y;head+=2;break;
                }else {
                    st[tail++]=x;head++;res.push_back(2);
                  //  printf("???\n");
                }
            }
        }
        while(st[head]!=goal[1]){       //顺序对了，但要排成goal的方式
            res.push_back(2);head++;
        }
        for(i=0;i<res.size();i++)
            printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}

