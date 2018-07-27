#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> Vec;

const int maxn=1000+10;

bool check(vector<int> &a){
    for(int i=0;i<a.size();i++)
        if(a[i]) return false;
    return true;
}

void print(vector<int> &a){
    for(int i=0;i<a.size();i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int i,j,T,n,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        Vec s[2];
        map<Vec,int> mp;
        int sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&t);
            s[0].push_back(t);
            sum+=t;
        }
        if(sum==0){
            printf("ZERO\n");
            continue;
        }
        mp[s[0]]++;
        int d=0,flag=0;
        while(1){
            int ok=1;
            t=d^1;
            s[t].clear();
            for(i=0;i<n-1;i++)
                s[t].push_back(abs(s[d][i]-s[d][i+1]));
            s[t].push_back(abs(s[d][n-1]-s[d][0]));
            if(mp[s[t]]){
                flag=1;break;
            }
            mp[s[t]]++;
            if(check(s[t])){
                flag=2;break;
            }
            d^=1;
        }
        if(flag==1)
            printf("LOOP\n");
        else if(flag==2)
            printf("ZERO\n");
    }
    return 0;
}
