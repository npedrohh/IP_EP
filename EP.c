#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
  int nUSP;
  double p1;
  double p2;
  double eps; 
  double listas;
}Aluno;

//Função que calcula a média de um aluno (Exercício 3)
double media(Aluno a){
  double media;

  media = 0.7*((a.p1 + a.p2)/2) + a.eps + a.listas;

  return media;
}

//Função que calcula quantos alunos foram aprovados (Exercício 3)
int quantos_aprovados(Aluno *alunos, int numAlunos){
  
  int aprovados = 0;

  for(int i = 0;i < numAlunos;i++)
    if(media(alunos[i]) >= 5.0)
      aprovados++;

  return aprovados;
}

int main(){

  int n;
  
  printf("Digite o número de alunos na turma:");
  scanf("%d", &n);

  Aluno *aluno = (Aluno*) malloc((n+1) * sizeof(Aluno));
  
  for(int i = 0;i < n;i++){
    printf("Digite o nUSP do aluno %d:", i+1);
    scanf("%d", &aluno[i].nUSP);
    printf("Digite a nota na P1 do aluno %d:", i+1);
    scanf("%lf", &aluno[i].p1);
    printf("Digite a nota na P2 do aluno %d:", i+1);
    scanf("%lf", &aluno[i].p2);
    printf("Digite a nota nos EPs do aluno %d:", i+1);
    scanf("%lf", &aluno[i].eps);
    printf("Digite a nota nas listas do aluno %d:", i+1);
    scanf("%lf", &aluno[i].listas);
  }

  printf("%d alunos foram aprovados", quantos_aprovados(aluno, n));
  
}
