/****************
*PID:510c div2
*Auth:Jonariguez
*****************
建图拓扑排序
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+20;
char str[maxn][maxn];
int in[30],mp[30][30],len[maxn];
vector<int> res;

void top(){
    queue<int> que;
    int i;
    for(i=0;i<26;i++)
        if(in[i]==0)
            que.push(i);
    while(!que.empty()){
        int u=que.front();que.pop();
        res.push_back(u);
        for(i=0;i<26;i++){
            if(mp[u][i]){
                in[i]--;
                if(in[i]==0) que.push(i);
            }
        }
    }
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            len[i]=strlen(str[i]+1);
        }
        memset(mp,0,sizeof(mp));
        memset(in,0,sizeof(in));
        int yes=1;
        for(i=1;i<n;i++){
            if(str[i][1]!=str[i+1][1]){
                if(mp[str[i+1][1]-'a'][str[i][1]-'a']){ //如果已经有a大于b，那么说b大于a就矛盾了
                    yes=0;break;
                }
                mp[str[i][1]-'a'][str[i+1][1]-'a']=1;
                in[str[i+1][1]-'a']++;
            }else {
                int j=1,k=1;
                while(j<=len[i] && k<=len[i+1]){
                    if(str[i][j]!=str[i+1][k]){
                        if(mp[str[i+1][k]-'a'][str[i][j]-'a']){
                            yes=0;break;
                        }
                        mp[str[i][j]-'a'][str[i+1][k]-'a']=1;
                        in[str[i+1][k]-'a']++;
                        break;
                    }
                    j++;k++;
                }
                if(k>len[i+1]){
                    yes=0;break;
                }
            }
            if(yes==0) break;
        }
        if(yes==0)
            printf("Impossible\n");
        else {
            res.clear();
            top();
            if((int)res.size()!=26){
                printf("Impossible\n");continue;
            }
            for(i=0;i<26;i++)
                printf("%c",res[i]+'a');
            printf("\n");
        }
    }
    return 0;
}
