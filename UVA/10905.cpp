/****************
*PID:uva10905
*Auth:Jonariguez
*****************
贪心，一开始想到用前缀的思路处理，编程有点复杂。
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100;
string dic[maxn];
int vis[maxn];

int cmp(const string &a,const string &b){
    return a+b>b+a;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            cin>>dic[i];
        sort(dic,dic+n,cmp);
        for(i=0;i<n;i++)
            cout<<dic[i];
        cout<<endl;
    }
    return 0;
}


/*
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            cin>>dic[i];
        memset(vis,0,sizeof(vis));
        for(i=9;i>=1;i--){
            vector<string> now;
            for(j=0;j<n;j++)
                if(dic[j][0]-'0'==i) now.push_back(dic[j]);
            if(now.size()==0) continue;
            if(now.size()==1){
                cout<<now[0];continue;
            }
            sort(now.begin(),now.end());
            int k=0,t=0;
            for(j=0;j<now.size()-1;j++){
                k=0;
                while(k<now[j].size() && k<now[j+1].size()){
                    if(now[j][k]!=now[j+1][k]) break;
                    k++;
                }
                if(j==0 || t>k)
                    t=k;
            }
            for(j=now.size()-1;j>=0;j--){
                if(now[j].size()>t){
                    if(now[j][t]>=



        }
    }
    return 0;
}*/
