#include<stdio.h>
int stack[100],top=-1,i;
void push();
void pop();
void display();
int main()
{
	int input,MAX;
    printf("\nEnter stack size: Max 100");
    scanf("%d",&MAX);

    while(1){
        printf("\nEnter the Choice:\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                	push(MAX);
                	break;
            case 2:
               		pop(MAX);
                	break;
            case 3:
                	display(MAX);
                	break;
            case 4:
                	return 0;
                	break;
        }
    }
}

void push(int MAX){
    int element;
            
    if(top==MAX-1)
        printf("Stack is overflowing");

    else{
        printf("Enter element to be pushed:");
        scanf("%d",&element);
            top++;
            stack[top]=element;
        }
    }


void pop(int MAX){
    int element;
    if(top==-1)
        printf("Stack is empty");

    else{
        printf("Popped element=%d",stack[top]);
        top--;
    }
}

void display(int MAX){
    int element;
    if(top==-1)
        printf("Stack is empty");

    else{
        printf("Elements:\n");
        for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);   
    }
}
