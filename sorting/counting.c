#include<stdio.h>

void countsort(int a[],int n,int i,int max);

int main()
{
    int a[50],n,i,max;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    max=a[0];

    for(i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];

    countsort(a,n,0,max);

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

void countsort(int a[],int n,int i,int max)
{
    int j,k=0,c[100]={0};

    if(i>max)
        return;

    for(j=0;j<n;j++)
        if(a[j]==i)
            c[i]++;

    for(j=0;j<c[i];j++)
        a[k++]=i;

    countsort(a,n,i+1,max);
}