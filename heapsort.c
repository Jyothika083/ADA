#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    while(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    while (r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
    
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void heapsort(int a[],int n)
{
    int i;
    //create max heap
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }

    //sort using deletion
    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

void main()
{
    int a[20],n,i,j;
    clock_t st,et;
    float ts;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st=clock();
    heapsort(a,n);
    et=clock();
    ts=(float)(et-st)/CLOCKS_PER_SEC;
    printf("\nAfter sorting elements are\n");
    print(a,n);
    printf("\nTime taken \t %f ",ts);

}
