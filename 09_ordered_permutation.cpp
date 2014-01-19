/*****************************
 * dictionary order permutation
 * Reference : blog.csdn.net/joylnwang/article/details/7064115
 * P1 P2 P3 P4 ... P5
 * 1. i = max{j | P[j-1] < P[j], 0<j<n}
 * 2. l = min{P[j] | P[j] > P[i], i<j<=n}
 * 3. exchange(P[i], P[j])
 * 4. reverse(P[i+1...n])
******************************/
#include <iostream>

using namespace std;











int main(int argc, char *argv[])
{
	char set[3] = {'a', 'b', 'c'};

	Permutate(set, 3, 0);

	//printLevel( arrayToTreeLevel(set, 3) );

	return 0;
}




