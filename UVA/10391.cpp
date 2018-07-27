/****************
*ID:uva10391
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n,tot;
map<string,int> id;
map<string,int> res;

int ID(const string s){
    if(!id.count(s)){
        return id[s]=tot++;
    }
    return id[s];
}

vector<string> data;

int main()
{
    int i;
    string s;
    tot=0;
    while(getline(cin,s)){
        data.push_back(s);
        int d=ID(s);
      //  printf("d=%d\n",d);
        res[s]=d;
    }
    for(i=0;i<data.size();i++){
        bool ok=false;
        s=data[i];
        for(int j=1;j<s.length()-1;j++)
            if(res.count(s.substr(0,j)) && res.count(s.substr(j))){
                ok=true;break;
            }
        if(ok)
            cout<<s<<endl;
    }
    return 0;
}
