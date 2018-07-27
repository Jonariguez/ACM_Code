/*
记录每行需要打扫的列号，然后枚举每一行i，
检查其他行需要打扫的列号是否和i需要的打扫
的完全一样
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn][maxn];
vector<int> v[maxn];

bool check(int x,int y){
    if(v[x].size()!=v[y].size()) return false;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=v[y][i]) return false;
    return true;
}

int main()
{
    int i,j,n,t;
    while(scanf("%d",&n)!=EOF){
        char c;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf(" %c",&c);
                a[i][j]=c-'0';
            }
        }
        for(i=0;i<n;i++){
            v[i].clear();
            for(j=0;j<n;j++)
                if(a[i][j]==0)
                    v[i].push_back(j);
        }
        int res=0;
        for(i=0;i<n;i++){
            int cnt=0;
            for(j=0;j<n;j++)
                if(check(i,j)) cnt++;
            res=max(res,cnt);
        }
        printf("%d\n",res);
    }
    return 0;
}
