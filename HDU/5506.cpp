/****************
*PID:hdu5506
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int maxn=33;
int n,l;
bitset<330> b[maxn];
bool yes;

void dfs(int cur,bitset<330> *ans){
    if(yes) return ;
    int i;
    if(cur==n){
        for(i=0;i<l;i++)
            if(ans[i].count()==0) break;
        if(i>=l) yes=true;              //�����n�����϶��ŵ�l���������ˣ����Ҹ������ֶ��й������֣���YES
        return ;
    }
    bitset<330> temp[6];
    for(i=0;i<l;i++)
        temp[i]=ans[i];         //��ans���Ƶ�temp��
    for(i=0;i<l;i++){           //��Ŀǰ��cur������b[cur]�����ŷŵ���l��������
        temp[i]=ans[i]&b[cur];  //���ü��Ϻ͵�i��������û�й�������
        if(temp[i].count()!=0)  //�й�������˵�����Էŵ�����ȥ���Ž�ȥ֮������ŵݹ鴦����һ�����ϣ�cur+1
            dfs(cur+1,temp);
        temp[i]=ans[i];         //��������룬��tempҪ���ֺ�ans��ԭ��������Ҫ��ans���Ƶ�temp
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            b[i].reset();
        int k,x;
        for(i=0;i<n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                b[i][x]=1;
            }
        }
        bitset<330> ans[6];
        for(i=0;i<l;i++)
            for(j=1;j<=300;j++)
                ans[i][j]=1;
        yes=false;
        dfs(0,ans);
        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
