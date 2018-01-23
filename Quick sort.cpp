#include<iostream>
using namespace std;
int partition(int *a,int start,int end)
{
	int pindex=start;
	int pivot=a[end];
	for(int i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			int temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	int temp=a[pindex];
	a[pindex]=a[end];
	a[end]=temp;
	return pindex;
}
void quicksort(int *a,int start,int end)
{
	if(start<end)
	{
		int p=partition(a,start,end);
		quicksort(a,start,p-1);
		quicksort(a,p+1,end);
	}
}
int main()
{
	int a[50];
	int n;
	cout<<"Enter the number of elements "<<endl;
	cin>>n;
	cout<<"Enter"<<n<<"elements "<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n+1);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"  ";
	}
	return 0;
}

