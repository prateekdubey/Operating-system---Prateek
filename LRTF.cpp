#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{      int n;
    cout<<"***************************LRTF-Longest Remaining Time First****************************\n";
    cout<<"\t\t\t **According to question the Arrival time of the process must be same**\n";
    cout<<"\t\t\t **Conflict must be broken by giving priority to process with smallest pid**\n";
   cout<<"enter number of processes";
   cin>>n;
	int pid[n],arrival[n],burst[n],sum_burst=0,count=0,inc=0,max,i,ct[n],max_element_index;
	int maxx_index[n],j=0;
	 int minn,k,h,min_index=0,tat[n],temp_burst[n],wait[n];
	 double total_tat=0,total_wait=0;
	 int temp_arrival[n],temp_pid[n];
	for(i=0;i<n;i++)
	{     cout<<"enter pid";
		cin>>pid[i];
		temp_pid[i]=pid[i];
		cout<<"enter arrival time";
		cin>>arrival[i];
		temp_arrival[i]=arrival[i];
		cout<<"enter burst time";
		cin>>burst[i];
		temp_burst[i]=burst[i];
		sum_burst=sum_burst+burst[i];
	}
	sum_burst=min(arrival[0],arrival[n-1])+sum_burst;
	
	count=min(arrival[0],arrival[n-1]);
	while(count<=sum_burst)
	{  
        
       
        max=burst[0];
		for(i=0;i<n;i++)
		{
			if(burst[i]>max)
			{
				max=burst[i];
						}
             		
		}
		for(i=0;i<n;i++)
		{
			if(burst[i]==max)
			{ maxx_index[j]=i;
			        j++;
			    	}
		}
		if(j==1)
		{   
			max_element_index=maxx_index[0];
			if(burst[max_element_index]!=0){
			
			burst[max_element_index]=burst[max_element_index]-1;
			count++;
			
		
			if(burst[max_element_index]==0)
			{   
				ct[max_element_index]=count;
	
			tat[max_element_index]=ct[max_element_index]-arrival[max_element_index];
				j=0;
			}
			else{
				j=0;
			}}
			
					}
		else{
				
	   
	    h=maxx_index[0];
		minn=pid[h];
		for(i=0;i<j;i++)
		{
			k=maxx_index[i];
			if(pid[k]<minn)
			{   
			minn=pid[k];
					}
		}
		for(i=0;i<n;i++)
		{
			if(pid[i]==minn)
			{
				min_index=i;
			}
		} 
		if(burst[min_index]!=0){
			
		burst[min_index]=burst[min_index]-1;
		count++;
		
	
		if(burst[min_index]==0)
		{   
			ct[min_index]=count;

			tat[min_index]=ct[min_index]-arrival[min_index];
		    
			j=0;
			
			
		}else
		{ j=0;
		}
	
		}
	
		
	}
	
	
	}
	for(int m=0;m<n;m++)
	{ total_tat=total_tat+tat[m];  
	 wait[m]=tat[m]-temp_burst[m];
	   total_wait=total_wait+wait[m];  
		
	}
	cout<<"pid"<<"*"<<"arrival time"<<"*"<<"burst time"<<"*"<<"completion time"<<"*"<<"Turn around time"<<"*"<<"waiting time"<<"\n";
	for(int t=0;t<n;t++)
	{
		
		cout<<temp_pid[t]<<"   *"<<temp_arrival[t]<<"*           *"<<temp_burst[t]<<"*         *"<<tat[t]+temp_arrival[t]<<"*             *"<<tat[t]<<"*              *"<<wait[t]<<"\n";
			}
		
	cout<<"\n\n average turn around time"<<total_tat/n<<"\n";
    cout<<"average waiting time"<<total_wait/n;

}
