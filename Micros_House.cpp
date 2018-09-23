#include<iostream>
using namespace std;
int main()
{
	int N,M,i,j,sum=0,max=0;
	cin>>N>>M;
	int arr[N][M];
	int row_arr[N+M];
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<M;j++)
		{
			cin>>arr[i][j];
			sum=sum^arr[i][j];
		}
		row_arr[i]=sum;
		if(max<row_arr[i])
		{
			max=row_arr[i];
		}
	}
	
int k=N;
	for(i=0;i<M;i++)
	{
		sum=0;
		for(j=0;j<N;j++)
		{
			sum=sum^arr[j][i];
		}
		row_arr[k]=sum;
		k++;
	}
	/*
	for(i=0;i<k;i++)
	{
		cout<<row_arr[i]<<" ";
	}
	cout<<endl;
	*/
	for(i=0;i<k;i++)
	{
		if(max<row_arr[i])
		{
			max=row_arr[i];
		}
	}

	cout<<max<<endl;
}