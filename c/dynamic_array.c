#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>



typedef struct dyn_int_array{
    int* arr;
    size_t len;
    size_t capacity;
    void (*print_arr)(struct dyn_int_array* arr);
    void (*append)(struct dyn_int_array* arr, int n);
    void (*_remove)(struct dyn_int_array* arr, int index);
    void (*insert_at)(struct dyn_int_array* arr, int element,int index);
}dyn_int_array;


void print_arr(dyn_int_array* array){
    for(size_t i = 0;i<array->len;i++)
    {
        printf("%d,", array->arr[i]);
    }
}

void append(dyn_int_array* array,int n){
    array->len++;
    array->arr = realloc(array->arr, array->capacity + sizeof(int));
    array->arr[array->len - 1] = n;
}

void _remove(dyn_int_array* array, int index){
    for(size_t i = index;i<(array->len - index);i++){
        *(array->arr + i) = *(array->arr + i+1);
    }
    array->arr = realloc(array->arr,array->capacity - sizeof(index));
    array->len--;
}

void insert_at(dyn_int_array* array, int element, int index){
    if(index == array->len - 1){
        append(array, element);
    }
    else if(index >= 0){
        array->len++;
        array->arr = realloc(array->arr,array->capacity + sizeof(int));
        for(size_t i = array->len; i > 0;i--){
            *(array->arr + i) = *(array->arr + i - 1);
        }
        *(array->arr+index) = element;
    };
}

int main(void){
    static bool shouldexit = false;
    srand(time(NULL));
    int option = 0;
    int element;
    int index;
    // size_t arr_len;
    puts("Dynamic array wizard");
    puts("Instantiating array... default size: 10");
    dyn_int_array array = {NULL,10,0,print_arr,append,_remove,insert_at};
    array.arr = malloc(sizeof(int) * array.len);
    array.capacity = sizeof(int) * array.len;
    if(array.arr == NULL){
        fprintf(stderr,"Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0;i<array.len;i++)
    {
        array.arr[i] = rand() % 1000;
    }
    while(!shouldexit){
    puts("\nArray:");
    array.print_arr(&array);
    printf("\nOptions: \
            \n1. Append element\
            \n2. Add element at index\
            \n3. Remove element at index\
            \n4. Exit\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            puts("Input:\n");
            scanf("%d", &element);
            array.append(&array,element);
            array.print_arr(&array);
            break;
        case 2:
            puts("Element:\n");
            scanf("%d", &element);
            puts("Index:\n");
            scanf("%d", &index);
            array.insert_at(&array, element, index);
            array.print_arr(&array);
            break;
        case 3:
            puts("Input:\n");
            scanf("%d",&index);
            array._remove(&array, index);
            array.print_arr(&array);
            break;
        case 4:
            puts("Bye!");
            exit(EXIT_SUCCESS);
        default:
            puts("Invalid option.");
            break;
        }
    }
    free(array.arr);
    return 0;
}
