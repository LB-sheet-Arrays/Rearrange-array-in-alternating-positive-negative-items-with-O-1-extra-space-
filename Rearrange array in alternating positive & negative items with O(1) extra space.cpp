/*
ORDER OF APPEARANCE IS IMPORTANT

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}


GFG approach:

The idea is to process array from left to right. While processing, find the first out of place element in 
the remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive 
and at even index. Once we find an out of place element, we find the first element after it with opposite sign. 
We right rotate the subarray between these two elements (including these two).

DRY RUN:


I/P: 1, 2, 3, -4, -1, 4
  
     -4, 1, 2, 3, -1, 4
     
     -4, 1, -1, 2, 3, 4


              

*/


#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    int  tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		int outofplace,curr;
		//get element out of place
		if((arr[i]>0 && i%2==0) || (arr[i]<0 && i%2==1))
		{
			outofplace=i;
			
			//ab is position se agla aisa first element dekho jo opposite sign ka ho
			for(int j=outofplace;j<n;j++)
			{
				if((arr[j]*arr[outofplace])<0)
				{
					curr=j;
					//rotate the array now between outofplace and curr
					rightrotate(arr,n,outofplace,curr);
					break;  //break isiliye bcoz hume first negative hi chiaye
				} 
			}
		}
	}
}

// Driver code
int main()
{
     
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}
