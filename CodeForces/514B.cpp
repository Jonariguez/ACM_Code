/****************
*PID:514b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-7
#define K 20000
set<pair<int,int> > s;
map<double,int> mp;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

pair<int,int> get(int a,int b){
    int g=gcd(abs(a),abs(b)),x,y;
    a/=g;b/=g;
    if(a*b>=0)
        return make_pair(abs(a),abs(b));
    else return make_pair(-abs(a),abs(b));
}

int main()
{
    int i,j,n;
    int x,y,a,b;
 //   printf("%d\n",-5/(3));
    while(scanf("%d%d%d",&n,&x,&y)!=EOF){
        s.clear();
        mp.clear();
        j=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            a-=x;b-=y;
            a*=10000;b*=10000;
            if(a==0) j=1;
            else s.insert(get(a,b));
        }
        printf("%d\n",s.size()+j);
    }
    return 0;
}
