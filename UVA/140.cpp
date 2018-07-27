/****************
*ID:uva140
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10;
int id[260],letter[maxn];
char str[1000];

int main()
{
    int i,j;
    while(scanf("%s",str)){
        if(str[0]=='#') break;
        int n=0;
        for(char ch='A';ch<='Z';ch++){
            if(strchr(str,ch)!=NULL){
                id[ch]=n++;
                letter[id[ch]]=ch;
            }
        }
        int p=0,q=0,len=strlen(str);
        vector<int> u,v;
        for(;;){
            while(p<len && str[p]!=':') p++;
            if(p>=len) break;
            while(q<len && str[q]!=';') q++;
            for(i=p+1;i<q;i++){
                u.push_back(id[str[p-1]]);
                v.push_back(id[str[i]]);
            }
            q++;p=q;
        }

        int P[maxn],best[maxn],pos[maxn],res=n;
        for(i=0;i<n;i++) P[i]=i;
        do{
            for(i=0;i<n;i++) pos[P[i]]=i;
            int bw=0;
            for(i=0;i<u.size();i++)
                bw=max(bw,abs(pos[u[i]]-pos[v[i]]));
            if(bw<res){
                res=bw;
                memcpy(best,P,sizeof(P));
            }
        }while(next_permutation(P,P+n));
        for(i=0;i<n;i++)
            printf("%c ",letter[best[i]]);
        printf("-> %d\n",res);
    }
    return 0;
}
