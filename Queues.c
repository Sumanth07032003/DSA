#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
typedef struct queue
{
    int data[100];
    int front;
    int rear;
}Q;

int main()
{
    int ch,x,d;
    Q Queue;
    Q *p;
    p=&Queue;
    p->front=-1;
    p->rear=-1;
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("Queuerand.txt","w");
    for(i=0;i<10;i++)
    {
        fprintf(fp1,"%d ",rand()%100);
    }
    fclose(fp1);
    fp1=fopen("Queuerand.txt","r");
    while(1)
    {
        printf("1.Enqueue\n 2.Dequeue \n 3.Display \n 4.Exit \n");
        printf("\n  Enter the option \n");
        scanf("%d",&ch);
        displayop(fp2,ch);
        switch(ch)
        {
            case 1:fscanf(fp1,"%d",&x);
                   enqueue(p,x);
                   fileEnqueue(fp3,x);
                   break;
            case 2:d=dequeue(p);
                   fileDequeue(fp4,d);
                   break;
            case 3:display(p);
                    break;
            case 4:exit(0);
                    break;
        }


    }
    fclose(fp1);



}

void displayop(FILE *fp2,int ch)
{
    fp2=fopen("OpeQueue.txt","a");
    char str1[]="Enqueue()";
    char str2[]="Dequeue()";
    if(ch==1)
    {
       fprintf(fp2,"%s\n",str1);
    }
    else if(ch==2)
    {
       fprintf(fp2,"%s\n",str2);
    }
    fclose(fp2);
}

void enqueue(Q *p,int x)
{
    if(p->rear==100-1)
    {
        printf("\n Queue overflow \n");
    }
    else
    {
        if(p->front==-1)
        {
            p->front=0;
        }
        p->rear++;
        p->data[p->rear]=x;
        printf("\n %d--\n",x);
    }
}

int dequeue(Q *p)
{
    int x;
    if(p->front==-1 | p->front > p->rear)
    {
        printf("\n Queue is empty \n");
    }
    else
    {
        x=p->data[p->front];
        p->front++;
        return x;
    }
}

void display(Q *p)
{
    if(p->front==-1 | p->front > p->rear)
    {
        printf("\n Queue is empty \n");
    }
    else
    {
        for(i=p->front ; i<=p->rear;i++)
        {
            printf("%d \n",p->data[i]);
        }
    }
}

void fileEnqueue(FILE *fp3,int x)
{
    fp3=fopen("Enqueue.txt","a");
    fprintf(fp3,"%d\n",x);
    fclose(fp3);
}

void fileDequeue(FILE *fp4,int d)
{
    fp4=fopen("Dequeue.txt","a");
    fprintf(fp4,"%d\n",d);
    fclose(fp4);
}


