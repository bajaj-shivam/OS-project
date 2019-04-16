#include<iostream>
using namespace std;
int main()
{
    float EAT,MAT,PFST1,PFST2,PTR; ////PFST1=Page fault  service time not modified
    
    									//PFST2=Replaced page service time , modified 
    									
    float ans;							


	 cout<<"Enter the memory access time in nanosecond "<<endl;

    cin>>MAT;

    cout<<"Enter the effective time access in nanosecond"<<endl;

    cin>>EAT;
    
    cout<<"Enter the value of Page fault service time ,not modified, in millisecond"<<endl;

    cin>>PFST1;
	
	PFST1=PFST1*1000000;
    cout<<"Enter the value of page fault service time ,modified , in millisecond"<<endl;

    cin>>PFST2;
	PFST2=PFST2*1000000;
   

   cout<<"Enter the page raplace modified percentage "<<endl;

    cin>>PTR;                                        //PTR =Page to replace percentage
    
    PTR=PTR/100;

   ans=(EAT-MAT)/((MAT+(PTR*PFST2)+(1-PTR)*PFST1)-MAT);

   cout<<" The Mamximum acceptable page fault rate is "<<ans;

}
