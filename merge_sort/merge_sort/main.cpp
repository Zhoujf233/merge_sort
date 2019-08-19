//
//  main.cpp
//  merge_sort
//
//  Created by JF Zhou on 2019/8/19.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

int min(int x, int y)
{
    return (x < y ? x : y);
}

void merge_sort(int* arr, int size)
{
    int* a = arr;
    int* b = (int*) malloc(size * sizeof(int));
    int seg,start;
    for(seg = 1; seg < size; seg += seg)
    {
        for(start = 0; start < size; start += seg + seg)
        {
            int low = start, mid = min(start + seg, size), high = min(start + seg + seg, size);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while(start1 < end1 && start2 < end2)
            {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while(start1 < end1)
            {
                b[k++] = a[start1++];
            }
            while(start2 < end2)
            {
                b[k++] = a[start2++];
            }
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if(a != arr)
    {
        int i;
        for(i = 0; i < size; i++)
        {
            b[i] = a [i];
        }
        b = a;
    }
    free(b);
}


int main(int argc, const char * argv[])
{
    int arr[] = {89,22,3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    merge_sort(arr, size);
    
    cout << "选择排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
