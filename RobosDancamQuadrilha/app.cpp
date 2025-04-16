// file:    app.cpp
// author:  Diogo Marques da Silva
// date:    30/03/2025
// file description:
//      Implementacao da solucao 2 descrita no relatorio da atividade.

#include <iostream>
#include <fstream>
#include <chrono> //Utilizada para medir o tempo

using namespace std;

bool veteq(int * vet1, int * vet2, int n){
    for(int i = 0; i < n; i++){
        if(vet1[i] != vet2[i]){
            return false;
        }
    }
    return true;
}



int main(){
    
    auto start = chrono::high_resolution_clock::now();

    ifstream file("casosteste/caso74.txt"); // alterar o arquivo para rodar outros testes
    int n = 0;
    file >> n;
    int firstpos[n];
    int robots[n];
    long rodadas = 1;

    // lendo a posicao inicial e populando robots[]
    for(int i = 0; i < n; i++) {
        file >> firstpos[i];
        robots[i] = i;
    }
    
    if(!file.is_open()){

        cerr << "erro ao abrir o arquivo!" << endl;

    } else {
        int i = 0;
        int pos = 0;
        int temp[n];
        
    while(1){
        if(i == n){
            i = 0; 
            rodadas++;
            // Atualiza os robos, atraves do vetor temporario
            for(int j = 0; j < n; j++){robots[j] = temp[j];}
        }

        if(veteq(robots, firstpos, n) && rodadas > 2){
        cout << "Parando o programa...\ncom " << rodadas << " rodadas" << endl;
        break;
        }
    
        pos = firstpos[i];
        temp[i] = robots[pos];
    
         i++;
    }
        cout << "Printing robots..." << endl;
        for(int i = 0; i < n; i++){
            cout << robots[i] << " ";
        }
        cout << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Tempo de execucao: " << duration.count() << " segundos" << endl;
        cout << "n = " << n << " " << duration.count() << " segundos" << endl;
        file.close();
    }

    return 0;
}

