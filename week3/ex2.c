void bubble_sort(int* array, int size){
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                int a = array[j];
                array[j] = array[j + 1];
                array[j + 1] = a;
            }
        }
    }
}

int main() {
    return 0;
}