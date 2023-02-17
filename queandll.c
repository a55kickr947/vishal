#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
 {
  int ph;
  char name[20];
  char usn[10];
  char branch[20]; 
  struct node *link;
};
 struct node *front=0;
 struct node *rear=0;
  void enqueue(int ph,char name[20],char usn[10],char branch[20])
 {
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->ph=ph;
  strcpy(newnode->name,name);
  strcpy(newnode->usn,usn);
  strcpy(newnode->branch,branch);
  newnode->link=0;
  if(front==0 && rear==0)
{
 front=rear=newnode;
}
 else
  {
   rear->link=newnode;
   rear=newnode;
 }
}
  void display()
 {
  struct node *temp;
  temp=front;
  if(front==0&&rear==0)
 {
  printf("\nunderflow\n");
 }
  while(temp!=NULL)
{
 printf("\nname=%s\nBranch=%s\nUSN=%s\nPhone number=%d",temp->name,temp->branch,temp->usn,temp->ph);
 temp=temp->link;
}
}
 void dequeue()
{
 struct node *temp;
 temp=front;
 if(front==0)
{
 printf("\nunderflow\n");
}
else{

 
  front=front->link;
  free(temp);
}
 }
/*else{

  printf("\nName=%s\nUSN=%s\nBranch=%s\nPhone number=%d",temp->name,temp->usn,temp->branch,temp->ph);
  front=front->link;
  free(temp);
}
 }*/
  void main()
{
 int n,choice,ph;
 char name[20],usn[10],branch[20];
  while(1)
{
 printf("\nMenu\n1.Enqueue\n2.Display\n3Dequeue\n4.Exit");
 printf("\nenter the choice");
 scanf("%d",&choice);
    switch(choice)
 {
 case 1: printf("\nenter the number of nodes");
         scanf("%d",&n);
         for(int i=0;i<n;i++)
         {
 	  printf("\nenter the phonno");
	  scanf("%d",&ph);
	  printf("\nenter the name");
	  scanf("%s",name);
	  printf("\nenter the usn");
	 scanf("%s",usn);
	printf("\nenter the branch"); 
	scanf("%s",branch);
     enqueue(ph,name,usn,branch);
        }
         break;

case 2:display();
        break;
case 3: dequeue();
         break;


case 4:exit(1);
default:printf("invalid");
  }
 }
}
