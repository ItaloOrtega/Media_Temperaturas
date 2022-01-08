#include <stdio.h>
#include <stdlib.h>

typedef struct{//Struct do Mês, que possui:
  int cont;//Contagem das vezes que o mês aparece no arquivo
  float max_min, max_max, media, min, max;//Valor minimo maximo, valor maximo maximo, media das medias, media das minimas e media das maximas
}mes;

void percorre(mes vetor[]);//Função de percorrer o arquivo "temps.dat"
void escreve(mes vetor[]);//Função de escrever os valores no arquivo "medias.dat"

int main(){
  int i = 0;
  mes vetor[12];//Criação do vetor de meses
  while(i < 12){//while para zerar os valores do vetor
    vetor[i].media = vetor[i].max = vetor[i].max_max = vetor[i].cont = vetor[i].min = 0;
    vetor[i].max_min = 999;
    i++;
  }

  printf("\nLendo o arquivo 'temps.dat'...\n");
  percorre(vetor);//Chama a função para percorrer o arquivo "temps.dat"
  printf("\nEscrevendo no arquivo 'medias.dat'...\n");
  escreve(vetor);//Chama a função para escrever o vetor no arquivo "medias.dat"
  printf("\nEncerrando...\n");
  return 0;
}

void percorre(mes vetor[]){
  FILE *arq;//Criação do ponteiro do arquivo
  float min, media, max;//Variaveis auxiliares
  int year, month;
  arq = fopen("temps.dat", "r");//Abre o arquivo barras.dat para leitura
  if(arq == NULL){//Dando algum erro com o arquivo
    printf("Nao foi possivel abrir o arquivo!!!\n");
    exit(0);
  }
  while(!feof(arq)){//While para ler o arquivo até o final
    fscanf(arq,"%d %d %f %f %f", &year, &month, &min, &media, &max);//Recebe os dados da linha atual do arquivo
    if (feof(arq))//Caso leia a ultima linha do arquivo
      break;
    month--;//Para ir na posição correta do vetor
    vetor[month].cont = vetor[month].cont + 1;//Aumenta a contagem de vezes que o mes aparece
    vetor[month].media = vetor[month].media + media;//Adiciona o valor da media desse mes as medias
    vetor[month].min = vetor[month].min + min;//Adiciona o valor minimo desse mes aos outros minimos
    vetor[month].max = vetor[month].max + max;//Adiciona o valor maximo desse mes aos outros maximos
    //Caso de mudanças do maior e menor valor do vetor respectivamente
    if(min < vetor[month].max_min)
      vetor[month].max_min = min;
    if(max > vetor[month].max_max)
      vetor[month].max_max = max;
  }
  fclose(arq);//Fecha o arquivo
}

void escreve(mes vetor[]){//Função para escrever os dados no arquivo "medias.dat"

  FILE *arq;
  arq = fopen("medias.dat", "w");//Abre o arquivo barras.dat para leitura
  if(arq == NULL){//Dando algum erro com o arquivo
    printf("Nao foi possivel abrir o arquivo!!!\n");
    exit(0);
  }
  int i=0;
  while(i<12){//Escreve até o i ser igual a 12, que é o total de meses
    fprintf(arq, "%d %.1f (%.1f) %.1f %.1f (%.1f)\n",i+1,(vetor[i].min / vetor[i].cont),vetor[i].max_min, (vetor[i].media / vetor[i].cont), (vetor[i].max / vetor[i].cont), vetor[i].max_max);
    i++;//Os valores escritos no arquivo é o mês, média das minimas(vlrs min / cont), minima maxima, media das medias(vlrs med/ cont), media das maximas(vlrs max/cont), maxima maxima
  }
  fclose(arq);//Fecha o arquivo
}