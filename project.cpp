#include <stdio.h>
#include <stdlib.h>

typedef struct rgb{
    int R, G, B;
} RGB;

struct ppm_image{
    char type[2];
    int width;
    int heigth;
    int rgb;
    RGB** matrix;
};

void horizontal_rotation(struct ppm_image img){
    printf("%c%c\n", img.type[0], img.type[1]);
    printf("%d ", img.width);
    printf("%d\n", img.heigth);
    printf("%d\n", img.rgb);
    for(int i=0;i<img.heigth;i++){
        for(int j=img.width-1;j>=0;j--){
            printf("%d ", img.matrix[i][j].R);
            printf("%d ", img.matrix[i][j].G);
            printf("%d\n", img.matrix[i][j].B);
        }
    }
}

void horizontal_rotation_to_file(struct ppm_image img, char** argv){
    FILE* fo;

    if((fo = fopen(argv[2], "w")) == NULL){
        exit(1);
        printf("Erro ao ler ficheiro\n");
    }
    fprintf(fo, "%c%c\n", img.type[0], img.type[1]);
    fprintf(fo, "%d ", img.width);
    fprintf(fo, "%d\n", img.heigth);
    fprintf(fo, "%d\n", img.rgb);
    for(int i=0;i<img.heigth;i++){
        for(int j=img.width-1;j>=0;j--){
            fprintf(fo, "%d ", img.matrix[i][j].R);
            fprintf(fo, "%d ", img.matrix[i][j].G);
            fprintf(fo, "%d\n", img.matrix[i][j].B);
        }
    }

    fclose(fo);
}

void vertical_rotation(struct ppm_image img){
    printf("%c%c\n", img.type[0], img.type[1]);
    printf("%d ", img.width);
    printf("%d\n", img.heigth);
    printf("%d\n", img.rgb);
    for(int i=img.heigth-1;i>=0;i--){
        for(int j=0;j<img.width;j++){
            printf("%d ", img.matrix[i][j].R);
            printf("%d ", img.matrix[i][j].G);
            printf("%d\n", img.matrix[i][j].B);
        }
    }
}

void vertical_rotation_to_file(struct ppm_image img, char** argv){
    FILE* fo;

    if((fo = fopen(argv[2], "w")) == NULL){
        exit(1);
        printf("Erro ao ler ficheiro\n");
    }
    fprintf(fo, "%c%c\n", img.type[0], img.type[1]);
    fprintf(fo, "%d ", img.width);
    fprintf(fo, "%d\n", img.heigth);
    fprintf(fo, "%d\n", img.rgb);
    for(int i=img.heigth-1;i>=0;i--){
        for(int j=0;j<img.width;j++){
            fprintf(fo, "%d ", img.matrix[i][j].R);
            fprintf(fo, "%d ", img.matrix[i][j].G);
            fprintf(fo, "%d\n", img.matrix[i][j].B);
        }
    }

    fclose(fo);
}

void component_adjust(struct ppm_image img, char** argv){

    int size1 = size(argv[1]);
    int size2 = size(argv[2]);
    int size3 = size(argv[3]);

    int somar1 = 0, somar2=0, somar3=0;

    int x=1;
    if(argv[1][0] == '-'){
        for(int i=size1-1;i>=1;i--){
            somar1 += ((argv[1][i]-48) * x);
            x *= 10;
        }
        somar1 = -somar1;
    }
    else{
        if(argv[1][0] == '+'){
            for(int i=size1-1;i>=1;i--){
                somar1 += ((argv[1][i]-48) * x);
                x *= 10;
            }
        }
        else{
            for(int i=size1-1;i>=0;i--){
                somar1 += ((argv[1][i]-48) * x);
                x *= 10;
            }
        }
    }

    x=1;
    if(argv[2][0] == '-'){
        for(int i=size2-1;i>=1;i--){
            somar2 += ((argv[2][i]-48) * x);
            x *= 10;
        }
        somar2 = -somar2;
    }
    else{
        if(argv[2][0] == '+'){
            for(int i=size2-1;i>=1;i--){
                somar2 += ((argv[2][i]-48) * x);
                x *= 10;
            }
        }
        else{
            for(int i=size2-1;i>=0;i--){
                somar2 += ((argv[2][i]-48) * x);
                x *= 10;
            }
        }
    }

    x=1;
    if(argv[3][0] == '-'){
        for(int i=size3-1;i>=1;i--){
            somar3 += ((argv[3][i]-48) * x);
            x *= 10;
        }
        somar3 = -somar3;
    }
    else{
        if(argv[3][0] == '+'){
            for(int i=size3-1;i>=1;i--){
                somar3 += ((argv[3][i]-48) * x);
                x *= 10;
            }
        }
        else{
            for(int i=size3-1;i>=0;i--){
                somar3 += ((argv[3][i]-48) * x);
                x *= 10;
            }
        }
    }
    int new1, new2, new3;

    printf("%c%c\n", img.type[0], img.type[1]);
    printf("%d ", img.width);
    printf("%d\n", img.heigth);
    printf("%d\n", img.rgb);

    for(int i=0;i<img.heigth;i++){
        for(int j=0;j<img.width;j++){

            new1 = img.matrix[i][j].R + somar1;
            if(new1 > img.rgb) new1 = img.rgb;
            if(new1 < 0) new1 = 0;
            printf("%d ", new1);

            new2 = img.matrix[i][j].G + somar2;
            if(new2 > img.rgb) new2 = img.rgb;
            if(new2 < 0) new2 = 0;
            printf("%d ", new2);

            new3 = img.matrix[i][j].B + somar3;
            if(new3 > img.rgb) new3 = img.rgb;
            if(new3 < 0) new3 = 0;
            printf("%d\n", new3);
        }
    }
}

void component_adjust_to_file(struct ppm_image img, char** argv){
    FILE* fo;

    if((fo = fopen(argv[5], "w")) == NULL){
        exit(1);
        printf("Erro ao ler ficheiro\n");
    }

    int size1 = size(argv[1]);
    int size2 = size(argv[2]);
    int size3 = size(argv[3]);

    int somar1 = 0, somar2=0, somar3=0;

    int x=1;
    if(argv[1][0] == '-'){
        for(int i=size1-1;i>=1;i--){
            somar1 += ((argv[1][i]-48) * x);
            x *= 10;
        }
        somar1 = -somar1;
    }
    else{
        for(int i=size1-1;i>=0;i--){
            somar1 += ((argv[1][i]-48) * x);
            x *= 10;
        }
    }

    x=1;
    if(argv[2][0] == '-'){
        for(int i=size2-1;i>=1;i--){
            somar2 += ((argv[2][i]-48) * x);
            x *= 10;
        }
        somar2 = -somar2;
    }
    else{
        for(int i=size3-1;i>=0;i--){
            somar2 += ((argv[2][i]-48) * x);
            x *= 10;
        }
    }

    x=1;
    if(argv[3][0] == '-'){
        for(int i=size1-1;i>=1;i--){
            somar3 += ((argv[3][i]-48) * x);
            x *= 10;
        }
        somar3 = -somar3;
    }
    else{
        for(int i=size1-1;i>=0;i--){
            somar3 += ((argv[3][i]-48) * x);
            x *= 10;
        }
    }
    int new1=0, new2=0, new3=0;

    fprintf(fo, "%c%c\n", img.type[0], img.type[1]);
    fprintf(fo, "%d ", img.width);
    fprintf(fo, "%d\n", img.heigth);
    fprintf(fo, "%d\n", img.rgb);
    for(int i=0;i<img.heigth;i++){
        for(int j=0;j<img.width;j++){
            new1 = img.matrix[i][j].R + somar1;
            if(new1 > img.rgb) new1 = img.rgb;
            if(new1 < 0) new1 = 0;
            fprintf(fo, "%d ", new1);

            new2 = img.matrix[i][j].G + somar2;
            if(new2 > img.rgb) new2 = img.rgb;
            if(new2 < 0) new2 = 0;
            fprintf(fo, "%d ", new2);

            new3 = img.matrix[i][j].B + somar3;
            if(new3 > img.rgb) new3 = img.rgb;
            if(new3 < 0) new3 = 0;
            fprintf(fo, "%d\n", new3);

        }
    }

    fclose(fo);
}


int main(int argc, char** argv){

    struct ppm_image image;

    //imagem lida por imagem padrao
    if(argc == 1){
        scanf("%c", &image.type[0]);
        scanf("%c", &image.type[1]);

        scanf("%d", &image.width);
        scanf("%d", &image.heigth);

        scanf("%d", &image.rgb);

        //alocacao dinamica de memoria
        image.matrix = (RGB**)malloc(image.heigth * sizeof(RGB*));
        for(int i=0;i<image.heigth;i++){
            image.matrix[i] = (RGB*)malloc(image.width * sizeof(RGB));
        }

        for(int i=0;i<image.heigth;i++){
            for(int j=0;j<image.width;j++){
                scanf("%d", &image.matrix[i][j].R);
                scanf("%d", &image.matrix[i][j].G);
                scanf("%d", &image.matrix[i][j].B);
            }
        }

        vertical_rotation(image);


        //libertar memoria
        for(int i=0;i<image.heigth;i++){
            free(image.matrix[i]);
        }
        free(image.matrix);

    }//imagem lida por ficheiro de input
    else if(argc == 2 || argc == 3){
        FILE* f;

        if((f = fopen(argv[1], "r")) == NULL ){
            exit(1);
            printf("Erro ao ler ficheiro\n");
        }

        fscanf(f, "%c", &image.type[0]);
        fscanf(f, "%c", &image.type[1]);

        fscanf(f, "%d", &image.width);
        fscanf(f, "%d", &image.heigth);

        fscanf(f, "%d", &image.rgb);

        //alocacao dinamica de memoria
        image.matrix = (RGB**)malloc(image.heigth * sizeof(RGB*));
        for(int i=0;i<image.heigth;i++){
            image.matrix[i] = (RGB*)malloc(image.width * sizeof(RGB));
        }

        for(int i=0;i<image.heigth;i++){
            for(int j=0;j<image.width;j++){
                fscanf(f, "%d", &image.matrix[i][j].R);
                fscanf(f, "%d", &image.matrix[i][j].G);
                fscanf(f, "%d", &image.matrix[i][j].B);
            }
        }

        if(argc == 2) vertical_rotation(image);
        else vertical_rotation_to_file(image, argv);

        //libertar memoria
        for(int i=0;i<image.heigth;i++){
            free(image.matrix[i]);
        }
        free(image.matrix);

        fclose(f);
        

    }else printf("Erro\n");

    return 0;
}
