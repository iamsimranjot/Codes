#include<stdio.h>

void main()
{

	int n , arr[100] , end , mid , beg , i , j , item , count = 0;

	printf("Enter the number of elements : ");
	scanf("%d" , &n);

	printf("Enter the elements : ");

	for(i = 0 ; i < n ; i++)
	{
		scanf("%d" , &arr[i]);
	}

	printf("Enter the number you want to search : ");
	scanf("%d" , &item);

	beg = 0;
	end = n - 1;
	mid = (beg + end) / 2;


	while(beg <= end)
	{
		if(arr[mid] == item)
			{
				printf("The item was found at %d location\n\n" , mid + 1);
				break;
				count++;
			}

		else if(item > arr[mid])
		{
			beg = mid + 1;
			mid = (beg + end) / 2;
		}

		else if(item < arr[mid])
		{
			end = mid - 1;
			mid = (beg + end) / 2;
		}
	}

	if(count == 0)
	{
		printf("Entered Item Not Found\n\n");
	}
}
				
