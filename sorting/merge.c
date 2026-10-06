#include<stdio.h>

void merge(int a[],int l,int m,int h);
void mergesort(int a[],int l,int h);

int main()
{
    int a[50],n,i;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergesort(a,0,n-1);

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

void mergesort(int a[],int l,int h)
{
    int m;

    if(l<h)
    {
        m=(l+h)/2;

        mergesort(a,l,m);
        mergesort(a,m+1,h);

        merge(a,l,m,h);
    }
}

void merge(int a[],int l,int m,int h)
{
    int t[50],i=l,j=m+1,k=0;

    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }

    while(i<=m)
        t[k++]=a[i++];

    while(j<=h)
        t[k++]=a[j++];

    for(i=l,k=0;i<=h;i++,k++)
        a[i]=t[k];
}