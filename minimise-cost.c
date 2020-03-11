#include<stdio.h>
int main()
{
    int n,k,shift,i,j,modj=0;
    long long int sum=0;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        //if we increase negative value then only we can decrease sum of modulus of number
        if(arr[i]<0)
        {
            //to get left most value from arr[i] of which value it can gain
            //modj contain leftmost value greater than 0 from previous operations
            j=i-k;
            if(j<modj)
            {
                j=modj;
            }
            for(;j<=i+k && j<n;j++)
            {
                if(arr[j]>0)
                {
                    //shift = value arr[i] to become +ve
                    shift=-arr[i];
                    //checking does arr[j] contain sufficient value to make a[i] +ve
                    if(arr[j]<shift)
                    {
                        shift=arr[j];
                    }
                    arr[j]=arr[j]-shift;
                    arr[i]=arr[i]+shift;
                    if(arr[i]==0)
                    {
                        break;
                    }
                }
            }
            modj=j;
        }
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            sum=sum-arr[i];
        }
        else
        {
            sum=sum+arr[i];
        }
    }
    printf("%lli",sum);
    return 0;
}