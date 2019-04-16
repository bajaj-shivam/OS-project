#include<stdio.h>
//#include<conio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
struct queue
{
	string info;
	queue * link;
};
struct queue * rear;
struct queue * front;

/*queue * create_queue(int cap)
{
	queue *temp;
	temp=(queue *)malloc(sizeof(struct queue)*cap);
	return(temp);
}*/
void enqueue(string item)
{
	//int item;
	queue *temp=new queue;
	//cout<<"Enter the item"<<endl;
	//cin>>item;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
		rear->link=NULL;
		rear->info=item;
	}
	else
	{
		rear->link=temp;
		rear=temp;
		rear->link=NULL;
		rear->info=item;
	}
}
void view_queue()
{

	queue * temp=front;
	while(temp!=rear)
	{
		cout<<temp->info<<endl;
		temp=temp->link;
	}
	cout<<temp->info<<endl;
}
string dequeue()
{
	string item;
	if(front==NULL)
	{
		cout<<"Underflow"<<endl;
		exit(0);
	}
	else if(front==rear)
	{
		item=front->info;
		front=NULL;
		rear=NULL;
		return(item);
	}
	else
	{
		item=front->info;
		front=front->link;
		return(item);
	}
}
int main()
{

 string temp;
  int i,j,totwt=0,temp1,n,tq=0;
  float avgwt;
cout<<"Enter no of processes"<<endl;
	cin>>n;
	string p[n];
	int pt[n],pt1[n],tat[n],pr[n],ct[n],wt[n];
    rear=NULL;
	front=NULL;
  for(i=0;i<n;i++)
  {
cout<<"Enter process "<<i+1<<" name"<<endl;
 cin>>p[i];
cout<<"Enter process time"<<endl;
 cin>>pt[i];
 pt1[i]=pt[i];
cout<<"Enter priority"<<endl;
 cin>>pr[i];
  }
  cout<<"Enter the timq quantum for processes"<<endl;
  cin>>tq;


 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   if(pr[i]>pr[j])
 {
   temp1=pr[i];
 pr[i]=pr[j];
  pr[j]=temp1;
  temp1=pt[i];
  pt[i]=pt[j];
  pt[j]=temp1;
 temp=p[i];
 p[i]=p[j];
  p[j]=temp;

  temp1=pt1[i];
  pt1[i]=pt1[j];
  pt1[j]=temp1;
  }
    }
  }



  for(i=n-1;i>=0;i--)
  {
  enqueue(p[i]);
  }
	

for(int i=0;i<n;i++)
{
ct[i]=0;
wt[i]=0;
tat[i]=0;
}

  string y;
  int index,time=0;
  while(front!=NULL)
  {
  y=dequeue();
  for(i=0;i<n;i++)
  {
  if(p[i]==y)
  {
  index=i;
  break;
  }
  }
  if(pt[index]>0)
  {
  cout<<"Process "<<p[index]<<" running"<<endl;
  if(pt[index]>tq)
    {
      pt[index]=pt[index]-tq;
      cout<<p[index]<<" ran for "<<tq<<" time"<<endl;

      time=time+tq;
      if(pt[index]>0)
      {
      enqueue(p[index]);
      }

    }
  else{
 cout<<p[index]<<" ran for "<<pt[index]<<" time"<<endl;

 time=time+pt[index];
 cout<<"process "<<p[index]<<" end at the time "<<time<<endl;
 ct[index]=time;
  pt[index]=0;
   }
}
}

cout<<endl;

   for(int i=0;i<n;i++)
   {
   wt[i]=ct[i]-pt1[i];
   totwt=totwt+wt[i];
   }

cout<<"Name"<<"    "<<"PR"<<"    "<<"PT"<<"     "<<"CT"<<"     "<<"WT"<<endl;
for(int i=0;i<n;i++)
{
cout<<p[i]<<"      "<<pr[i]<<"      "<<pt1[i]<<"      "<<ct[i]<<"      "<<wt[i]<<endl;

}

   avgwt=totwt/n;
  cout<<"Total waiting time ="<<totwt<<endl<<" Average waiting time "<<avgwt<<endl;


}
