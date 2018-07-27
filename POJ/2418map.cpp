#include <iostream>
#include <cstdio>
#include <iterator>
#include <map>
#include <string>
using namespace std;

int main()
{
	string str;
	int tot=0;
	map<string,int> mp;
	while(getline(cin,str)){
		mp[str]++;
		tot++;
	}
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first;
		printf(" %.4f\n",(double)it->second/tot*100);
	}
	return 0;
}
