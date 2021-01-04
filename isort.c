#include <stdio.h> 

#define arrSize 50

void shift_element(int* arr, int i){
    int temp1 = *(arr);
    for (int j = 1; j <= i; j++){
        int temp2 = *(arr + j);
        *(arr + j) = temp1;
        temp1 = temp2;
    }
}

void insertion_sort(int* arr, int len){
    int temp, counter = 0;
    for (int j = 0; j < len; j++){
        if(j+1 < len){
            if(*(arr+j) > *(arr+j+1)){
                temp = *(arr+j+1);
                for (int i = 0;i <= j && temp > *(arr+i); i++){
                    counter++;
                }
                shift_element(arr+counter, j+1-counter);
                *(arr+counter) = temp;
                counter = 0;
            }
        }
    }
}

int main(){
    int arr[arrSize] = {0};
    int temp = 0;
    for (int i = 0; i < arrSize; i++){
        scanf("%d",&temp);
        arr[i] = temp;
    }
    int *arrPtr = NULL;
    arrPtr = &arr[0];
    // printf("\n");
    insertion_sort(arrPtr, arrSize);
    for (int i = 0; i < arrSize; i++){
        if(i+1 == arrSize){
            printf("%d",*(arr+i));
        }
        else{
            printf("%d,",*(arr+i));
        }
    }
    printf("\n");
    return 0;
}

