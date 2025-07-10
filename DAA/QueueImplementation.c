#include <stdio.h>
int arr[100];
int f;
int r;
int maxsize;

void initQueue(int n)
{
    f = 0;
    r = 0;
    maxsize = n;
}

void enque(int n)
{
    if (r >= maxsize)
    {
        printf("queue overflow\n");
        return;
    }
    r += 1;
    arr[r] = n;
    if (f == 0)
    {
        f = 1;
    }
}

int dequeue()
{
    if (f == 0){
        printf("queue underflow\n");
        return 0;
    }
    int ele=arr[f];
    if(f==r){
        f=0;
        r=0;
    }
    else{
        f+=1;
    }
    printf("%d\n",ele);
    return ele;
}

void display(){
    for(int i=f;i<=r;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    initQueue(10);
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    enque(5);
    enque(6);
    display();
    printf("%d\n",dequeue());
    display();
    return 0;
}