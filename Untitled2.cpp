#include<iostream>
void fgraph();
static findr(int);
static int g[100][100];
static int n;
static int k;
int i,j,r,w;
int main()
{
std::cout<<"Multistage graph";
            std::cout<<"\n\n\nEnter the no. of  vertices:";
            std::cin>>n;
               std::cout<<"\n\n\nEnter the total no. of  states:";
               std::cin>>k;
            std::cout<<"\n\nIf there is a edge between following vertices Enter its weight else 0";
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
         {
                   g[i][j]=0;
                   if((i!=j)&&(i<j))
                    {
                       std::cout<<"\n"<<i;
                       std::cout<<"and"<<j;
                      std::cout<<":";
                      std::cin>>w;
                       g[i][j]=w;
                    }
		}
            fgraph();
         
}
void fgraph()
{
        int cost[100];
            int d[100];
            int p[100];
            for(i=1;i<=n;i++)
            cost[i]=0;
            for(j=n-1;j>=1;j--)
             {
                   r=findr(j+1);
                   cost[j]=g[j][r]+cost[r];
                   d[j]=r;
             }
             p[1]=1;p[k]=n;
            for(j=2;j<k;j++)
            p[j]=d[p[j-1]];
            std::cout<<d[1];
           std::cout<<"****";
            for(j=2;j<n;j++)
             {
                   if((d[j]==d[j-1]||d[j]==0))
                   continue;
                   std::cout<<d[j];
             }
         std::cout<<n;
}
static int findr(int cu)
{
          int k;
            int r1=n+1;
            for(int h=1;h<=n;h++)
             {
                   if((g[h][cu]!=0)&&(r1==n+1))
                    {
                       r1=h;
              continue;
                    }
                   if(g[h][cu]!=0)
                        {
                       if(g[h][cu]<g[r1][cu])
                       r1=h;
                    	}
             }
return r1;
}

