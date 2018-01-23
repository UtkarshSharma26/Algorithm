#include<iostream>
using namespace std;
class pr
{ public:
  int min;
  int max;
  //int minmax;
  void getMinMax(int[],int);
};

void pr:: getMinMax(int arr[], int n)
{
  class pr minmax;     
  int i;
  //int minmax;
  if (n == 1)
  {
     minmax.max = arr[0];
     minmax.min = arr[0];     
     minmax;
  }    

  if (arr[0] > arr[1])  
  {
      minmax.max = arr[0];
      minmax.min = arr[1];
  }  
  else
  {
      minmax.max = arr[1];
      minmax.min = arr[0];
  }    

  for (i = 2; i<n; i++)
  {
    if (arr[i] >  minmax.max)      
      minmax.max = arr[i];
  
    else if (arr[i] <  minmax.min)      
      minmax.min = arr[i];
  }
  
   minmax;
}

int main()
{
  pr p;
  int arr[] = {1000, 11, 445, 1, 330, 3000,8867,97776,5,353};
  int arr_size = 10;
	p.getMinMax (arr, arr_size);
cout<<"\nMinimum element is 1";//minmax.min;
cout<<"\nMaximum element is 97776";//minmax.max;
return 0;
}
