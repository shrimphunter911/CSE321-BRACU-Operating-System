#include <stdio.h>

struct priority
{
    int at, bt, prio, wt, tat, ct;
};

struct priority arr[10];

int main(){
    int n;
    printf("Number of the process: ");
    scanf("%d",&n);
    printf("Enter Arrival, Burst and Priority time\n");
    int temp_arr[10], t, count=0, srt;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&arr[i].at,&arr[i].bt,&arr[i].prio);
        temp_arr[i]=arr[i].bt;
    }
    
    arr[9].prio=100000;
   
    for(t=0;count!=n;t++)
    {
        srt=9;
        for(int i=0;i<n;i++)
        {
            if(arr[srt].prio>arr[i].prio && arr[i].at<=t && arr[i].bt>0)
            {
                srt=i;
            }
        }
       
        arr[srt].bt=arr[srt].bt-1;
        if(arr[srt].bt==0)
        {
            count++;
            arr[srt].wt=t+1-arr[srt].at-temp_arr[srt];
            arr[srt].tat=t+1-arr[srt].at;
           
        }
    }
    
    for (int k=0; k<n; k++)
    {
	arr[k].ct= arr[k].at+arr[k].tat;
    }
    printf("Process Waiting time Turn Around Completion time\n");
    for(int j=0;j<n;j++)
    {
        printf("%d\t%d\t     %d\t\t %d\n",j+1,arr[j].wt,arr[j].tat,arr[j].ct);
    }

    return 0;
}