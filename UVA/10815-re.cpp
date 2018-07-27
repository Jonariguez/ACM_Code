/****************
*PID:uva10815
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
set<string> dic;

int main()
{
    int i,j,n=0;
    string s;
    while(cin>>s){
        for(i=0;i<s.length();i++){
            if(isalpha(s[i]))
                s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        string buf;
        while(ss>>buf) dic.insert(buf);
    }
    set<string>::iterator it;
    for(it=dic.begin();it!=dic.end();it++)
        cout<<*it<<endl;
    return 0;
}
