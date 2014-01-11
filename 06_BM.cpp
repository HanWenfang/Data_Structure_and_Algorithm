/// Boyer-Moore
/// Reference: http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
///	Bad Character and Good Suffix
///
/// g++ -W ./06_BM.cpp -o test

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


int bm(string &text, string &pattern)
{
	int patternSize = pattern.size()-1; // decrease 1
	int *badCharTableLower = new int[24];
	int *badCharTableUpper = new int[24];
	for(int i=0; i<24; ++i)
	{
		badCharTableLower[i] = -1;
		badCharTableUpper[i] = -1;
	}

	for(string::iterator it = pattern.begin(); it != pattern.end(); ++it)
	{
		if(isupper(*it)){
			if(badCharTableUpper[*it-'A'] == -1){
				badCharTableUpper[*it-'A'] = it-pattern.begin();
			}
		}else{
			if(badCharTableLower[*it-'a'] == -1){
				badCharTableLower[*it-'a'] = it-pattern.begin();
			}
		}
	}

	for(int i=0; i < 24; ++i){
		cout << "badCharTableLower: " << badCharTableLower[i] << endl;
	}

	int index=-1;
	string::iterator it = text.begin() + patternSize;
	cout << *it << endl;
	string::iterator itt = pattern.end()-1;
	for(; it < text.end() && itt != pattern.begin()-1;)
	{
		if(*it == *itt){
			--it;
			--itt;
		}else{
			if(isupper(*it)){
				it += (patternSize - badCharTableUpper[*it - 'A']);
			} else {
				cout << *it << " : " << *itt << endl;
				it += (patternSize - badCharTableLower[*it - 'a']);
			}
			
			itt = pattern.end()-1;
		}
	}

	if(it < text.end()) index = it - text.begin(); // start from 1

	if(badCharTableLower) delete[] badCharTableLower;
	if(badCharTableUpper) delete[] badCharTableUpper;

	return index;
}




int main(int argc, char *argv[])
{
	string text = "Here is a simple example!!";
	string pattern = "example";

	int index = bm(text, pattern);

	cout << index << endl;

	return 0;
}

