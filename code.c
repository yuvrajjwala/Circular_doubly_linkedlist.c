//CODE BY YUVRAJ JWALA


#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node * next;
    struct node * prev;
};


void display(struct node * head){
    struct node * ptr;
    ptr=head;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);

    printf("\nnext node of last node is : %d ",ptr->data);
    
}

void insertAtFirst(struct node * head , struct node * temp){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
    head=newnode;

    display(head);

}

void insertAtEnd(struct node * head ,struct node *temp){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("What you want to insert at end : ");
    scanf("%d",&newnode->data);
    temp->next=newnode;
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=temp;

    display(head);
}

void insertAtAnyIndex(struct node *head,int count){
    int index,m=1;
    struct node *newnode ,*ptr;
    printf("At What index you want to insert ");
    scanf("%d",&index);
    if(index>count){
        printf("Your index value exceeds the length :( ");
    }
    else{
        newnode=(struct node *)malloc (sizeof(struct node));
        printf("Enter data to insert : ");
        scanf("%d",&newnode->data);
        ptr=head;
        while(m<(index-1)){
            ptr=ptr->next;
            m++;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
        newnode->next->prev=newnode;
        newnode->prev=ptr;

    }
    printf("\nYour linked list is \n");
    display(head);
}

void DeleteAtFirst(struct node * head , struct node * temp ,int count){
    struct node * ptr;
    if (count<=1){
        printf("Linked list is Empty ");
    }
    else{
            ptr=head;
            head=ptr->next;
            ptr->next->prev=temp;
            temp->next=head;
            free(ptr);

    display(head);
    }
}

void DeleteAtEnd(struct node * head , struct node *temp,int count ){
    struct node * ptr;
    if(count<=1){
        printf("linked is Empty :( ");
    }
    else{
            ptr=head;
    while (ptr->next!=temp)
    {
        ptr=ptr->next;
    }
    ptr->next=head;
    head->prev=ptr;
    free(temp);

    display(head);
    }
    
}

void DelteFromAnyIndex(struct node * head,int count){
    int index,m=1;
    struct node *ptr,*nextnode;
    printf("Enter the index where you want to delete :  ");
    scanf("%d",&index);
    if(index>count){
        printf("\nSize of list exceeds :(  ");
    }
    else{
        ptr=head;
        nextnode=head->next;
        while (m<(index-1))
        {
            ptr=ptr->next;
            nextnode=nextnode->next;
            m++;
        }
        ptr->next=nextnode->next;
        nextnode->next->prev=ptr;
        free(nextnode);
    
        display(head);    
    }
}

void main(){
    struct node *newnode,*head,*temp;
    head=0; 
    int choice,count=0;
    while (choice){
        newnode=(struct node * )malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if (head==0)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        count++;
        printf("continue 1 0r 0 : ");
        scanf("%d",&choice);

    }
    temp->next=head;
    head->prev=temp;

// insertAtFirst(head,temp);
// insertAtEnd(head,temp);
// insertAtAnyIndex(head,count);
// DeleteAtFirst(head,temp,count);
// DeleteAtEnd(head,temp,count);
DelteFromAnyIndex(head,count);

//I defined all the functions so, you can perform any one you want 
}
