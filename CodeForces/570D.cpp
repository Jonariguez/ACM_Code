/****************
*PID:cf570D
*Auth:Jonariguez
*****************
�������жϻ��ģ�����г���1���ַ����ֵĴ�������������ô�Ͳ���
���ɻ��ġ�
dfs��ÿ���ڵ�u����һ����ʼʱ���start[u]�ͽ���ʱ���End[u],
��ô��uΪ�������������нڵ��ʱ�����Χ����(start[u],End[u])�
����ѯ��v,h����ô�жϵ�h����Щ�ڵ�������vΪ�����������أ�
��Ȼ��֪�������������ĳһ���ȫ���ڵ���(�������dep[i]��)��
��ô������ĳ��������Ľڵ���dep[i]�п϶��������ġ��������ǰ���
�����ĵ�h���ȫ���ڵ㰴������(��ʵҲ�ǰ�dfs��Ĵ�С)�����dep[h]
�����У�����dep[h]��dfs���С������ô����Ҫ�����Щ�ڵ����ĳ
����Χ�ڣ������Χ��ʲô�أ�
ѯ��v��h��������dep[h]�в���ֵ��С��(start[v],End[v])��Χ�ڵļ�Ϊ����
���ǻ���Ҫ֪��ÿ���ڵ���ʲô��ĸ���������ǿ��Կ�26��dep����dep[26][maxH];
dep[i][h]��ʾ�ڵ�h������ĸ'a'+i���ֵĿ�ʼʱ�������ô����Щʱ���
��(start[v],End[v])��Χ�ڵĸ��������ˡ�
���⣬�����1��Сʱ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
char str[maxn];
int depth[maxn];
vector<int> son[maxn];
vector<int> dep[26][maxn];
int dfs_seq,start[maxn],End[maxn],maxdeep;

void dfs(int u,int D){
    dep[str[u]-'a'][D].push_back(++dfs_seq);
    maxdeep=max(maxdeep,D);
    start[u]=dfs_seq;
    for(int i=0;i<son[u].size();i++)
        dfs(son[u][i],D+1);
    End[u]=++dfs_seq;
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    depth[1]=1;
    for(i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        son[x].push_back(i);
        depth[i]=depth[x]+1;
    }
    scanf("%s",str+1);
    dfs_seq=0;
    maxdeep=0;
    dfs(1,1);
    while(m--){
        int v,h;
        scanf("%d%d",&v,&h);
        if(h>maxdeep || h<=depth[v]){   //���������ȣ���С��v����ȵõ����ַ������ǿմ�����Ҳ�ǻ���
            printf("Yes\n");
            continue;
        }
        int odd=0;
        for(i=0;i<26;i++){
            int cnt=upper_bound(dep[i][h].begin(),dep[i][h].end(),End[v])-
                    lower_bound(dep[i][h].begin(),dep[i][h].end(),start[v]);
            if(cnt%2){
                odd++;
                if(odd>1) break;
            }
        }
        if(odd>1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
