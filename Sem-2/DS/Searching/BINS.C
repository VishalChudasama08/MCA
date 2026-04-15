// binary search | long n

#include<stdio.h>
#include<conio.h>



int main(){
	int i, result, target, arr[] = {1,2,3,4,5,6,7,8,9,10};
	clrscr();

	printf("\n\tArray: ");
	for(i=0;i<10;i++)
		printf("  %d", arr[i]);

	printf("\n\tEnter value you want to found: ");
	scanf("%d", &target);
	result = binarysearch(arr, target);

	if(result == -1){
		printf("\n\tvalue not found");
	} else {
		printf("\n\tvalue found at %d index", result);
	}

	getch();
	return 0;
}

int binarysearch(int arr[], int target){
	int mid;
	int start=0, end=9;
	while(start<=end){
		mid = (start+end)/2;
		if(arr[mid]==target)
			return mid;
		else if(arr[mid] < target)
			start = mid+1;
		else
			end = mid-1;
	}
	return -1;
}