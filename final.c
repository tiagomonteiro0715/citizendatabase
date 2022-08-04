#include <stdio.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

#define MAX_CITIZENS 50
#define MAX_SIZE 100
#define True 1
#define False 0
#define bool int

struct num_serv_sec {
  int num_serie;
};

struct info_pessoal {
  char nome[MAX_SIZE];
  int dia_nasc;
  int mes_nasc;
  int ano_nasc;
  int altura;
  char olhos[MAX_SIZE];
  char cabelo[MAX_SIZE];
};

struct info_numer {
  int bi;
  int contribuinte;
  int seg_social;
  int carta_cond;
};

struct morada {
  char rua[MAX_SIZE];
  int cod_postal1;
  int cod_postal2;
  char cod_postal3[MAX_SIZE];
};

struct confid {
  char partido[MAX_SIZE];
  char clube[MAX_SIZE];
}; // até aqui, as estruturas ainda não foram criadas

typedef struct { //aqui, elas são criadas
  struct num_serv_sec nss;
  struct info_pessoal infp;
  struct info_numer infn;
  struct morada address;
  struct confid confidencial;

}
CITIZEN_MODEL;

void le_nss(CITIZEN_MODEL * ptr) {
  printf("\n===Conteudos nss===\n num_serie: %d\n\n", ( * ptr).nss.num_serie); // =  (*ptr).num_seire
}

void le_info_pessoal(CITIZEN_MODEL * ptr) {
  printf("\n===Conteudos info pessoal===\n nome:%s\n dia_nasc:%d\n mes_nasc:%d\n ano_nasc:%d\n altura:%d\n olhos:%s\n cabelo:%s\n\n",
    ( * ptr).infp.nome,
    ( * ptr).infp.dia_nasc,
    ( * ptr).infp.mes_nasc,
    ( * ptr).infp.ano_nasc,
    ( * ptr).infp.altura,
    ( * ptr).infp.olhos,
    ( * ptr).infp.cabelo);
}

void le_info_numer(CITIZEN_MODEL * ptr) {
  printf("\n===Conteudos info numero===\n bi:%d\n contribuinte:%d\n seg_social:%d\n carta_cond:%d\n\n",
    ( * ptr).infn.bi,
    ( * ptr).infn.contribuinte,
    ( * ptr).infn.seg_social,
    ( * ptr).infn.carta_cond);
}

void le_morada(CITIZEN_MODEL * ptr) {
  printf("\n===Conteudos morada===\n rua:%s\n cod_postal1:%d\n cod_postal2:%d\n cod_postal3:%s\n\n",
    ( * ptr).address.rua,
    ( * ptr).address.cod_postal1,
    ( * ptr).address.cod_postal2,
    ( * ptr).address.cod_postal3);
}

void le_confidencial(CITIZEN_MODEL * ptr) {
  printf("\n===Conteudos confidencial===\n partido:%s\n clube:%s\n\n",
    ( * ptr).confidencial.partido,
    ( * ptr).confidencial.clube);
}

void le_tudo(CITIZEN_MODEL * person) {
  le_nss(person);
  le_info_pessoal(person);
  le_info_numer(person);
  le_morada(person);
  le_confidencial(person);
}

CITIZEN_MODEL base_de_dados[MAX_CITIZENS];
static const CITIZEN_MODEL EmptyCitizen; //usamos static para iniciar todos os valores. Bem bom. Assim não os tenho que preenher - https://stackoverflow.com/questions/10927274/gcc-uninitialized-global-variables/10927409#10927409
//https://stackoverflow.com/questions/6891720/initialize-reset-struct-to-zero-null

/*
--------------------------------------------------------------------------------------------------------------------------------------------------
*/
int inputVar;
void getNumCitizen() {
  inputVar = 0;
  

  int getNumCitizensucess = 0;

  while (getNumCitizensucess != 1) {

    printf("Write number of citizen: ");
    scanf("%d", & inputVar);

    if (inputVar > MAX_CITIZENS) {
      printf("Max number of citizens is 50. Try another number\n\n");
    } else {
      getNumCitizensucess = 1;
    }
  }

}


void deleteCitizen() {
  getNumCitizen();
  base_de_dados[inputVar - 1] = EmptyCitizen;
  le_tudo( & base_de_dados[inputVar - 1]);
}


size_t count = 0;

void writeToDatabase() {

  if (count == MAX_CITIZENS) {
    printf("\n\n\n Your database has exceeded 50 citizens \n\n\n");
    exit(0);
  } else {

    printf("num_serie: ");
    scanf("%d", & base_de_dados[count].nss.num_serie);
    getchar();

    printf("\nnome:");
    fgets(base_de_dados[count].infp.nome, MAX_SIZE, stdin);
    printf("\ndia:");
    scanf("%d", & base_de_dados[count].infp.dia_nasc);
    printf("mes:");
    scanf("%d", & base_de_dados[count].infp.mes_nasc);
    printf("ano:");
    scanf("%d", & base_de_dados[count].infp.ano_nasc);

    printf("altura:");
    scanf("%d", & base_de_dados[count].infp.altura);
    getchar();

    printf("\nolhos:");
    fgets(base_de_dados[count].infp.olhos, MAX_SIZE, stdin);
    printf("\ncabelo:");
    fgets(base_de_dados[count].infp.cabelo, MAX_SIZE, stdin);
    printf("\nbi:");
    scanf("%d", & base_de_dados[count].infn.bi);
    printf("contribuinte:");
    scanf("%d", & base_de_dados[count].infn.contribuinte);
    printf("seg_social:");
    scanf("%d", & base_de_dados[count].infn.seg_social);
    printf("carta_cond:");
    scanf("%d", & base_de_dados[count].infn.carta_cond);
    getchar();

    printf("\nrua:");
    fgets(base_de_dados[count].address.rua, MAX_SIZE, stdin);
    printf("\ncod_postal1:");
    scanf("%d", & base_de_dados[count].address.cod_postal1);
    printf("cod_postal2:");
    scanf("%d", & base_de_dados[count].address.cod_postal2);
    getchar();
    printf("\ncod_postal3:");
    fgets(base_de_dados[count].address.cod_postal3, MAX_SIZE, stdin);

    printf("\npartido:");
    fgets(base_de_dados[count].confidencial.partido, MAX_SIZE, stdin);
    printf("clube:");
    fgets(base_de_dados[count].confidencial.clube, MAX_SIZE, stdin);

  }
}

int createNotmodify(bool userchoice) {
  int temporaryVar = 0;
  if (userchoice == False) {
    /*
    tà a criar um novo cidadão em vez de modificar o que temos agora.
    apaga o cidadão 1. Em vez de escrever no 1, cria e escreve no 4.
    o problema é que count não fica com o valor de inputvar.
    */
    deleteCitizen();
    temporaryVar = count;
    inputVar = count;
    writeToDatabase();
    count = temporaryVar + 1;
    printf("\n\n\ncount variable value: %ld\n\n\n", count);

  } else if (userchoice == True) {
    writeToDatabase();
    count += 1;
    printf("\n\n\ncount variable value: %ld\n\n\n", count);

  }
  //printf("\n\n\n count: %d \n\n\n", count);

  //le_tudo( & base_de_dados[count]);

  //printf("\n\n\n count new value: %d \n\n\n", count);
  return 0;

};




void printAll_num_serie() {
  for (int i = 0; i < count; i++) {
    printf("\n\nCitizen: %d\n", i + 1);
    le_nss( & base_de_dados[i]);
  };
}

void printCertan_citizen() {
  getNumCitizen();
  printf("inputVar: %d", inputVar);
  if (inputVar > count) {
    printf("\n\n\nNo citizen for that number\n\n\n");
    exit(1);
  } else {
    le_tudo( & base_de_dados[inputVar - 1]);

  }
}

void showMenu() {
  printf("\n\n\n\n=====================================================================");
  printf("\na - Mostrar os número de série de todos os elementos da base de dados\n");
  printf("b - Mostrar toda a informação do cidadão com um certo número (a pedir)\n");
  printf("c - Modificar a informação do cidadão com um certo número (a pedir)\n");
  printf("d - Criar um novo registo para um novo cidadão\n");
  printf("e - Apagar o registo com um certo número (a pedir)\n\n");

  printf("s - Sair do programa\n\n\n");
}

void choices() {
  char choice;
  int choiceSucess = 0;
  showMenu();

  while (choiceSucess == 0) {
    choice = getchar();
    switch (choice) {
    case 'a':
      printAll_num_serie();

      break;

    case 'b':
      printCertan_citizen();

      break;

    case 'c':

      createNotmodify(False);

      break;

    case 'd':
      createNotmodify(True);

      break;

    case 'e':
      deleteCitizen();
      break;
    case 's':
      printf("\nEscolheu sair do programa\n\n");
      exit(1);
      break;

    }
  }

}

int main() {

  printf("\n\n/*********** PROGRAMA SIRP – Registo dos cidadaos **********/\n\n");
  choices();

  return 0;
}