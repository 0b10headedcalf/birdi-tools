#include <stdlib.h>
#include <stdio.h>


void print_arr(int* arr,size_t arr_len){
    for(size_t i = 0;i<arr_len;i++)
    {
        printf("%d,", arr[i]);
    }
}
void append(int* arr,int n, size_t* arr_len){
    size_t curr_size = sizeof(*arr) * (*arr_len);
    printf("\nSeeking to append element %d to array %p.\tCurrent Length:%ld",n,arr,*arr_len);
    *arr_len+=1;
    arr = realloc(arr,curr_size + sizeof(typeof(n)));
    arr[*arr_len - 1] = n;
}

void _remove(int* arr, int index, size_t* arr_len){

}

void insert_at(int* arr, int index, size_t* arr_len){

}




int main(void){
    size_t arr_len;
    puts("Enter size of array:");
    scanf("%ld", &arr_len);
    int* arr = malloc(sizeof(int) * arr_len);
    if(arr == NULL){
        fprintf(stderr,"Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }
    printf("Randomly generating a dynamic integer array of size %ld that is %ld bytes\n", arr_len, sizeof(int) * arr_len);
    for(size_t i = 0;i<arr_len;i++)
    {
        arr[i] = rand() % 1000;
    }
    puts("\nArray:");
    print_arr(arr,arr_len);
    puts("\nNew:");
    append(arr,25,&arr_len);
    printf("\nNew size: %ld\n", arr_len);
    print_arr(arr, arr_len);
    free(arr);
    return 0;
}
