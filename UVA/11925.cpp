/****************
*PID:uva11925
*Auth:Jonariguez
*****************
�Ӻ���ǰȷ��������֪����goal[n]=vǰ��Ӧ����goal[n-1]=p,
��ô��һֱѭ�����������p����ס��(���ͺ���Ļ���Ȼ���ú���
�Ǹ��ŵ���βȥ),Ȼ��ѭ��һֱ����v����ͣ����ô��ʱp����vǰ���ˣ�
Ȼ��pȥ��β��v�ٽ�β��Ȼ����v=p��Ȼ��p=goal[n-2]��������ˡ�
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
        while(st[head]!=goal[1]){       //˳����ˣ���Ҫ�ų�goal�ķ�ʽ
            res.push_back(2);head++;
        }
        for(i=0;i<res.size();i++)
            printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}

