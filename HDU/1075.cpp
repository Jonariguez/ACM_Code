#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

const int maxn=3000+10;
char str[maxn],str2[maxn];
map<string,string> mp;

int main()
{
    int i,j,n;
    scanf("%s",str);
    while(scanf("%s",str) && !strcmp(str,"END")){
        scanf("%s",str2);
        mp[string(str2)]=string(str);
    }
    while(gets(str) && !strcmp(str,"END")){
    }
    return 0;
}
