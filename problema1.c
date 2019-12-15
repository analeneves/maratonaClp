#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX_ALUNOS 30 
clock_t tempo;
//tempo = clock();
 
struct TipoAluno { 
      char nome[30]; 
      float media; 
}; 
 
// protótipos das funções 
float solicitaNota(void); 
float calculaMedia(float nota1, float nota2, float pontos); 
void exibeAluno(struct TipoAluno aluno); 
void finalizaPrograma(void); 
 
// programa principal com as chamadas das funções criadas 
int main(void) { 
      // As variáveis criadas aqui dentro (chamadas de variáveis locais) não são 
      // visíveis em outras funções. Variáveis declaradas fora de qualquer função 
      // são chamadas de variáveis globais. 
      // Se houver necessidade de acessar uma variável dentro de outra função   
      // deve-se passa-la como argumento como acontece com: calculaMedia e exibeAluno 
      struct TipoAluno alunos[5]; 
      float nota1, nota2, pontos; 
      int i; 
      for(i=0; i < MAX_ALUNOS; i++) { 
            printf("Entre com o nome do aluno: "); 
            fflush(stdin);
            gets(alunos[i].nome); 
            printf("Entre com a primeira nota (0 a 10): "); 
            nota1 = solicitaNota(); 
            printf("Entre com a segunda nota (0 a 10): "); 
            nota2 = solicitaNota(); 
            printf("Entre com os pontos (0 a 10): "); 
            pontos = solicitaNota(); 
            alunos[i].media = calculaMedia(nota1, nota2, pontos); 
      } 
      printf("\n\nExibicao dos dados:"); 
      for(i=0; i < MAX_ALUNOS; i++) 
            exibeAluno(alunos[i]);   
 
      finalizaPrograma(); 
}          
 
// Funções: 
 
// solicita uma nota exigindo que a mesma esteja na faixa válida: 0 a 10 
float solicitaNota(void) { 
      // a variável nota tem escopo local, ou seja ela só existe dentro desta função 
      float nota; 
      do { 
            scanf("%f", &nota); 
            if(nota < 0 || nota > 10) { 
                  printf("Erro, valor deve ser de 0 a 10 \n"); 
            } 
      }while(nota < 0 || nota > 10);   
      return nota; 
} 
 
// calcula a média a partir de duas notas e pontos extras 
// não permitindo que a média ultrapasse de 10 
float calculaMedia(float nota1, float nota2, float pontos) { 
      // a variável media tem escopo local, ou seja ela só existe dentro desta função 
      float media = (nota1 + nota2)/2 + pontos; 
      // não permite que o retorno seja maior que 10 
      if(media > 10) 
            return 10; 
      else 
            return media; 
} 
 
// exibe os dados de uma aluno passado como argumento 
void exibeAluno(struct TipoAluno aluno) { 
      printf("\n\nAluno: %s\n", aluno.nome);
      printf("Tempo:%f\n",(clock() - tempo) / (double)CLOCKS_PER_SEC); 
      printf("\nMedia: %.2f\n", aluno.media);      
} 
 
// função sem retorno, contendo comandos para finalizar o programa 
void finalizaPrograma(void) { 
      printf("\n\n\n"); 
      system("pause"); 
}