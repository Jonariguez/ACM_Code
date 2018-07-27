/****************
*PID:uva1625
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
const int first=0;
const int second=1;
char s[maxn],t[maxn];
int dp[maxn][maxn],vis[2][27],start[27][2],end[27][2],cnt[maxn][maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s,t);
        n=strlen(s);m=strlen(t);
        for(j=0;j<=26;j++){              //ע��startҪ��ʼ�������end������С
            start[j][first]=start[j][second]=maxn;
            end[j][first]=end[j][second]=-1;
        }
        memset(vis[first],0,sizeof(vis[first]));
        for(i=0;i<n;i++){
            int u=s[i]-'A';
            if(!vis[first][u]){
                start[u][first]=i;vis[first][u]=1;
            }
            end[u][first]=i;
        }
    /*    memset(vis[first],0,sizeof(vis[first]));
        for(i=n;i>=1;i--)
            if(!vis[first][s[i]-'A']){
                end[s[i]-'A'][first]=i;vis[first][s[i]-'A']=1;
            }*/
        memset(vis[second],0,sizeof(vis[second]));
        for(i=0;i<m;i++){
            int u=t[i]-'A';
            if(!vis[second][u]){
                start[u][second]=i;vis[second][u]=1;
            }
            end[u][second]=i;
        }
      /*  memset(vis[second],0,sizeof(vis[second]));
        for(i=m;i>=1;i--)
            if(!vis[second][t[i]-'A']){
                end[t[i]-'A'][second]=i;vis[second][t[i]-'A']=1;
            }*/
      //  memset(cnt,0,sizeof(cnt));  ������memset�ᳬʱ��û�б�Ҫ
        int cnt1=0;
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                cnt1=0;
                for(int k=0;k<26;k++){      //start��end��ʼ����ԭ������������Ϊ�ڵڶ���if������ܻ����
                                        //ĳ���ַ�ֻ������һ���������ô����һ�����е�start��end��Ҫ��ʼ��
                    if(vis[first][k]==0 && vis[second][k]==0) continue; //���������ﶼû���ַ�k+'A'
                    if(start[k][first]>=i && start[k][second]>=j) continue;  //�ַ�k��ĿǰΪֹ����û���ֹ�
                    if(end[k][first]<=i-1 && end[k][second]<=j-1) continue;
                    cnt1++;
                }
                cnt[i][j]=cnt1;
            }
        }
        dp[n][m]=0;
        for(i=m-1;i>=0;i--)
            dp[n][i]=dp[n][i+1]+cnt[n][i];
        for(i=n-1;i>=0;i--)
            dp[i][m]=dp[i+1][m]+cnt[i][m];
        for(i=n-1;i>=0;i--)
            for(j=m-1;j>=0;j--)
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+cnt[i][j];
        printf("%d\n",dp[0][0]);
    }
    return 0;
}



