import java.io.*;
import java.util.*;
import java.lang.*;
class Bankers
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter no. of processes:");
		int n=sc.nextInt();
		int i,j;
		System.out.println("Enter MAX matrix");
		int max[][]=new int[n][3];
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				max[i][j]=sc.nextInt();
			}
		}
		System.out.println("Enter ALLOCATION matrix");
		int alloc[][]=new int[n][3];
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				alloc[i][j]=sc.nextInt();
			}
		}	
		System.out.println("Enter AVAILABLE row");
		int avail[]=new int[3];
		int work[]=new int[3];
		for(i=0;i<3;i++){
		avail[i]=sc.nextInt();
		work[i]=avail[i];
		}
		System.out.println("NEED matrix is:");
		int need[][]=new int[n][3];
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				need[i][j]=Math.abs(max[i][j]-alloc[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				System.out.print(need[i][j]+" ");
			}
			System.out.println();
		}
		boolean visited[]=new boolean[n];
		int safeq[]=new int[n];	
		int k=0,count=0,c=0;
		boolean flag=false;
		while(count<n)
		{
			int initwork[]=work;
			c++;
			for(i=0;i<n;i++)
			{
				for(j=0;j<3;j++)
				{
					if(!visited[i])
					{
					if(need[i][j]>work[j])
					break;
					}
				}
				if(j==3 && !visited[i])
				{
					count++;
					visited[i]=true;
					safeq[k++]=i+1;
					for(j=0;j<3;j++)
					work[j]+=alloc[i][j];
				}	
			}
			if(c==n)
			{	
				for(j=0;j<3;j++)
				{
				if(work[j]!=initwork[j])
				break;
				}
				if(j==3)
				{
				flag=true;
				break;
				}
			}
		}
		if(flag==true)
		{
		System.out.println("Deadlock! No safe sequence is possible");
		}
		else
		{
			System.out.println("Safe sequence is: ");
			for(i=0;i<n;i++)
			System.out.print("P"+safeq[i]+" ");
			System.out.println();
		}
	}
}
		
		
