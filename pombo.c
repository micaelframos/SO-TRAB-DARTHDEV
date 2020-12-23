#include <stdlib.h> // Cabecalho de Biblioteca padrao
#include <stdio.h> // Cabecalho de Biblioteca de I/O padrao
#include <pthread.h> // Cabecalho especifico para threads POSIX
#include <semaphore.h> //biblioteca para o uso de semafaros 
#include <unistd.h> // ??? ...

#define N 20

sem_t semaf_PostIt;//
sem_t semaf_LiberaPombo;// 
sem_t semaf_LiberaUsuario;//

int VEZES = 0;
int contPostIt = 0;
int para = 0;

void DormePombo (){
     puts("Pombo Dormindo zZZzzZZzzZZ");
     sleep(3);
}
void AcordaPombo (){
    puts("Pombo Acordado @@@@@@@@@@@@");
}
void ColaPostIt (){
    puts("Post it colado");
}
void levaMochilaAteB (){
    puts ("Pombo indo para B");
    puts("---->");
    sleep(3);
    puts("Pombo voltou ao A");
    puts("<----");
}       
void slow (){
    int num = 1000;
    for (int i = 0; i < num; i++){
        for(int k = 0; k < num; k++){
            for(int g = 0; g < num; g++){
                num = num;
            }
        }
    }
}

void *usuario (void* arg){
    register unsigned int i;
    while(i++<VEZES){
        sem_wait(&semaf_LiberaUsuario); //Libera
        sem_wait(&semaf_PostIt);
        contPostIt++;
        //slow ();
        printf("Post it colado %d\n", contPostIt);
        if (contPostIt == N){
            printf("mochila cheia \n");
            AcordaPombo();
            sem_post(&semaf_LiberaPombo);
            sem_post(&semaf_PostIt);
            sem_wait(&semaf_LiberaUsuario);
        }else{
            sem_post(&semaf_PostIt);
        }
        sem_post(&semaf_LiberaUsuario);
    }
 pthread_exit(NULL);
}
void *Pombo (void* arg){
    register unsigned int i;
    while(i++<VEZES){
        sem_wait(&semaf_LiberaPombo);
        levaMochilaAteB();
        sem_wait(&semaf_PostIt);
            contPostIt = 0; 
        sem_post(&semaf_PostIt);
            for (int i=1; i<=N; i++){
                printf("Adic. msg %d\n", i);
            }
        sem_post(&semaf_LiberaUsuario);
    }
    pthread_exit(NULL);
}

int main (void){

    int NumeroMensagem = 0; 
    DormePombo();
    printf("Digite o numero de usuarios que iram escrever mensagens:");
    scanf("%d", &NumeroMensagem);
    VEZES = NumeroMensagem;

    pthread_t idusuario[N]; 
    pthread_t idpombo;

    register unsigned int i;

    sem_init(&semaf_PostIt, 0, 1);
    sem_init(&semaf_LiberaPombo, 0, 0);
    sem_init(&semaf_LiberaUsuario, 0, 1);

    pthread_create(&idpombo, NULL, Pombo, NULL);

    for( i = 0; i < N; i++){
        pthread_create(&idusuario[i], NULL, usuario, NULL);
    }

    for (i=0; i< N;i++){
        pthread_join(idusuario[i],NULL);
    }

    pthread_join(idpombo, NULL);

    sem_destroy(&semaf_PostIt);
    sem_destroy(&semaf_LiberaPombo);
    sem_destroy(&semaf_LiberaUsuario);

    pthread_exit(NULL);

    return 0;
}
