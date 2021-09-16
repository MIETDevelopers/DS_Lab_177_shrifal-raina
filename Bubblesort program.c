//Author:shrifal raina
//Date of creation: 9 sept 2021
//Purpose: C program (with proper comment line) to compare the running times (in milliseconds) 
//of Bubble Sort and Merge Sort for the following array:{1,3,42,2,41,66,66,33,98,0}
#include<stdio.h>//header file for standard input and output
#include<time.h>//header file which includes functions to calculate time
#define max 100
int arr[max], n;//Variable declaration
//Function prototypes
void bubblesort();
void mergeSort(int, int);
void merge(int, int, int);
void display();
void input();
int main()//main function or main body of the program
{
	int choice;//Variable declaration
	clock_t start_t, end_t;//it is typedef for long int and used to store 
	//the processor time in terms of the number of CPU cycles passed
	double total_t1, total_t2;

	printf("(:  Welcome  :)\n");
	do{
			printf("Main Menu\n");
			printf("Press 1 for bubble sort\n");
			printf("Press 2 for merge sort\n");
			printf("Press 3 to exit\n");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
					input();//function to take input from the user
					start_t=clock();//clock() function to calculate time 
					printf("Array before sorting\n");
					display();//function to display elements in the array
					printf("\n");
					bubblesort();//bubble sort function call
					printf("Array after sorting\n");
					display();
					end_t=clock();//end_t will store the finishing time of the execution
					printf("\n");
					printf("\n");
					total_t1 = (double)(end_t - start_t) / CLOCKS_PER_SEC;//this is the formula to calculate the total time
					// consumed by bubble sort stored in total_t1
					printf("Execution Time=%f\n",total_t1);
					break;

				case 2:
					input();//function to take input from the user
					start_t=clock();//clock() function to calculate time 
					printf("Array before sorting\n");
					display();//function to display elements in the array
					printf("\n");
					mergeSort(0, n-1);//merge sort function call
					printf("Array after sorting\n");
					display();
					end_t=clock();//end_t will store the finishing time of the execution
					printf("\n");
					printf("\n");
					total_t2 = (double)(end_t - start_t) / CLOCKS_PER_SEC;//this is the formula to calculate the total time
					// consumed by bubble sort stored in total_t1
					printf("Execution Time=%f\n",total_t1);
					break;

				case 3:
					printf("Thanks visit again\n");
					break;

				default:
					printf("Enter a valid choice\n");	

			}
	  }while(choice!=3);
	  printf("Execution Time for bubble sort=%f\n",total_t1);
	  printf("Execution Time for merge sort=%f\n",total_t2);
}

void display()//display function definition
{
	for (int i = 0; i < n; i++)//displaying elements with the help of for loop
	{
		printf("%d\t",arr[i]);
	}
}

void input()//input function definition
{
	printf("Enter the number of elements(Hint: 10)\n");
	scanf("%d",&n);
	printf("Enter the elements(Hint: {1,3,42,2,41,66,66,33,98,0})\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
}

void bubblesort()//bubble sort function definition
{
	int temp;
	for (int i = 0; i < n-1; i++)//this loop is for the number of passes
	{
		for (int j = 0; j < n-1-i; j++)//this loop is for number of comparison in every pass 
		{
			if (arr[j]>arr[j+1])//let us suppose j=1 then j+1=2, so if the value at index j i.e. 1 is less than value at index j+1 i.e. 2
			{//then we will swap the values
				temp=arr[j];//first we will store the value at index j in a temporary variable
				arr[j]=arr[j+1];//coming further we copy the value at index j+1 in j
				arr[j+1]=temp;//then we will copy the value of temporary variable at the index j+1 
			}//this way we will swap the values
		}
	}
}

void mergeSort(int l, int r)//recursive function
{
	int m;//m is the mid point of the array

	if (l < r)//if the first index i.e. 0 here is l is less than the last index i.e. n-1 here is r
	{
		m = (l+r)/2;//initialising m
		// call mergeSort() for left subarray

		mergeSort(l, m);
		// call mergeSort() for right subarray

		mergeSort(m+1, r);
		// merge the left and right subarrays

		merge(l, m, r);//to merge all the arrays when the are sorted
	}
}

void merge(int l, int m, int r)//merge function definition
{
	int n1 = m-l+1;//varaible declaration and initialisation
	int n2 = r-m;	//r-(m+1)+1; varaible declaration and initialisation
	int L[n1], R[n2];
	int i,j,k;
	/* Copy data to temp arrays L[] and R[] */
    	for (i = 0; i < n1; i++)//this loop is for copying the data from array with index 0 to the mid in the left subarray 
        {
        	L[i] = arr[l + i];
    	}
    	for (j = 0; j < n2; j++)//this loop is for copying the data from array with index mid to the last in the right subarray 
    	{
    	    	R[j] = arr[(m + 1) + j];
		}
		i = 0; // Initial index of first or left subarray
    	j = 0; // Initial index of second or right subarray
   		k = l; // Initial index of merged subarray
    	
    	while(i<n1 && j<n2)//checking the condition if index of left and right subarray is less than total number of elements in both array
    	{
    		if (L[i]<=R[j])//comparing the values of left and right sub array and copying the values in the original array
    		{
    			arr[k] = L[i];
    			i++;
    		} 
    		else
    		{
    			arr[k] = R[j];
    			j++;
    		}
    		k++;
    	}
   	 	while (i < n1)
   	  	{ //if right is empty
    	    arr[k] = L[i];//then we will copy all the values of left subarray in the original array 
    	    i++;
    	    k++;
   		}
    	while (j < n2)
     	{ //if left is empty
    	    arr[k] = R[j];//then we will copy all the values of right subarray in the original array 
    	    j++;
    	    k++;
   		}
}

/*Q.Which algorithm is faster and why? (Write a complete explanation using comment line into the same .c program file) 
Ans. During execution both sorting algorithm took same time i.e. 0.002000 but on paper merge sort is faster and more efficient in
big grouped data.The bubble sort is better than merge sort in practice for small set of data, but as size of input data increases,
the performance of bubble sort suddenly drop down and the exact opposite behavior I found with merge sort.  */ 

