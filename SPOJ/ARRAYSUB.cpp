#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n,k;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	//to print max element in each substring of size k

	list<int> q(k);

	int i;
	for(i = 0;i<k;i++)
	{
		while((!q.empty()) && a[i] >= a[q.back()])
		{
			q.pop_back();
		}

		q.push_back(i);
	}

	for(i = k;i<n;i++)
	{
		//denotes greatest element in that sub-array
		cout<<a[q.front()]<<" ";

		while((!q.empty()) && q.front() <= i - k)
		{
			q.pop_front();
		}

		while((!q.empty()) && a[i] >= a[q.back()])
		{
			q.pop_back();
		}

		q.push_back(i);


	}

	cout<<a[q.front()]<<endl;



}