#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
map<int,vector<int> > s;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        s.clear();
        int x,y;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(!s.count(x))
                s[x]=vector<int>();
            s[x].push_back(i);
        }
        while(m--){
            scanf("%d%d",&x,&y);
            if(!s.count(y) || s[y].size()<x)
                printf("0\n");
            else
                printf("%d\n",s[y][x-1]);
        }
    }
    return 0;
}
