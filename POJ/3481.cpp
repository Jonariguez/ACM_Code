/*
map里也是用树实现的，用迭代器遍历时会
根据first的升序遍历的
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> mp;

int main()
{
    int i,j,k,p,x;
    while(scanf("%d",&x),x){
        if(x==0) break;
        if(x==1){
            scanf("%d%d",&k,&p);
            mp[p]=k;
        }else if(x==2){
            if(mp.empty()){
                printf("0\n");continue;
            }
            map<int,int>::iterator it;
            it=mp.end();
            it--;
            printf("%d\n",it->second);
            mp.erase(it);
        }else {
            if(mp.empty()){
                printf("0\n");continue;
            }
            map<int,int>::iterator it;
            it=mp.begin();
            printf("%d\n",it->second);
            mp.erase(it);
        }
    }
    return 0;
}
