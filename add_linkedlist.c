#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};

//This function is use to create n number of linkedlist.
struct node *create(struct node *head,int n)
{
struct node *newnode,*ptr;
head=(struct node*)malloc(sizeof(struct node));
printf("Enter your data\n");
scanf("%d",&head->data);
ptr=head;
for(int i=1;i<n;i++)
{
newnode=(struct node*)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
newnode->next=NULL;
ptr->next=newnode;
ptr=ptr->next;
}
ptr=head;
return ptr;
}

//This function is use to convert linkedlist into number.
int lltono(struct node *head)
{
int num=0,temp=0;
while(head!=NULL)
{
num=num*10;
num=num+head->data;
head=head->next;
}
return num;
}

//This function is use to convert number into linkedlist.
struct node *notoll(int n)
{
struct node *head,*ptr,*nnode;
int num=0,rev=0,n1=0,temp=0;
n1=n;
while(n1>0)
{
rev=rev*10;
rev+=n1%10;
if(rev==0)
{
temp=1;
}
n1=n1/10;
}
n=rev;
head=(struct node*)malloc(sizeof(struct node));
num=n%10;
head->data=num;
n=n/10;
ptr=head;
while(n>0)
{
num=0;
num=n%10;
nnode=(struct node*)malloc(sizeof(struct node));
nnode->next=NULL;
nnode->data=num;
ptr->next=nnode;
ptr=ptr->next;
n=n/10;
}
if(temp==1)
{
nnode=(struct node*)malloc(sizeof(struct node));
nnode->next=NULL;
nnode->data=0;
ptr->next=nnode;
ptr=ptr->next;
}
ptr=head;
return ptr;
}

//This fuction is use to print linkedlist.
void printll(struct node *head)
{
while(head!=NULL)
{
printf("%d ",head->data);
head=head->next;
}
}

void main()
{
struct node *create(struct node *head,int n);
void printll(struct node *head);
int lltono(struct node *head);
struct node *notoll(int n);
struct node *head,*ptr,*newnode,*nptr,*newll;
int n,num1,num2,sum;

head=(struct node*)malloc(sizeof(struct node));
newnode=(struct node*)malloc(sizeof(struct node));

printf("Enter how many node you want to create in first linkedlist\n");
scanf("%d",&n);
ptr=create(head,n);

printf("Enter how many node you want to create in second linkedlist\n");
scanf("%d",&n);
nptr=create(newnode,n);

num1=lltono(ptr);
num2=lltono(nptr);

sum=num1+num2;
newll=notoll(sum);

printll(newll);

printf("\n");
}
