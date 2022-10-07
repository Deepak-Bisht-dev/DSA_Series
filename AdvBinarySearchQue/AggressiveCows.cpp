// we have to place the cows in the stalls so that the min dist b/w the cows is as max as possible... 
// as we find the sentence largest min dist. or kind of this means this tends to Binary Search problem

// so, the approach is that we'll montonically start from 1 as see if we can place the cows with this dist. if yes then we'll inc start = mid + 1 and if not then we'll dec. end = mid - 1
// so s = 1 as we can keep least dist as 1
// and e = max - min so our search space revolves around these start and end values


#include <bits/stdc++.h>
using namespace std;

int N,C;

int check(int num,int stalls[])
{	
	// cows is storing the count of cows and pos means we'r first 	placing the cow at first stall 
	int cows = 1,pos = stalls[0];
	for (int i = 1; i < N; i++)
	{
		if (stalls[i] - pos >= num)
		{
			pos = stalls[i]; // the new cow placed is at pos stall[i]
			cows++; // inc. the count of cow as we have placed one more cow now
			if (cows == C)
				return 1;
		}
	}
	return 0;
}

int binarySearch(int stalls[])
{
	int start = 0,end = stalls[N-1],max = -1;
	while (end > start)
	{
		int mid = (start+end)/2;
		if (check(mid,stalls) == 1)
		{
			if (mid > max)
				max = mid;
			start = mid+1;
		}
		else
			end = mid;
	}
	return max;
}

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		cin >> N >> C;
		
		int stalls[N];
		
		for (int i=0; i<N; i++)
			cin >> stalls[i];
		
		sort(stalls,stalls+N);
		
		int k = binarySearch(stalls);
		
		cout << "Max distance b/w cows can be :  " << k;
	}
	return 0;
}
