#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n, i, j, cost, skill[20], visited[20];
	int current, count=0;
	int best;
	time_t t;
	
	srand((unsigned) time(&t));
	
	printf("Enter the number of candidates appearing :");
	scanf("%d", &n);
	
	printf("Enter the hiring cost :");
	scanf("%d", &cost);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the skill of candidate %d :", i+1);
		scanf("%d", &skill[i]);
		visited[i]=0;
	}
	
	best = 0;
	
	while(1)
	{
		count++;
		current = rand() % n;
		if(visited[current] == 0)
		{
			if(skill[current]>skill[best])
			{
				best=current;
			}
			visited[current]++;
		}
		
		if(checkArray(visited, n))
		{
			printf("\nBest candidate to be hired is candidate %d\n", best+1);
			printf("\nNumber of random iterations is %d", count);
			printf("\nTotal hiring cost is : %d\n", count*cost);
			break;
		}
	}
}
	
int checkArray(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]>=1)
			continue;
		else
			return 0;
	}
	
	return 1;
}
