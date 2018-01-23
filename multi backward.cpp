#include<iostream>
#include<conio.h>

using namespace std;
struct fwd
{
	int l;
	int a[20];
};	struct fwd s1[10];
	
int main()
{
	int k,i,j,n,p[10],m,z,cost[50],v,c[20][20];

	cout<<"Enter the no. of stages :";
	cin>>k;
	n=0;
	//Get the input for vertices
	for(i=1;i<=k;i++)
	{
		cout<<"Enter no. of vertices in stage "<<i<<" :";
		cin>>s1[i].l;
		n+=s1[i].l;
		for(j=1;j<=s1[i].l;j++)
		{
			cout<<"Enter the value of vertex "<<j<<" :";
			cin>>s1[i].a[j];
		}
	}
	//Get the input for cost matrix
	for(i=1;i<k;i++)
	{
		for(j=s1[i].a[1];j<=s1[i].a[s1[i].l];j++)
		{
			for(z=s1[i+1].a[1];z<=s1[i+1].a[s1[i+1].l];z++)
			{
				cout<<"Enter the cost of c["<<j<<"]["<<z<<"] :";
				cin>>c[j][z];
			}
		}
	}
	//bwd approach
	cost[n]=0;
	int min,d[50],t;
	for(i=1;i<=k-1;i++)
	{
		for(j=s1[i+1].a[1];j<=s1[i+1].a[s1[i+1].l];j++)
		{
			min=999;
			for(z=s1[i].a[1];z<=s1[i].a[s1[i].l];z++)
			{
			//	cout<<cost[z]<<"j, z = "<<j<<" "<<z<<endl
				if(cost[z]+c[z][j]<min)
				{
					min=cost[z]+c[z][j];
					t=z;
	
				}
				d[j]=t;	
			}
			cost[j]=min;		 	
	
		}
	}

	p[1]=1;
	p[k]=n;
	
	for(i=k-1;i>1;i--)
	{
		p[i]=d[p[i+1]];
	}
	for(i=1;i<k;i++)
	{
		cout<<p[i]<<"-->";
	}
	cout<<p[k];
	
	return 0;
} 
