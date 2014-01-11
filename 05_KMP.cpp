/*****
  KMP Algorithm
  Reference: http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
  gcc -W -std=c99 ./05_KMP.c -o test
  g++ -W ./05_KMP.cpp -o test
*****/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

// normal match pattern -- kmp is reccursive in fact!
int matchNum(set<string> &prefixSet, set<string> &suffixSet)
{
	unsigned int maxMatchLen=0;
	for(set<string>::iterator it=prefixSet.begin(); it != prefixSet.end(); ++it)
	{
		if(suffixSet.find(*it) != suffixSet.end()){
			if(it->size() > maxMatchLen) maxMatchLen = it->size();
		}
	}

	return maxMatchLen;
}

int getSuffixSet(string &patt, set<string> &prefixSet, set<string> &suffixSet)
{
	for(string::iterator it=patt.begin(); it != patt.end()-1; ++it)
	{
		prefixSet.insert(string(patt.begin(), it+1));
	}

	for(string::iterator it=patt.begin()+1; it != patt.end(); ++it)
	{
		//cout << "suffixSet: " << string(it, patt.end()) << endl;
		suffixSet.insert(string(it, patt.end()));
	}
}

int print(set<string> &sSet)
{
	for(set<string>::iterator it = sSet.begin(); it != sSet.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}

int kmp(string &str, string &pattern)
{
	//construct the partial match table
	int *matchTable = new int[pattern.size()];
	cout << " pattern length: " << pattern.size() << endl;
	set<string> prefixSet;
	set<string> suffixSet;
	string temp;

	for(string::iterator it = pattern.begin(); it != pattern.end(); ++it)
	{
		temp = string(pattern.begin(), it+1);
		cout << "temp: " << temp << endl;
		getSuffixSet(temp, prefixSet, suffixSet);
		
		/*
		cout << "prefixSet" << endl;
		print(prefixSet);
		cout << "suffixSet size: " << suffixSet.size() << endl;
		print(suffixSet);
		*/
		
		matchTable[it-pattern.begin()] = matchNum(prefixSet, suffixSet);

		printf("matchTable i= %d\n", matchTable[it-pattern.begin()]);

		prefixSet.clear();
		suffixSet.clear(); // how to implement an algorithm: from the easy simple to hard detail!
	}

	string::iterator itt = pattern.begin();
	string::iterator it=str.begin();
	for(; it != str.end() && itt != pattern.end();)
	{
		cout << *it << " : " << *itt << endl;

		if(*it != *itt && itt != pattern.begin()){
			it += (itt-pattern.begin()-1)-matchTable[itt-pattern.begin()]; // here,both forom zero:it itt
			itt = pattern.begin();
		}else if (*it != *itt && itt == pattern.begin()){
			++it;
		}else {
			++it;
			++itt;
		}
	}

	if(matchTable) delete[] matchTable;
	if(itt == pattern.end()) return (it-str.begin()+1)-pattern.size();

	return -1;
}

int main(int argc, char *argv[])
{
	string str = "BBC ABCDAB ABCDABCDABDE";
	string pattern = "ABCDABD";

	int index = kmp(str, pattern);
	printf("Pattern location is : %d\n",index);

	return 0;
}
