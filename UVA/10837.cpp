/*
phi[n]=(p1-1)*p1^k1 * (p2-1)*p2^k2 *..* (pa-1)*pa^ka

��֪��n�е�����������p��������phi(n)%(p-1)==0��һ����(#)��
���仰˵���ǣ��ҳ���������phi_n%(p-1)==0��p����ô��p
�������n��
��Ҳ����˵�Ƕ�phi[n](��phi_n)�����ֽ⣬��Ϊki����Ϊ0,
�������ǾͶ�ÿ������p�ж��Ƿ���phi_n%(p-1)==0��������
p�ͼ�¼��f[]�У�������f[]����n��������dfs�����sum����
����f[cur]�أ�������f[cur]-1��
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000000;
bool vis[10005];
vector<int> prime,f;

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=10000;i++)
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=10000;j+=i)
                vis[j]=1;
        }
}

void divide(int phi_n){
    f.clear();              //
    for(int i=0;i<prime.size() && (prime[i]-1)*(prime[i]-1)<=phi_n;i++) //
        if(phi_n%(prime[i]-1)==0)
            f.push_back(prime[i]);
}

bool judge(int n){
    int i;
    for(i=0;i<prime.size() && prime[i]*prime[i]<=n;i++)
        if(n%prime[i]==0) return false;
    for(i=0;i<f.size();i++)
        if(f[i]==n && vis[i]==1) return false;
    return true;
}

/*
����Ԥ�������10000���ڵ�����p����phi_n�ܴ󣬿��ܻ����һ������10000�������ӣ�
�����Ļ�����dfsʱ�����þ����е�f[]ʱ��ʣ�µ�now��Ϊ1�Ļ���˵��ʣ�µ�now����
һ��(p-1)����ʽ,��p=now+1���������Ǽ��p�ǲ���һ����������ǰ��û�ù�����������
������������ǰ��û�ù�����ô�����һ���µ�p������Ҫ������˽����sum��ȥ����n�Ͷ���
������������ǰ���ù��ˣ���Ȼ�ù���Ҳ�����Ѿ�����������(#)Ҫ�󣬾Ͳ�Ҫ�ٶ��һ��p�ˣ�
��Ϊ��ĿҪ��n����С��
�۲����������������˵��ǰ���һϵ�й��춼���У���Ϊǰ��10000���ڵ��������Գ����ˣ�
�����ʣ��ã�˵��������ɣ����ʣ�ˣ�ҲӦ����һ��������Ȼ�������������ȥ����n��
���ǲ��������Ļ����Ǵ��ˣ�return����һ�㡣
*/
int res;

void dfs(int cur,int now,int sum){
    if(cur==f.size()){
        if(now==1) res=min(res,sum);
        else if(judge(now+1)){
            sum*=(now+1);
            res=min(res,sum);
        }
        return ;
    }
    dfs(cur+1,now,sum);
    if(now%(f[cur]-1)) return ;
    vis[cur]=1;
    now/=(f[cur]-1);        //ע����������p-1
    sum*=f[cur];
    dfs(cur+1,now,sum);
    while(now%f[cur]==0){   //��������p
        now/=f[cur];
        sum*=f[cur];        //��Ȼ���ý��n����С����ôΪʲô��Ҫ���ʹ��f[cur]�أ� ��Ϊ����ֻ֪��
        dfs(cur+1,now,sum); //�ڽ���к���f[cur]��������ӣ������弸����֪��������Ҫ��γ��ԣ����ҵ���ȷ
    }                       //�Ľ������Ҳ��dfs��ʹ�÷�����
    vis[cur]=0;         //��Ȼvis���������p�Ƿ��õģ���ô����p����֮ǰ��1������֮���0
}

int main()
{
    int i,j,kcase=1;
    int phi_n;
    prime_table();
    while(scanf("%d",&phi_n),phi_n){
        divide(phi_n);
        res=200000000;
        memset(vis,0,sizeof(vis));
        dfs(0,phi_n,1);
        printf("Case %d: %d %d\n",kcase++,phi_n,res);
    }
    return 0;
}
