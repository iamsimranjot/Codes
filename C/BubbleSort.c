#include<stdio.h>

void main()
{
	int n , arr[100] , i , j , k , temp , count = 0 , pass;

	printf("Enter the Number of elements : ");
	scanf("%d" , &n);

	printf("Enter the Elements :");

	for(i = 0 ; i < n ; i++)
	{
		scanf("%d" , &arr[i]);
	}

	
	printf("Enter the pass after which you want to see array :");
	scanf("%d" , &pass);

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n-1 ; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
				
				if(count == 10)
				{
					printf("\nArray after 10th Exchange is \n");
					for(k = 0 ; k < n ; k++)
					{
						printf("%d  " , arr[k]);
					}
				}
			}
		}
		if(i == pass)
		{
			printf("\nArray after %d Pass is : \n" , pass);
			for(k = 0 ; k < n ; k++)
			{
				printf("%d  " , arr[k]);
			}
		}
	}

}
			
