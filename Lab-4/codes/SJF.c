#include<stdio.h>
struct process
{
    int wt,at,bt,tat,ct;
};

struct process a[10];

int main()
{
    int n,temp[10];
    int count=0,t=0,srt;
    printf("Number of the process: ");
    scanf("%d",&n);
    printf("Enter Arrival and Burst time\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].at,&a[i].bt);
        temp[i]=a[i].bt;
    }
    a[9].bt=100000;
    
    for(t=0;count!=n;t++)
    {
        srt=9;
        for(int i=0;i<n;i++)
        {
            if(a[i].bt<a[srt].bt && (a[i].at<=t && a[i].bt>0))
            {
                srt=i;
            }
        }
        a[srt].bt=a[srt].bt-1;
        
        if(a[srt].bt==0)
        {
            count++;
            a[srt].wt=t+1-a[srt].at-temp[srt];
            a[srt].tat=t+1-a[srt].at;
        }
    }
    for (int j=0; j<10; j++)
    {
	a[j].ct= a[j].at+a[j].tat;
    }
    
    printf("Process Waiting Time Turn Around Completion Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t     %d\t\t %d\n",i+1,a[i].wt,a[i].tat,a[i].ct);
    }
    return 0;
}