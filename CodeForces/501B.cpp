/****************
*PID:501b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
string s[maxn],t[maxn];
map<string,int> vis;
map<string,string> name,namev;

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        int cnt=0;
        vis.clear();name.clear();namev.clear();
        for(i=1;i<=n;i++){
            cin>>s[i]>>t[i];
            vis[s[i]]=1;vis[t[i]]=1;
            if(i==1){
                name[s[i]]=t[i];namev[t[i]]=s[i];continue;
            }
            for(j=1;j<i;j++)
                if(t[j]==s[i]) break;
            if(j==i){
                name[s[i]]=t[i];
                namev[t[i]]=s[i];
            }
            else {
                string tt=namev[t[j]];
                name[tt]=t[i];namev[t[i]]=tt;
            }
        }
        printf("%d\n",name.size());
        map<string,string>::iterator it;
        it=name.begin();
        while(it!=name.end()){
            cout<<it->first<<' '<<it->second<<endl;
            it++;
        }
    }
    return 0;
}
