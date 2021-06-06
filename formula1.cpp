#include <iostream>
#include <algorithm>
using namespace std;

struct piloto{
    int id, colocacoes[105], pontos;
};    

int func(piloto a, piloto b){
    if(a.pontos!=b.pontos){
        return a.pontos > b.pontos;//ordena do primeiro para o ultimo;
    }else{
        return a.id < b.id;
    }
}

int main(){
    int corridas, pilotos, colocacao;
    cin >> corridas >> pilotos;
    while (corridas!=0){
        piloto v[pilotos];
        //inicialização;
        for(int i=0; i<corridas; i++){
            for(int q=0; q<pilotos; q++){
                cin >> colocacao;
                v[q].id = q+1;
                v[q].pontos = 0;
                v[q].colocacoes[i]=colocacao;
            }
        }
        //pontuacao;
        int s, k, x;
        cin >> s;
        for(int i = 0; i<s; i++){
            cin >> k;
            for(int j=0; j<k; j++){
                cin >> x;
                for(int l=0; l<pilotos; l++){
                    for(int m=0; m<corridas; m++){
                        if(v[l].colocacoes[m]==j+1){
                            v[l].pontos += x;
                        }
                    }
                }
            }
            sort(v, v+pilotos, func);
            int ponto = v[0].pontos;
                for(int q=0; q<pilotos;q++){
                    if(v[q].pontos==ponto){
                        cout << v[q].id << " ";
                    }
                    v[q].pontos = 0;
                }
                cout << endl;
        }
        cin >> corridas >> pilotos;
    }

    return 0;
}