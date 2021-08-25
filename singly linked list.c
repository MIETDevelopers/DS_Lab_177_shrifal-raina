//Author: shrifal raina
//A C Program to perform singly linked list operations.               
#include<stdlib.h>
#include<stdio.h>

void insert();
void delete();
void display();
 
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
int main()     
{
    int choice, count=0;;
    while(1){
                printf("\n~Singly Linked List Operation~");
                printf("\n 1. Insert a node.");
                printf("\n 2. Delete a node");
                printf("\n 3. Display all nodes");
                printf("\n 4. Exit the proggram.");
                printf("\n Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\n~Implementing insert function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            insert();
                            count++;
                            break;
                    case 2:
                            printf("\n~Implementing delete function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            delete();
                            count--;
                            break;
                    case 3:
                            printf("\n~Implementing display function!~\n");
                            printf("\nNumber of nodes available: %d", count);
                            display();
                            break;    
                    case 4:
                            printf("Exiting the program!");
                            exit(0);
                            break;
                    default:
                            printf("n Wrong Choice:n");
                            break;
                }
        }
        return 0;
}

void insert()
{
    struct node *note,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space! :/ ");
        return;
    }
    printf("\nEnter the index value for the new node to be inserted: ");
    scanf("%d",&pos);
    printf("\nEnter the value of the node: ");
    scanf("%d",&temp->info) ;
  
    temp->next=NULL;
        if(pos==0)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            for(i=0,note=start;i<pos-1;i++) 
                { 
                    note=note->next;
                        if(note==NULL)
                        {
                            printf("\nPosition not found! :/");
                            return;
                        }
                }

                temp->next =note->next ;
                note->next=temp;
        }
}

void delete()
{
    int i,pos;
    struct node *temp,*note;
    if(start==NULL)
    {
        printf("\nThe List is Empty! :/");
        return;
    }
    else
    {
        printf("\nEnter the index value of the node to be deleted: ");
        scanf("%d",&pos);
            if(pos==0)
            {
                note=start;
                start=start->next ;
            
                printf("\nThe deleted node is: %d",note->info );
                    free(note);
            }
            else
            {
                note=start;
                for(i=0;i<pos;i++) 
                { 
                    temp=note; 
                    note=note->next;
                    if(note==NULL)
                    {
                        printf("\nNode not found :/");
                        return;
                    }
                }
                temp->next =note->next ;
                printf("\nThe deleted node is: %d",note->info);
            free(note);
            }
    }
}

void display()
{
    struct node *note;
    if(start==NULL)
    {
        printf("\nList is empty! :/");
        return;
    }
    else
    {
        note=start;
        printf("\nThe nodes in the list are: ");
        while(note!=NULL)
        {
            printf(" %d,",note->info );
            note=note->next ;
        }
    }
}

