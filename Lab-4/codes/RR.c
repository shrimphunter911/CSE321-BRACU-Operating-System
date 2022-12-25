#include<stdio.h>
struct process
{
    int id,at,bt,wt,tat,ct;
};

struct process a[10];

int q[100];
int start=-1;
int end=-1;

void insert(int n)
{
    if(start==-1)
     start=0;
    end=end+1;
    q[end]=n;
}

int delete()
{
    int n;
    n=q[start];
    start=start+1;
    return n;
}
int main()
{
    int n,tq,p,time=0;
    int temp[10],exist[10]={0};
    printf("Number of the process: ");
    scanf("%d",&n);
    printf("Enter Burst time\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].bt);
	a[i].at=0;
        a[i].id=i;
        temp[i]=a[i].bt;
    }
    printf("Enter quantum: ");
    scanf("%d",&tq);

    insert(0);
    exist[0]=1;

    while(start<=end)
    {
        p=delete();
        if(a[p].bt>=tq)
        {
            a[p].bt=a[p].bt-tq;
            time=time+tq;
        }
        else
        {
            time=time+a[p].bt;
            a[p].bt=0;
        }
        
        for(int i=0;i<n;i++)
        {
            if(exist[i]==0 && a[i].at<=time)
            {
                insert(i);
                exist[i]=1;
            }
        }

        if(a[p].bt==0)
        {
            a[p].tat=time-a[p].at;
            a[p].wt=a[p].tat-temp[p];
        }
        else
        {
            insert(p);
        }
    }
    for (int j=0; j<10; j++)
    {
	a[j].ct= a[j].at+a[j].tat;
    }
    
    printf("Process Waiting time Turn Around Completion time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t     %d\t\t %d\n",i+1,a[i].wt,a[i].tat,a[i].ct);
    }
    return 0;
}
