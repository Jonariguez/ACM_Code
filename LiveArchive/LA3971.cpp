/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
int n,B,tot;
struct Component{
    int price,quality;
};
vector<Component> com[maxn];
map<string,int> id;

void Init(int n){
    id.clear();
    for(int i=0;i<=n;i++) com[i].clear();
    tot=0;
}

int ID(string str){
    if(!id.count(str))
        id[str]=++tot;
    return id[str];
}

bool C(int x){
    LL sum=0;
    Component c;
    for(int i=1;i<=tot;i++){
        int now=B+1;
        for(int j=0;j<com[i].size();j++){
            c=com[i][j];
            if(c.quality<x) continue;
            now=min(now,c.price);
        }
        if(now==B+1) return false;
        sum+=now;
        if(sum>B) return false;
    }
    return sum<=B;
}


int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&B);
        Init(n);
        string type,name;
        int price,quality,l=0,r=0;
        for(i=1;i<=n;i++){
            cin>>type>>name>>price>>quality;
            com[ID(type)].push_back((Component){price,quality});
            r=max(r,quality);
        }
        while(l<r){
            int m=l+(r-l+1)/2;
            if(C(m))
                l=m;
            else r=m-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
