//A program to check if a given expression is correctly parenthesized using Stacks

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30
int top=-1;
int stack[MAX];

void push(char);
char pop();
int match(char a,char b);
int check(char []);

int main()
{
    char exp[MAX];
    int valid, ch;
   
        
	do
    {	
        printf("\nSelect Your choise\n\n");
        printf("Enter 1 to Check for Balanced Parentheses  \n Enter 2 to EXIT the Program \n");
        	scanf("%d", &ch);
		
        switch (ch) 
		{
		
			case 1: printf("Enter an algebraic expression : ");
   					scanf("%s", exp);
					valid=check(exp);
        			if(valid==1)
                		printf("Valid expression\n");
        			else
                		printf("Invalid expression\n");
                	break;
			case 2:
            		printf("You have succesfully exited the Program");
           		    exit(0);
                
        	default:
            		printf("The choise is not available ");
                	break;
        
        	return 0;

        }       
	}while (ch != 2);
}

int check(char exp[] )
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        	push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        	if(top==-1)    
        	{
            	printf("Right parentheses are more than left parentheses\n");
            	return 0;
   	    	}
        	else
        	{
            	temp=pop();
            	if(!match(temp, exp[i]))
                {
                    printf("Mismatched parentheses are : ");
                    printf("%c and %c\n",temp,exp[i]);
                    return 0;
           	    }
        	}
    }
        if(top==-1) 
        {
            return 1;
        }
        else
        {
   		    printf("Left parentheses more than right parentheses\n");
            return 0;
        }
}

int match(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
        
    return 0;
}

void push(char item)
{
    if(top==(MAX-1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}

char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stack[top--]);
}
