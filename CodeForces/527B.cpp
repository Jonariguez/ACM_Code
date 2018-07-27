/****************
*PID:52b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
char s[maxn],t[maxn];
int vis[30][30];
map<int,char> ss,tt;
set<int> sa[30],ta[30];
vector<int> res;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s%s",s+1,t+1);
        memset(vis,0,sizeof(vis));
        int cnt=0;
        ss.clear();tt.clear();
        for(i=1;i<=n;i++){
            if(s[i]==t[i]) continue;
            cnt++;
            vis[s[i]-'a'][t[i]-'a']=1;
        }
        if(cnt==0){
            printf("0\n-1 -1\n");continue;
        }
        res.clear();
        int flag=0,x,y;
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                if(vis[i][j] && vis[j][i]){
                    x=i;y=j;flag=1;break;
                }
            }
            if(flag) break;
        }
        if(flag){
            printf("%d\n",cnt-2);
            int k1=0,k2=0;
            for(i=1;i<=n;i++){
                if(s[i]==t[i]) continue;
                if(s[i]-'a'==x && t[i]-'a'==y && k1==0){    //×¢ÒâÓÃk1£¬k2ÅÐÖØ
                    res.push_back(i);k1=1;
                }
                if(s[i]-'a'==y && t[i]-'a'==x && k2==0){
                    res.push_back(i);k2=1;
                }
                if(res.size()==2) break;
            }
            printf("%d %d\n",res[0],res[1]);
        }else {
            flag=0;
            int k;
            for(i=0;i<26;i++){
                for(j=0;j<26;j++){
                    if(vis[i][j]==1){
                        for(k=0;k<26;k++)
                            if(vis[j][k]) break;
                        if(k==26) continue;
                        else {
                            flag=1;break;
                        }
                    }
                }
                if(flag) break;
            }
            if(flag){
                int k1=0,k2=0;
                for(int v=1;v<=n;v++){
                    if(s[v]==t[v]) continue;
                    if(s[v]-'a'==i && t[v]-'a'==j && k1==0){
                        res.push_back(v);k1=1;
                    }
                    if(s[v]-'a'==j && k2==0){
                        res.push_back(v);k2=1;
                    }
                    if(res.size()==2) break;
                }
                printf("%d\n%d %d\n",cnt-1,res[0],res[1]);
            }else
                printf("%d\n-1 -1\n",cnt);
        }
    }
    return 0;
}
