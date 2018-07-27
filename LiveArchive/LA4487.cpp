/****************
*PID:la4487
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=20000+10;
int par[maxn],rel[maxn];
map<int,int> mp;

void init(int n){
    for(int i=0;i<=n;i++){
        par[i]=i;rel[i]=0;
    }
}

int find(int x){
    if(x==par[x]) return x;
    int y=find(par[x]);
    rel[x]^=rel[par[x]];
    return par[x]=y;
}

int main()
{
    int i,j,n,Q,kcase=1;
    while(scanf("%d%d",&n,&Q)!=EOF){
        if(n==0 && Q==0) break;
        init(n);
        getchar();
        printf("Case %d:\n",kcase++);
        string line,op;
        int a[50],yes=1,p,q,v,sum=0;
        for(j=1;j<=Q;j++){
            getline(cin,line);
            if(yes==0) continue;
            stringstream ss(line);
            ss>>op;
            i=0;
            if(op[0]=='I'){
                sum++;
                while(ss>>a[++i]);
                if(i==3){           //I p v
                    p=a[1];v=a[2];
                    p++;
                    if(find(p)==0 && rel[p]!=v){
                        yes=0;
                        printf("The first %d facts are conflicting.\n",sum);
                        continue;
                    }else {
                        par[p]=0;rel[p]=v;
                    }
                }else if(i==4){
                    p=a[1];q=a[2];v=a[3];
                    p++;q++;
                    int fp=find(p),fq=find(q);
                  //  if(fp!=0 && fq!=0){
                        if(fp!=fq){
                            if(fp>fq) swap(fp,fq);
                            par[fq]=fp;rel[fq]=(rel[p]^rel[q]^v);
                        }else {
                            if((rel[p]^rel[q])!=v){
                                yes=0;
                                printf("The first %d facts are conflicting.\n",sum);
                                continue;
                            }
                        }
                  /*  }else {
                        if(fp==0 && fq!=0){
                            par[fq]=0;rel[fq]=(rel[p]^rel[q]^v);
                        }else if(fp!=0 && fq==0){
                            par[fp]=0;rel[fp]=(rel[q]^rel[p]^v);
                        }else {
                            if((rel[q]^rel[p])!=v){
                                yes=0;
                                printf("The first %d facts are conflicting.\n",sum);
                                continue;
                            }
                        }
                    }*/
                }
            }else if(op[0]=='Q'){
                while(ss>>a[++i]);
                int y=1,res=0;
                mp.clear();
                for(int z=2;z<i;z++){
                    a[z]++;
                    mp[find(a[z])]++;
                    res^=rel[a[z]];
                }
                map<int,int>::iterator it;
                it=mp.begin();
                y=1;
                while(it!=mp.end()){
                    if((*it).first!=0 && (*it).second%2==1){
                        y=0;break;
                    }
                    it++;
                }
                if(y) printf("%d\n",res);
                else puts("I don't know.");
            }
        }
        puts("");
    }
    return 0;
}


