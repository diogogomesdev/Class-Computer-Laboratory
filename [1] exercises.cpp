int contar_maiores(int* vec, int size, int val){
    int count=0;
    for(int i=0;i<size;i++)
        if(vec[i] > val) count++;
    return count;
}

int palindromo(char* str){

    int size = 0;
    int i=0;

    // size array of chars
    while(str[i] != '\0'){
        size++;
        i++;
    }

    int half = size / 2, last = size - 1, count=0;

    //check if is palindrome
    for(int i=0; i<half; i++){
        if(str[i] == str[last]){
            count++;
            last--;
        }
    }

    if(count == half) return 1;
    else return 0;
}
