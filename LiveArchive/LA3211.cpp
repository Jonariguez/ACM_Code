/****************
*PID:la3211
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+5;
int T[maxn][2],n;

struct TwoSAT{
    int n,S[maxn*2],c;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    void init(int n){
        this->n=n;
        for(int i=0;i<n*2;i++) G[i].clear();
        memset(mark,0,sizeof(mark));
    }
    //x=vx or y=vy
    void add_clause(int x,int vx,int y,int vy){
        x=x*2+vx;
        y=y*2+vy;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }
    bool dfs(int x){
        if(mark[x^1]) return false; //对立面也被标记，则矛盾
        if(mark[x]) return true;    //检查一圈，没问题。
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();i++){
            int v=G[x][i];
            if(!dfs(v))
                return false;
        }
        return true;
    }
    bool solve(){
        for(int i=0;i<n*2;i+=2){
            if(!mark[i] && !mark[i+1]){
                c=0;
                if(!dfs(i)){        //尝试标记失败
                    while(c>0) mark[S[--c]]=false;
                    if(!dfs(i+1))   //则去标记对立面
                        return false;
                }
            }
        }
        return true;
    }
}twosat;
/*
bool C(int diff){
    int a,b,i,j;
    twosat.init(n);
    for(i=0;i<n;i++){
        for(a=0;a<2;a++){
            for(j=i+1;j<n;j++){
                for(b=0;b<2;b++){
                    if(abs(T[i][a]-T[j][b])<diff)
                        twosat.add_clause(i,a^1,j,b^1);
                }
            }
        }
    }
    return twosat.solve();
}*/

bool C(int diff){
    int a,b,i,j;
    twosat.init(n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){     //真：早着陆1 假：晚着陆0
            if(abs(T[i][0]-T[j][0])<diff)
                twosat.add_clause(i,0,j,0);
            if(abs(T[i][0]-T[j][1])<diff)   //i早着陆和j晚着陆矛盾，那么就应该i=晚(假0) or j=早(真1)
                twosat.add_clause(i,0,j,1);
            if(abs(T[i][1]-T[j][0])<diff)
                twosat.add_clause(i,1,j,0);
            if(abs(T[i][1]-T[j][1])<diff)
                twosat.add_clause(i,1,j,1);
        }
    }
    return twosat.solve();
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        int L=0,R=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&T[i][0],&T[i][1]);
            R=max(R,T[i][0]);
            R=max(R,T[i][1]);
        }
        while(L<R){
            int M=L+(R-L+1)/2;
            if(C(M))
                L=M;
            else R=M-1;
        }
        printf("%d\n",L);
    }
    return 0;
}
