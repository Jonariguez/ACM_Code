/****************
*ID:uva699
*Auth:Jonariguez
*****************
直接用map，然后根从0开始，就不用担心没法处理
负数下标了，数组还要处理，麻烦
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> mp;

void build(int now){
    int v;
    scanf("%d",&v);
    if(v==-1) return ;
    mp[now]+=v;
    build(now-1);
    build(now+1);
}

int main()
{
    int i,j,kcase=1;
    while(true){
        mp.clear();
        build(0);
        if(!mp.size())
            break;
        printf("Case %d:\n",kcase++);
        map<int,int>::iterator it;
        it=mp.begin();
        printf("%d",it->second);
        for(it++;it!=mp.end();it++)
            printf(" %d",it->second);
        printf("\n\n");
    }
    return 0;
}
