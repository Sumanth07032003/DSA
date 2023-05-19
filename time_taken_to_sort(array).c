#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
void read(FILE *fp,int a[],int n)
{
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
}
void random(FILE *fp,int n)
{
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand()%100);
    }
}
void sort(int a[],int n)
{
    int temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-i-1;j++)
        {
            if(a[i]>a[j])
            {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
            }
        }
    }
}
int main()
{
    time_t t1,t2,t;
    int a[100000],n;
    FILE *fp,*fp1;
    printf("\n Enter value of n \n");
    scanf("%d",&n);
    fp=fopen("file.txt","w");
    random(fp,n);
    fclose(fp);
    fp=fopen("file.txt","r");
    read(fp,a,n);
    fclose(fp);
    t1=time(NULL);
    sort(a,n);
    t2=time(NULL);
    t=t2-t1;
    fp1=fopen("file1.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp1,"%d ",a[i]);
    }
    fclose(fp1);
    printf("\n TIME TAKEN = %d \n",t);
}
