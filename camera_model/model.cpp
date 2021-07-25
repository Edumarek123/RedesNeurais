#include <iostream>
#include "../libs/matriz_lib.h"
#include "../libs/rede_neural_lib.h"
#include <time.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <fstream>
#include <conio.h>


Matriz* recebe_entradas(std::string path);
int ajusta_saidas(Matriz* m);
void imprimir_algarismo(Matriz* entradas);
void filtro(Matriz* m);


int main()
{
  srand(time(NULL));

  int tam_Lx=784, tam_Ly=10;
  float LEARNING_RATE=0.02;
  vector<int> tams_Lh {64};

  RedeNeural* NN=new RedeNeural(tam_Lx, tam_Ly, tams_Lh, LEARNING_RATE);
  NN->carregar_rede("../training/rede_neural.txt");

  Matriz* entradas=new Matriz(784, 1);

  std::cout<<"Iniciando..."<<std::endl;
  while(1)
    do{
      delete entradas;
      system("python3 webcam.py");
      entradas=recebe_entradas("pipe_data.txt");
      NN->FeedFoward(entradas);
      // filtro(entradas);
      imprimir_algarismo(entradas);
      std::cout<<"Algarismo calculado: "<<ajusta_saidas(NN->saidas[NN->numero_layers-2])<<std::endl;
    }while(cin.get()!='\n');

  delete NN;

  return 0;
}

Matriz* recebe_entradas(std::string path){
    fstream arquivo;
    arquivo.open(path, ios::in);
    std::string valor, linha;

    Matriz* dados=new Matriz(784, 1);

    if(arquivo.is_open()){
      sleep(1);
      getline(arquivo, linha);
      std::istringstream iss(linha);

      for(int i=0;i<784;i++){
        std::getline(iss, valor, ' ');
        dados->matriz[i][0]=std::stof(valor);
        dados->matriz[i][0]=255-dados->matriz[i][0];
        dados->matriz[i][0]/=255;
      }
    }
    else
      std::cout<<"erro"<<std::endl;

    arquivo.close();
    return dados;
}

int ajusta_saidas(Matriz* m){
  int maxP=-1;
  float maxV=0;
  for(int i=0;i<m->linhas;i++){
    if(m->matriz[i][0]>maxV){
      maxV=m->matriz[i][0];
      maxP=i;
    }
  }
  return maxP;
}

void imprimir_algarismo(Matriz* dados){
  Matriz* printar=new Matriz(28, 28);
  int k=0;
  for(int i=0;i<28;i++){
    for(int j=0;j<28;j++){
      printar->matriz[i][j]=dados->matriz[k][0];
      k++;
    }
  }

  system("clear");

  for(int i=0;i<28;i++){
    for(int j=0;j<28;j++){
      if(printar->matriz[i][j]>0.9){
        textbackground(15);
        std::cout<<"##";
      }else {
        textbackground(7);
        std::cout<<"  ";
      }
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl<<std::endl;
}


void filtro(Matriz* m){
  float media;
  for(int i=0;i<m->linhas;i++)
    media+=m->matriz[i][0];
  media/=784;

  for(int i=0;i<m->linhas;i++){
      if(m->matriz[i][0]<media)
        m->matriz[i][0]=1;
      else
        m->matriz[i][0]=0;
    }
}



//g++ -o mnist main.cpp rede_neural_lib.cpp matriz_lib.cpp
