#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 30

struct fecha{
    int dd;
    int mm;
    int aa;
};

struct punto{
    float x;
    float y;
};

int cuadrante(int A[N][N]);
int critico(int A[N][N], int i, int j);
float media(int A[N][N], int *fil, int *col);
int borde(int i, int j);
int adyacente(int i, int j, int r, int s);


int main(){
    struct punto p1;
    struct punto p2;
    struct punto medio;
    struct fecha f1;
    struct fecha f2;
    f2.dd = 12;
    f2.mm = 12;
    f2.aa = 2016;
    f1 = f2;
    printf("%d", f1.dd);
    printf("\n Introduzca las coordenadas del primer punto[x y]: ");
    scanf("%f%f", p1.x, p1.y);
    printf("\n Introduzca las coordenadas del segundo punto[x y]: ");
    scanf("%f%f", p2.x,p2.y);
    puntoMedio(p1, p2, &medio);
    return 0;
}

int cuadrante(int A[N][N]){
    int i, j;
    for (i = 0; i < N/2; ++i) {
        for(j = 0; j < N/2; j++){
            if(A[i][j] != A[N-1-j][N-1-i]){
                return 0;
            }
        }
    }
    return 1;
}

int critico(int A[N][N], int i, int j){
    int k, suma;
    suma = 0;
    for(k = 0; k < N; k++){
        if(k != i){
            suma = A[k][j];
        }
        if(k != j){
            suma = A[i][k];
        }
    }
    if(suma == A[i][j]){
        return suma;
    }else{
        return 0;
    }
}

float media(int A[N][N], int *fil, int *col){
    float media;
    int i, j, cont, hayC;
    hayC = 0;
    media = 0;
    cont = 0;
    *fil = -1;
    *col = -1;
    for(i = 0; i < N;i++){
        for(j = 0; j < N; j++){
            if(critico(A, i, j)){
                if(hayC == 0){
                    hayC = 1;
                    *fil = i;
                    *col = j;
                }else if(A[i][j] > A[*fil][*col]){
                    *fil = i;
                    *col = j;
                }
                media += A[i][j];
                cont++;
            }
        }
    }
    if(hayC == 1){
        return media/cont;
    }else{
        return 0;
    }
}

int borde(int i, int j){
    return i == 0 || i == N - 1 || j == 0 || j == N - 1;
}

int adyacente(int i, int j, int r, int s){
    return abs(i - r) <= 1 && abs(j - s) <= 1;
}

void puntoMedio(struct punto p1, struct punto p2, struct punto *p3){
    p3->x = (p1.x + p2.x)/2;
    p3->y = (p1.y + p2.y)/2;
}