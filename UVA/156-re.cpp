/****************
*PID:uva156
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
string dict[maxn];
vector<string> res;
map<string,int> mp;

string standard(string s){
    for(int i=0;i<s.length();i++)
        s[i]=tolower(s[i]);
    sort(s.begin(),s.end());
    return s;
}

int main()
{
    string s;
    int i,n=0;
    while(cin>>s){
        if(s[0]=='#') break;
        string b=standard(s);
        mp[b]++;
        dict[n++]=s;
    }
    for(i=0;i<n;i++)
        if(mp[standard(dict[i])]==1)
            res.push_back(dict[i]);
    sort(res.begin(),res.end());
    for(i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}
