#include<iostream>
 
using namespace std;
 
int main()
{
    int a[50],n,i,j,temp;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the array elements: "; 
    
    for(i=0;i<n;i++)
        cin>>a[i];
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
    cout<<" "<<a[1]<<"   "<<a[n];
        
    return 0;
}
