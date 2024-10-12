#include<iostream>
using namespace std;

class heap{
    public:
     int arr[100];
     int size;
     heap()
     {
        arr[0]=-1;
        size=0;
     }
    void insert(int value)
    {
        size=size +1 ;
        int index=size;
        arr[index]=value;

        while(index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else return;
        }

    }

    void deleteroot()
    {
        if(size==0)
        {
            cout<<"nothing to delete";
            return;
        }
        arr[1]=arr[size];

        size--;
        int i=1;

        while(i<size)
        {
            int leftindex=i*2;
            int rightindex=i*2+1;

            if(leftindex<size && arr[i]<arr[leftindex] )
            {
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[rightindex]>arr[i] )
            {
                swap(arr[rightindex],arr[i]);
                i=rightindex;
            }
            else return;
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }





};
void heapify(int arr[],int i,int size)
{
    int largest =i;
    int left =i*2;
    int right = i*2+1;

    if(left<size && arr[left]>arr[largest])
    {
        largest=left;

    }
    if(right<size && arr[right]>arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,largest,size);
    }
}


void heapsort(int ar[], int size)
{
    while(size > 1)  // Repeat until the array is sorted
    {
        // Swap the first (largest) element with the last element
        swap(ar[1], ar[size]);

        // Decrease the size of the heap
        size--;

        // Heapify the root (index 1) to maintain the max-heap property
        heapify(ar, 1, size);
    }
}


int  main()
{
    heap h;
    h.insert(60);
    h.insert(70);
    h.insert(25);
    h.insert(79);


    h.print();

    int ar[6]={-1,70,60,50,47,38};
    int n=6;
    for(int i=n/2;i>1;i--)
    {
        heapify(ar,i,6);
    }

    heapsort(ar,n);

    for(int i=2;i<=n;i++)
    {
        cout<<ar[i]<<" ";

    }
    cout<<endl;

    






    return 0;
}

