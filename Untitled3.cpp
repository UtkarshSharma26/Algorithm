#include<iostream>
struct fwd
{
                int l;
                int a[20];
};
struct fwd s1[10];
 
int main()
{
                int k,i,j,n,p[10],m,z,cost[50],v,c[20][20];
            
                std::cout<<"Enter the no. of stages :";
                std::cin>>k;
                n=0;
 
                //Get the input for vertices
                for(i=1;i<=k;i++)
                {
                                std::cout<<"Enter no. of vertices in stage "<<i<<" :";
                                std::cin>>s1[i].l;
                                n+=s1[i].l;
                                for(j=1;j<=s1[i].l;j++)
                                {
                                                std::cout<<"Enter the value of vertex "<<j<<" :";
                                                std::cin>>s1[i].a[j];
                                }
                }
 
                //Get the input for cost matrix
                for(i=1;i<k;i++)
                {
                                for(j=s1[i].a[1];j<=s1[i].a[s1[i].l];j++)
                                {
                                                for(z=s1[i+1].a[1];z<=s1[i+1].a[s1[i+1].l];z++)
                                                {
                                                                std::cout<<"Enter the cost of c["<<j<<"]["<<z<<"] :";
                                                                std::cin>>c[j][z];
                                                }
                                }
                }
 
                //fwd approach
                cost[n]=0;
                int min,d[50],t;
                for(i=k-1;i>=1;i--)
                {
                                for(j=s1[i].a[1];j<=s1[i].a[s1[i].l];j++)
                                {
                                                min=999;
                                                for(z=s1[i+1].a[1];z<=s1[i+1].a[s1[i].l];z++)
                                                {
                                                                if(cost[z]+c[z][j]<min)
                                                            
															
                                                                min=cost[z]+c[z][j];
                                                                t=z;
                                                        
                                                }
                                                cost[j]=min;
                                                d[j]=t;
                                }
                }
 
                //To display the path
 
                p[1]=1;
                p[k]=n;
                for(i=2;i<k;i++)
                {
                                p[i]=d[p[i-1]];
                }
                for(i=1;i<k;i++)
                {
                                std::cout<<p[i]<<"-->";
                }
                std::cout<<p[k];
            
return 0;}
