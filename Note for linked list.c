//Author:Shrifal raina
#include<stdio.h>  
#include<stdlib.h>

struct node   
{  
    int data;  
    struct node *next;
};  
struct node *head=NULL; //Creating head note for the linkedlist 
    
void insert_at_end();   
void delete_at_end();   
void display();  
void search();  

int main ()  // Main Function body
{  
    int choice =0;  
    while(choice != 5)   
    {  
        printf("\n\n****Main Menu****\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert at last\n2.Delete from last\n3.Search for an element\n4.Show\n5.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:    
                    insert_at_end();         
                    break;  
            case 2:  
                    delete_at_end();        
                    break;  
            case 3:  
                    search();         
                    break;  
            case 4:  
                    display();        
                    break;  
            case 5:  
                    exit(0);  
                    break;  
            default:  
                    printf("The choice is not available");  
        }           break;
            return 0;
    }  
}  
 
void insert_at_end()  
{  
    //creating two pointer variables to hold adresses for nodes, 
    //first node (*note) to hold data and 
    //second node (*value) for address traversal 

    struct node *note,*value;  
    int element;     
    
    note = (struct node*)malloc(sizeof(struct node));
	    
    if(note == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&element);  
        note->data = element;
        note->next = NULL;  
        if(head == NULL)  
        {  
            head = note;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            head = value;  
            while (value -> next != NULL)  
            {  
                value = value -> next;  
            }  
            value->next = note;   
            printf("\nNode inserted");     
        }  
    }  
}  

 
void delete_at_end()  
{  
    struct node *note,*note1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        note= head;   
        while(note->next != NULL)  
        {  
            note1 = note;  
            note = note ->next;  
        }  
        note1->next = NULL;  
        free(note);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  

void search()  
{  
    struct node *note;  
    int element,i=0,temp;  
    note = head;   
    if(note == NULL)     
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter Element which you want to search?\n");   
        scanf("%d",&element);  
        while (note!=NULL)  
        {  
            if(note->data == element)  
            {  
                printf("Element found at location %d ",i+1);  
                temp=0;
                break;  
            }   
            else  
            {  
                temp=1;  
            }  
            i++;  
            note = note -> next;  
        }  
        if(temp==1)  
        {  
            printf("Element not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *note;  
    note = head;   
    if(note == NULL)  
    {  
        printf(" Empty note");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (note!=NULL)  
        {  
            printf("\n%d",note->data);  
            note = note -> next;  
        }  
    }  
}
