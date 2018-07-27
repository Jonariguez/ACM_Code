/****************
*PID:449c div1
*Auth:Jonariguez
*****************
�ȴ���3��n/2֮�������x����ôx,2x,3x..tx��t����������ӣ�
���t����������ô�ʹ���t������һ��x��ż����(���Ǹ�ż��)����������
ʣ��ż����������ԡ����t��ż�����ô���ֱ����ԡ�
������֮���ٴ���2����2�ı���+ǰ����������û����Ե�ż������Щ��
������Լ��ɡ�
ע������Ĺ���Ҫʼ�ձ�֤�������ظ��ġ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+5;
int vis[maxn];
vector<int> prime,res,remain;

void table(){
    int i,j;
    vis[1]=1;
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            if((LL)i*i>100000) continue;
            for(j=i*i;j<=100000;j+=i) vis[j]=1;
        }
    }
}

int main()
{
    int i,j,n,m;
    table();
    while(scanf("%d",&n)!=EOF){
        res.clear();remain.clear();
        memset(vis,0,sizeof(vis));
        LL now;
        for(i=1;i<prime.size() && prime[i]<=n/2;i++){
            int cnt=0,f=0;
            for(j=1;j*prime[i]<=n;j++){
                if(vis[j*prime[i]])  continue;
                if(j%2==0 && f==0){
                    remain.push_back(j*prime[i]);f=1;
                    vis[j*prime[i]]=1;
                }else {
                    res.push_back(j*prime[i]);vis[j*prime[i]]=1;
                }
                cnt++;
            }
            if(cnt%2==0){
                if(f){      //���һ����ż����prime[i]�ı�������ô��������������ԣ�����reamin��Ļ���res
                    res.push_back(remain[remain.size()-1]);remain.pop_back();
                }
            }else {
                if(f==0)
                    res.pop_back(); //���һ����������prime[i]�ı������Ҷ�����������ôֻ��ȥ��һ����������ˡ�
            }
        }
        for(i=2;i<=n;i+=2)
            if(vis[i]==0) res.push_back(i);
        for(i=0;i<remain.size();i++)
            res.push_back(remain[i]);
        printf("%d\n",res.size()/2);
        if(res.size()>=2)
            for(i=0;i<res.size()-1;i+=2)
                printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}
