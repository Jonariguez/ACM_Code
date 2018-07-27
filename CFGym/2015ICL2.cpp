/****************
*PID:F
*Auth:Jonariguez
*****************
*/
#include<stdio.h>
#include<string.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[100005],c[100005];
map<LL,LL> mp;
set<LL> s;


int main()
{
    int n,i,maxx=1,p=0;
    while(scanf("%d",&n)!=EOF){
        LL res=0;
        mp.clear();s.clear();
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            mp[a[i]]++;
            s.insert(a[i]);
        }
        set<LL>::iterator it;
        it=s.end();
        it--;
        res=mp[(*it)]*(*it);//printf("%I64d\n",res);
        LL v;
        for(i=1;i<=n;i++){
            if(a[i]==0) continue;
            if(i==1){
                v=(--mp[a[i]]);
                if(mp[a[i]]==0)
                    s.erase(a[i]);
                mp[a[i]-1]++;
                s.insert(a[i]-1);
                mp[a[i+1]+1]++;
                s.insert(a[i+1]+1);
                v=(--mp[a[i+1]]);
                if(v==0)
                    s.erase(a[i+1]);
                it=s.end();
                it--;
              //  printf("it=%I64d\n",(*it));
                res=min(res,(*it)*mp[(*it)]);
                mp[a[i]]++;
                s.insert(a[i]);
                v=(--mp[a[i]-1]);
                if(v==0)
                    s.erase(a[i]-1);
                mp[a[i+1]]++;
                s.insert(a[i+1]);
                v=(--mp[a[i+1]+1]);
                if(v==0)
                    s.erase(a[i+1]+1);
            }else if(i==n){
                v=(--mp[a[i]]);
                if(v==0)
                    s.erase(a[i]);
                mp[a[i]-1]++;
                s.insert(a[i]-1);
                mp[a[i-1]+1]++;
                s.insert(a[i-1]+1);
                v=(--mp[a[i-1]]);
                if(v==0)
                    s.erase(a[i-1]);
                it=s.end();
                it--;//printf("it=%I64d\n",(*it));
                res=min(res,(*it)*mp[(*it)]);
                mp[a[i]]++;
                s.insert(a[i]);
                v=(--mp[a[i]-1]);
                if(v==0)
                    s.erase(a[i]-1);
                mp[a[i-1]]++;
                s.insert(a[i-1]);
                v=(--mp[a[i-1]+1]);
                if(v==0)
                    s.erase(a[i-1]+1);
            }else {
                v=(--mp[a[i]]);
                if(v==0)
                    s.erase(a[i]);
                mp[a[i]-1]++;
                s.insert(a[i]-1);
                mp[a[i+1]+1]++;
                s.insert(a[i+1]+1);
                v=(--mp[a[i+1]]);
                if(v==0)
                    s.erase(a[i+1]);
                it=s.end();
                it--;//printf("it=%I64d\n",(*it));
                res=min(res,(*it)*mp[(*it)]);
                mp[a[i]]++;
                s.insert(a[i]);
                v=(--mp[a[i]-1]);
                if(v==0)
                    s.erase(a[i]-1);
                mp[a[i+1]]++;
                s.insert(a[i+1]);
                v=(--mp[a[i+1]+1]);
                if(v==0)
                    s.erase(a[i+1]+1);//printf("%I64d\n",res);

                v=(--mp[a[i]]);
                if(v==0)
                    s.erase(a[i]);
                mp[a[i]-1]++;
                s.insert(a[i]-1);
                mp[a[i-1]+1]++;
                s.insert(a[i-1]+1);
                v=(--mp[a[i-1]]);
                if(v==0)
                    s.erase(a[i-1]);
                it=s.end();
                it--;//printf("it=%I64d\n",(*it));
                res=min(res,(*it)*mp[(*it)]);
                mp[a[i]]++;
                s.insert(a[i]);
                v=(--mp[a[i]-1]);
                if(v==0)
                    s.erase(a[i]-1);
                mp[a[i-1]]++;
                s.insert(a[i-1]);
                v=(--mp[a[i-1]+1]);
                if(v==0)
                    s.erase(a[i-1]+1);//printf("%I64d\n",res);
            }
         //   printf("%I64d\n",res);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
