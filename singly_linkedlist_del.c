#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 struct node{
     int data;
     struct node *next;
 };
 struct node *start,*first,*second,*ptr,*newnode,*preptr,*temp;


int main()
{
   int ch,num,val;
   
start=(struct node *)malloc(sizeof(struct node));
first=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));

start->data=3;
first->data=4;
second->data=5;

start->next=first;
first->next=second;
second->next=NULL;

 ptr=start;

printf("\nprinting the linked list\n");
while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;


}



while(ch!=0){

printf("\n1.Delete begin\n2.Delete end\n3.Delete after\nenter your choice\n");
scanf("%d",&ch);

switch(ch){

    case 1: ptr=start;
           start=start->next;
           free(ptr);
           break;

    case 2: ptr=start;
            preptr=ptr;
           while(ptr->next!=NULL){
               preptr=ptr;
               ptr=ptr->next;
           }
           preptr->next=NULL;

           free(ptr);

            break;

    case 3: printf("enter the value to be deleted\n");
           scanf("%d",&num);
           ptr=start;
           preptr=ptr;
           while(preptr->data!=num){
               preptr=ptr;
               ptr=ptr->next;
           }
           temp=ptr;
           preptr->next=ptr->next;
           free(temp);
           break;
           
    default: printf("invalid choice entered");
              break;
}


printf("\nprinting the new linked list........\n");
ptr=start;
while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;
}

}

return 0;
}
