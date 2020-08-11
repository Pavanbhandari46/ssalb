#include<stdio.h>

void RR()
{
        int nofp,a[10],b[10],tquantum,pq[20],totaltime=0,pno=0,pqindex=-1,padded[10]={0},c[10],bcopy[10]={0};
        int avgwt[10],avgtt[10],sum1w=0,sum2t=0;
        printf("\nEnter the number of processes:");
        scanf("%d",&nofp);
        printf("\nEnter time quantum");
        scanf("%d",&tquantum);
        printf("\nEnter the arrival and burst times");
        printf("\n\tProcess");
        for(int i=0;i<nofp;i++)
        {
                printf("\n\t P%d\t\tArrival time:",i+1);
                scanf("%d",&a[i]);
                printf("\n\t\t\tBurst time: ");
                scanf("%d",&b[i]);
                bcopy[i]=b[i];
                totaltime+=b[i];
         }
         for(int bc=0;bc<20;bc++)
         pq[bc]=99;
         for(int i=0;i<totaltime;)
         {
                pqindex++;
                for(int j=0;j<nofp;j++)
                {
                    if(i>=a[j] && padded[j]!=1)
                    {
                    pq[pno++]=j;
                    padded[j]=1;
                    printf("\nProcess added: %d",j+1);
                    }
                }
         if(pq[pqindex]==99)
         {
                printf("\n\tProcessor idle @ time : %d",i);
                pqindex--;
                i++;
                totaltime++;
                continue;
         }
         b[pq[pqindex]]-=tquantum;
         if(b[pq[pqindex]]>0)
         {
                i+=tquantum;
                for(int j=0;j<nofp;j++)
                {
                        if(i>=a[j] && padded[j]!=1)
                        {
                                pq[pno++]=j;
                                padded[j]=1;
                        }
                 }
                 pq[pno++]=pq[pqindex];
          }
          else
          {
                printf("\nProcess completed: %d",pq[pqindex]+1);
                if(b[pq[pqindex]]<0)
                i+=(tquantum+b[pq[pqindex]]);
                else
                i+=tquantum;
                c[pq[pqindex]]=i;
          }
        }
        printf("\nProcess queue: ");
        for(int i=0;i<pno;i++)
        printf("\t%d",pq[i]+1);
        printf("\n\n\nProcess\t\tA.T\t\tB.T\t\tC.T\t\tT.T\t\tW.T");
        for(int i=0;i<nofp;i++)
        {
                printf("\n\n P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",i+1,a[i],bcopy[i],c[i],c[i]-a[i],c[i]-a[i]-bcopy[i]);
         }
         for(int i=0;i<nofp;i++)
         {
                avgwt[i]=c[i]-a[i]-bcopy[i];
                avgtt[i]=c[i]-a[i];
         }
         for(int i=0;i<nofp;i++)
         {
                sum1w+=avgwt[i];
                sum2t+=avgtt[i];
         }
         printf("\nAverage turnaround time=%f",sum2t/(float)nofp);
         printf("\nAverage waiting time=%f",sum1w/(float)nofp);
}    
void SRTF()
{
        int a[10],b[10],x[10],i,j,smallest,count=0,time,n;
        int wt[10],tt1[10];
        double avg=0,tt=0,end;
        printf("Enter number of processes");
        scanf("%d",&n);
        printf("Enter arrival times:");
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("Enter burst times:");
        for(i=0;i<n;i++)
        scanf("%d",&b[i]);
        for(i=0;i<n;i++)
        x[i]=b[i];
        b[9]=999;
        for(time=0;count!=n;time++)
        {
                smallest=9;
                for(i=0;i<n;i++)
                {
                        if(a[i]<=time && b[i]<b[smallest] && b[i]>0)
                        smallest=i;
                 }
                 b[smallest]--;
                 if(b[smallest]==0)
                 {
                        count++;
                        end=time+1;
                        avg=avg+end-a[smallest]-x[smallest];
                        tt=tt+end-a[smallest];
                        wt[smallest]=end-a[smallest]-x[smallest];
                        tt1[smallest]=end-a[smallest];
                 }
         }
         printf("Process\tWaiting time\tTurn around time\n");
         for(i=0;i<n;i++)
         printf("%d\t\t%d\t\t%d\n",i+1,wt[i],tt1[i]);
         printf("\nAverage waiting time=%f",avg/(float)n);
         printf("\nAverage Turnaround time=%f",tt/(float)n);        
        
}
int main()
{
        int ch;
        while(1)
        {
        printf("Enter\n1.SRTF\n2.RR\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:SRTF();
                        break;
                case 2:RR();
                        break;
                case 3:exit(0);
        }
        }
}
