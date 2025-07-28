#include <stdio.h>
#include <stdlib.h>
void count_sort(int *arr,int size){
int idx=1;
int max=arr[0];
while(idx<size){
    if(arr[idx]>max){
        max=arr[idx]; //finding maximum element
    }
        idx++;
}
int* temp_arr=(int*)malloc((max+1)*sizeof(int)); //dynamically allocating memory, we can avoid this without any issue
for(int i=0;i<max+1;i++){
    temp_arr[i]=0; //initializing all indeces with zero
}
for(int j=0;j<size;j++){
    int x=arr[j];
    temp_arr[x]+=1;
}
int jdx=0;
for(int k=0;k<=max;k++){
    while(temp_arr[k]>0){
        arr[jdx]=k;
        jdx++;
        temp_arr[k]-=1;
    }
}
free(temp_arr);
}
int main(){
    int arr[]={7, 9, 3, 5, 4, 0, 8, 5, 6, 3}; //only non negetive number allowed
    int size=sizeof(arr)/sizeof(arr[0]);
    count_sort(arr,size);
    printf("Sorted array--->\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}