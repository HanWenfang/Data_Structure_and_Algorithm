/*****
  Reference: http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
  gcc -W -std=c99 ./05_KMP.c -o test

*****/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strCmp(char const *startS1, char const *endS1, char const *startS2, char const *endS2 )
{
	char const *start1 = startS1;
	char const *start2 = startS2;
	while(start1 <= endS1 && start2 <= endS2){
		if(*start1 != *start2) return 0;
		else{
			++start1;
			++start2;
		}
	}

	return (*start1 == *start2);
}

// normal match pattern -- kmp is reccursive in fact!
int matchLen(char const *start, int frontEnd)
{
	int len = strlen(start);
	for(int i=1; i < len; ++i)
	{
		if (strCmp(start, start+frontEnd, start+i, start+len-1))
			return frontEnd+1;
	}
	return 0;
}

int matchNum(char const *start, int end)
{
	int maxMatchLen=0;
	int matchedLen=0;
	for(int i=0; i < end; ++i)
	{
		matchedLen = matchLen(start, i);
		if(matchedLen > maxMatchLen) maxMatchLen = matchedLen;
	}

	return maxMatchLen;
}


int kmp(char const *str, char const *pattern)
{
	//construct the partial match table
	int pLen = strlen(pattern);
	int *matchTable = (int *)malloc(pLen*sizeof(int));

	printf("len: %d\n", pLen);

	for(int i=0; i<pLen; ++i)
	{
		matchTable[i] = matchNum(pattern, i);
		printf("matchTable i= %d\n", matchTable[i]);
	}

	if(matchTable) free(matchTable);
}


int main(int argc, char *argv[])
{
	char *str = "BBC ABCDAB ABCDABCDABDE";
	char *pattern = "ABCDABD";

	int index = kmp(str, pattern);
	printf("Pattern location is : %d\n",index);

	return 0;
}











