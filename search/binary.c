#include <stdio.h>
int binarySearch(int a[], int n, int key)
{int low=0, high=n-1, mid;
    while(low<=high)
    {   mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(key>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }

    return -1;
}
int main()
{   int a[50], n, i, key, pos;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter sorted elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to search: ");
    scanf("%d",&key);
       pos=binarySearch(a,n,key);
    if(pos!=-1)
        printf("Element found at position %d",pos+1);
    else
        printf("Element not found");
    return 0;
}