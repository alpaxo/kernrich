#include <stdio.h>

int main(int argc, char *argv[]){
	printf("%p%s", &argc, "\n");
	printf("%p%s", *argv, "\n");
	// print args
	while(--argc > 0){
		printf("%s%s", *++argv, argc > 1 ? " " : "\n");
	}
	//
	int x=10, y=20, z = 0;
	int *ptr1, *ptr2, *ptr3;
	ptr1 = &x;
	ptr2 = ptr1;				// points to @x
	ptr2 = &y;					// points to @y
	printf("ptr1addr:\t%p\n", ptr1);	//	@x address;
	printf("ptr2addr:\t%p\n", ptr2);	//	@y address
	printf("ptr1!addr:\t%p\n", &ptr2);	//	@ptr2 address
	printf("ptr2!addr:\t%p\n", &ptr2);	//	@ptr2 address
	printf("ptr1val:\t%i\n", *ptr1);	//
	printf("ptr2val:\t%i\n", *ptr2);	//
	printf("x:val\t\t%i\n", x);
	printf("tabs\11\0112\n");
	printf("y:val\t\t%i\n", y);
	printf("\n");
	//char *arr[] = {x,y};				// segfault at (*arr)[0]
	int *arr[] = {ptr1, y};				// array of pointers(?)
	//
	int *lnk = &arr[1];

	printf("arr\n");
	printf("addr\t\t%p\n", arr);		//	&arr[0] address
	printf("---\n");
	printf("0val\t\t%i\n", (*arr)[0]);	//	arr[0] value
	printf("1val\t\t%i\n", (*arr)[1]);	//	arr[1] value
	printf("---\n");
	printf("0val\t\t%p\n", arr[0]);		//	arr[0] address
	printf("1val\t\t%p\n", arr[1]);		//	arr[1] value
	printf("---\n");

	printf("arr\t\t%i\n", *(*(arr+0)));	// 	*(arr+0) - address; *address = value. **arr is same
	printf("arr\t\t%i\n", *(arr+1));	// 	arr[1] value
	printf("arr\t\t%i\n", *lnk);		//

	return 0;
}