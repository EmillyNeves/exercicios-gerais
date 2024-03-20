#include <stdio.h>
#define MAX 4

typedef struct{
    int l;
    int c;
}tPonto;

void PreencheMapa(int M, int N, int map[M][N]){
    int i=0, k=0;

    for(i=0; i<M; i++){
        for(k=0; k<N; k++){
            scanf("%d", &map[i][k]);
        }
    }
}

int EndGame(tPonto ponto, tPonto final){
    if(ponto.c==final.c && ponto.l == final.l){
        return 1;
    }
    else{
        return 0;
    }
}
void LePrioridade(char mov[MAX]){
    int i=0;
        scanf("%*c");
    while(i<MAX){
        scanf("%c", &mov[i]);
        i++;
    }
}
void Movimento(int M, int N, int map[M][N], char mov[MAX], tPonto inicio, tPonto final){
    int i=0;
    printf("(%d,%d) ", inicio.l, inicio.c);
    inicio.c-=1;
    inicio.l-=1;
    final.c-=1;
    final.l-=1;

    while(!EndGame(inicio, final)){
        for(i=0; i<4; i++){
            if(mov[i]=='B' && inicio.l < M-1 && map[inicio.l+1][inicio.c]==0){
                map[inicio.l][inicio.c]=2;
                inicio.l+=1;
                break;
            }
            else if(mov[i]=='C' && inicio.l > 0 && map[inicio.l-1][inicio.c]==0){
                map[inicio.l][inicio.c]=2;
                inicio.l-=1;
                break;
            }
            else if(mov[i]=='E' && inicio.c > 0 && map[inicio.l][inicio.c-1]==0){
                map[inicio.l][inicio.c]=2;
                inicio.c-=1;
                break;
            }
            else if(mov[i]=='D' && inicio.c < N-1 && map[inicio.l][inicio.c+1]==0){
                map[inicio.l][inicio.c]=2;
                inicio.c+=1;
                break;
            }
        }
        if(i==4){
            break;
        }
        printf("(%d,%d) ", inicio.l+1, inicio.c+1);
    }
    
}

int main(){

    int M, N;
    char mov[MAX];
    scanf("%d %d", &M, &N);
    int map[M][N];
    PreencheMapa(M,N,map);
    tPonto inicio;
    tPonto final;
    scanf("%d %d %d %d", &inicio.l, &inicio.c, &final.l, &final.c);
    LePrioridade(mov);
    Movimento(M, N, map, mov, inicio, final);
    return 0;
}
