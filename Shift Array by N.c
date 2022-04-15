#include <stdio.h>

void main()
{
    int a[1000],n,d,b[100] = {-1};
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter value of D: ");
    scanf("%d",&d);
    for(int i=0;i<n;i++)
        b[((n-d)+i)%n] = a[i];
    for(int i=0;i<n;i++)
        printf("%d\t",b[i]);
}
