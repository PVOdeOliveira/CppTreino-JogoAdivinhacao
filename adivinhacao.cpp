#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    char dificuldade;
    int numeroDeTentativas, chute, tentativas=0, numeroSecreto;
    double pontuacao = 1000.0;
    bool NaoAcertou = true;

    srand(time(NULL));
    numeroSecreto = rand()%100; //gera um numero secreto entre 0 e 99
    
    cout << "***************************************" << endl;
    cout << "*  Bem Vindos ao jogo de adivinhacao  *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha a dificuldade: " << endl;
    cout << "Facil(F)\nMedio(M)\nDificil(D)" << endl;

    cin >> dificuldade;

    if(dificuldade == 'F' || dificuldade == 'f'){
        numeroDeTentativas=15;
    }
    else if(dificuldade == 'M' || dificuldade == 'm'){
        numeroDeTentativas=10;
    }
    else if(dificuldade == 'D' || dificuldade == 'd'){
        numeroDeTentativas=5;
    }
    else{
        cout << "Opcao nao existente!" << endl;
        return 0; //encerra o programa em caso de escolha errada de dificuldade
    }

    for(tentativas = 1; tentativas <=numeroDeTentativas; tentativas++)
    {
        cout << "Tentativa " << tentativas << endl;
        cout << "Digite o seu chute:" << endl;
        cin >> chute;

        bool acertou = chute == numeroSecreto;
        bool chuteMenor = chute < numeroSecreto;

        if(acertou){
            cout << "Parabens! Voce acertou em "<< tentativas <<" tentativas!! \nO numero secreto e " << numeroSecreto << "!" << endl;
            NaoAcertou=false;
            break;
        }
        else if(chuteMenor){
            cout << "O numero secreto e maior que " << chute << "!" << endl;
        }
        else{
            cout << "O numero secreto e menor que " << chute << "!" << endl;
        }
        pontuacao = pontuacao - (abs(chute - numeroSecreto)/2.0);
    }

    if(NaoAcertou){
        cout << "\n\nFim de jogo!!" << endl;
        cout << "Voce perdeu! Tente Novamente!" << endl;
    }
    else{
        cout << "\n\nFim de jogo!!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de "<< pontuacao << endl;
    }
    
}
