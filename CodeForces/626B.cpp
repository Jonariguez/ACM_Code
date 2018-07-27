/****************
*PID:626b div2
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

const int maxn=200+10;
char str[maxn];
char t[6]="aBGR";
int cnt[5];

set<char> ss,z;
map<char,int> mp;

int Id(char c){
    if(c=='B') return 1;
    if(c=='G') return 2;
    return 3;
}

int main()
{
    int i,j,n;
    z.insert('B');
    z.insert('G');
    z.insert('R');
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        ss.clear();
        mp.clear();
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            ss.insert(str[i]);
            cnt[Id(str[i])]++;
            mp[str[i]]++;
        }
        if(ss.size()==3){
            puts("BGR");
        }else if(ss.size()==1){
            printf("%c\n",str[1]);
        }else {
            if(n==2){
                set<char> now;
                now=z;now.erase(str[1]);now.erase(str[2]);
                set<char>::iterator it;
                it=now.begin();
                printf("%c\n",(*it));
            }else if(n==3){
                if(mp['B']==2){
                    puts("GR");
                }else if(mp['G']==2){
                    puts("BR");
                }else if(mp['R']==2)
                    puts("BG");
            }else {
                if(mp['B']==1){
                    if(mp['G']>1) puts("BR");
                    else puts("BG");
                }else if(mp['G']==1){
                    if(mp['B']>1) puts("GR");
                    else puts("BG");
                }else if(mp['R']==1){
                    if(mp['B']>1) puts("RG");
                    else puts("BR");
                }else puts("BGR");
            }
        }
    }
    return 0;
}

