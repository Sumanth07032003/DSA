// program to generate random numbers based on the input in the file then  sort and display in another file.
#include<stdio.h>
#include<stdlib.h>
int i,j,n,temp;
void read(FILE *fp1,int n,int a[])
{
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&a[i]);

    }
}
void sort(FILE *fp,int n,int a[])
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-1-i;j++)
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
void display(FILE *fp2,int n, int a[])
{
    for(i=0;i<n;i++)
    {
        fprintf(fp2," %d",a[i]);
        printf("%d ",a[i]);
    }
}
void main()
{
    int a[1000];
    FILE *fp1,*fp2;
    fp1=fopen("file1.txt","r");
    fscanf(fp1,"%d",&n);
    fclose(fp1);
    fp1=fopen("file1.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp1," %d",rand());
    }
    fclose(fp1);
    fp1=fopen("file1.txt","r");
    read(fp1,n,a);
    sort(fp1,n,a);
    fclose(fp1);
    fp2=fopen("abcd.txt","w");
    display(fp2,n,a);
    fclose(fp2);


}
