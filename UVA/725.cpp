#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int vis[11],a[11],n,flag;

set<int> s;

//�ж�x�Ƿ���5λ��
bool add(int x){
    int cnt=0;
    while(x){
        s.insert(x%10);
        cnt++;
        x/=10;
    }
    return cnt==5;
}

//ֻҪ��֤��ĸ�Ǵ�С����ö�٣���ô����ʽ�Ӿ��Ǵ�С����ģ���������������ֱ���������
void dfs(int cur,int sum){
    if(sum>98765/n) return ;      //�����ʱ��fghij̫���ˣ��Ͳ���ö����
    int i;
    if(cur==5){
        int res;
        s.clear();
        for(i=0;i<5;i++){
            s.insert(a[i]);
        }
        res=n*sum;
        if(!add(res)) return ;
        if(s.size()==10){
            flag=1;
            printf("%d / ",res);
            for(i=0;i<5;i++) printf("%d",a[i]);
            printf(" = %d\n",n);
        }
        return ;
    }
    for(i=0;i<10;i++)
        if(vis[i]==0){
            vis[i]=1;
            a[cur]=i;
            dfs(cur+1,sum*10+i);
            vis[i]=0;
        }
}

int main()
{
    int i,j,k=0,mp[80];
    memset(mp,0,sizeof(mp));
    while(scanf("%d",&n),n){
        if(k++)
            printf("\n");
        flag=0;
        if(mp[n]){      //mp������ǣ����mpΪ1˵��n���޽�ģ��Ż�
            printf("There are no solutions for %d.\n",n);
            continue;
        }
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        if(!flag){
            mp[n]=1;
            printf("There are no solutions for %d.\n",n);
        }
    }
    return 0;
}
