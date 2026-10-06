#include<stdio.h>

void quick(int a[],int l,int h);

int main()
{
    int a[50],n,i;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quick(a,0,n-1);

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

void quick(int a[],int l,int h)
{
    int i=l,j=h,p=a[l],t;

    if(l<h)
    {
        while(i<j)
        {
            while(a[i]<=p && i<h)
                i++;

            while(a[j]>p)
                j--;

            if(i<j)
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }

        a[l]=a[j];
        a[j]=p;

        quick(a,l,j-1);
        quick(a,j+1,h);
    }
}