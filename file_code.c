//Write a program to take input from one file and sort or  perform any operation and send it to another file.
#include<stdio.h>
int i,j;
void read(FILE *fp,int n,int a[100])
{
    int i;
    for(i=0;i<n;i++)
    {
      fscanf(fp,"%d",&a[i]);
    }
}
void sort(FILE *fp2,int a[],int n)
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
    for(i=0;i<n;i++)
    {
        fprintf(fp2,"%d,",a[i]);
    }

}
void main()
{
    int i,a[100],n;
    FILE *fp1,*fp2;
    fp1=fopen("file.txt","r");
    fscanf(fp1,"%d",&n);
    read(fp1,n,a);
    fclose(fp1);
    fp2=fopen("ABC.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp2,"%d",a[i]);
    }
    fprintf(fp2,"\n");
    sort(fp2,a,n);
    fclose(fp2);

}
