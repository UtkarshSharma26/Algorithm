#include<iostream>
using namespace std;
class knap
  { int n,p[50],w[50],c,oldc;
    int i,y,x[50],f[50][120];  
	public: 
	void get();            
	void findf();           
	void findopt();             
	void display();       
 };   
 void knap::get()   
 {      
 cout<<"ENTER HOW MANY ITEMS:\t";     
 cin>>n;      
 cout<<"ENTER THE CAPACITY OF THE KNAPSACK:\t";      
 cin>>c;      
 oldc=c;      
 for(int i=1;i<=n;i++)       
 { 
  cout<<"ENTER THE PROFIT OF ITEM FOR "<<i<<":\t";       
  cin>>p[i];       
  cout<<"ENTER THE WEIGHT OF ITEM FOR "<<i<<":\t";       
  cin>>w[i];      
 }   
 }   
  void knap::findf()     
  {     
   for(y=0;y<w[n];y++)       
    f[n][y]=0;      
	for(y=w[n];y<=c;y++)        
	f[n][y]=p[n];      
	for(int i=n-1;i>1;i--)      
	{       
	for(int y=0;y<w[i];y++)             
	f[i][y]=f[i+1][y];       
	for(y=w[i];y<=c;y++)             
	f[i][y]=(f[i+1][y]>(f[i+1][y-w[i]]+p[i]))?f[i+1][y]:(f[i+1][y-w[i]]+p[i]);
	}      
	f[1][c]=f[2][c];      
	if(c>=w[1])        
	f[1][c]=(f[1][c]>f[2][c-w[1]]+p[1])?f[1][c]:f[2][c-w[1]]+p[1];    
}    
void knap ::findopt()      
{       
findf();       
for(i=1;i<n;i++)        
{            
 if(f[i][c]==f[i+1][c])              
  x[i]=0;            
   else              
    {                
	x[i]=1;               
	c-=w[i];              
	}       
	}       
    x[n]=(f[n][c])?1:0;     
	}    
	void knap::display()     
	{       
	cout<<"NUMBER OF ITEMS:"<<n<<endl;       
	cout<<"CAPACITY OF THE KNAPSACK :"<<oldc<<endl;       
	cout<<"THE OPTIMAL FILLING IS:"<<endl;       
	for(int i=1;i<=n;i++)             
	cout<<"\n\t"<<"x["<<i<<"]:"<<x[i]<<"  "<<endl;      
	}    
	
	int main()      
	{       
	knap k;                   
	cout<<"\n"<<endl;       
	  k.get();        
	  k.findopt();        
	  k.display();       
	  return 0;
	}
