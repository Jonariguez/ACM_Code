/****************
*PID:uva10817
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>1
#include <sstream>
using namespace std;

const int maxn=120+10;
const int INF=1e9;
int c[maxn],st[maxn],S,n,m,dp[maxn][(1<<8)][(1<<8)];

int dfs(int cur,int s0,int s1,int s2){
    if(cur==m+n) return s2==(1<<S)-1?0:INF;
    int& ans=dp[cur][s1][s2];
    if(ans>=0) return ans;
    ans=INF;
    if(cur>=m)
        ans=dfs(cur+1,s0,s1,s2);
    int m0=s0&st[cur],m1=s1&st[cur];
    s0^=m0;s1^=m1;s1|=m0;s2|=m1;
    ans=min(ans,c[cur]+dfs(cur+1,s0,s1,s2));
    return ans;
}

int main()
{
    int i,j,res;
    string sp;
    while(getline(cin,sp)){
        stringstream sa(sp);
        sa>>S>>m>>n;
        if(S==0) break;
        for(i=0;i<m+n;i++){
            string s;
            getline(cin,s);
            stringstream ss(s);
            int b;
            ss>>c[i];
            st[i]=0;
          //  printf("b=%d\n",b);
            while(ss>>b){
             //   printf("b=%d\n",b);
                st[i]|=(1<<(b-1));
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(0,(1<<S)-1,0,0));
    }
    return 0;
}
