#include <iostream>
#include <string>

using namespace std;

//variaveis
int quantidadeTuberculos, quantidadeFrutas, quantidadeFolhosas, quantidadeLegumes, quantidadeQuitanda = 0;
string nome, tuberculo, frutas, folhosas, legumes, quitanda, confirma;
string cesta;
bool adicional = false;
float preco = 0;

void cestaFunc(){
    cout << "Escolha sua cesta:" << endl;
    cout << "Cesta Pequena (P):\n 1kg de tuberculo\n 1.5kg de frutas\n 1 folhosa (1 tipo)\n 1kg de legumes (ate 2 itens)\n Valor: R$50,00" << endl;
    cout << "Cesta Media (M):\n 2kg de tuberculo\n 2.5kg de frutas\n 2 folhosa (2 tipos)\n 1.5kg de legumes (ate 3 itens)\n 1 item da quitanda\n Valor: R$100,00" << endl;
    cout << "Cesta Grande (G):\n 3kg de tuberculo\n 3.5kg de frutas\n 3 folhosa (3 tipos)\n 3kg de legumes (ate 3 itens)\n 1 a 2 itens da quitanda\n Valor: R$200,00" << endl;
    cout << "Insira alternativa: ";
    cin >> cesta;
    if(cesta == "P" || cesta == "p"){
        preco = 50.00;
    }
    if(cesta == "M" || cesta == "m"){
        preco = 100.00;
    }
    if(cesta == "G" || cesta == "g"){
        preco = 200.00;
    }
}

void tuberculoFunc(string opcao){
    cout << "Tuberculos:" << endl;
    cout << "Deseja Batata? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeTuberculos++;
    }
    cout << "Deseja Cenoura? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeTuberculos++;
    }
}

void frutasFunc(string opcao){
    cout << "Frutas:" << endl;
    cout << "Deseja Banana? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFrutas++;
    }
    cout << "Deseja Laranja? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFrutas++;
    }
    cout << "Deseja Mamão? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFrutas++;
    }
}
void folhosasFunc(string opcao){
    cout << "Folhosas:" << endl;
    cout << "Deseja Brocolis? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFolhosas++;
    }
    cout << "Deseja Alface? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFolhosas++;
    }
    cout << "Deseja Rucula? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeFolhosas++;
    }
}
void legumesFunc(string opcao){
    cout << "Legumes:" << endl;
    cout << "Deseja Abobora? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeLegumes++;
    }
    cout << "Deseja Tomate? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeLegumes++;
    }
    cout << "Deseja Chuchu? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeLegumes++;
    }
}
void quitandaFunc(string opcao){
    cout << "Quitanda:" << endl;
    cout << "Deseja Geleia? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeQuitanda++;
    }
    cout << "Deseja Ovos? SIM/NAO" << endl;
    cin >> opcao;
    if(opcao == "SIM" || opcao == "sim"){
        quantidadeQuitanda++;
    }
}
void valorCesta(){
    if(cesta == "P" || cesta == "p"){
        if(quantidadeFolhosas > 1){
            adicional = true;
        }
        if(quantidadeLegumes > 2){
            adicional = true;
        }
        if(quantidadeQuitanda >= 1){
            adicional = true;
        }
    }
    if(cesta == "M" || cesta == "m"){
        if(quantidadeFolhosas > 2){
            adicional = true;
        }
        if(quantidadeQuitanda > 1){
            adicional = true;
        }
    }
}
int main(){

    //nome
    cout << "Insira seu nome: ";
    cin >> nome;
    //cesta
    cestaFunc();
    //1
    tuberculoFunc(tuberculo);
    //2
    frutasFunc(frutas);
    //3
    folhosasFunc(folhosas);
    //4
    legumesFunc(legumes);
    //5
    quitandaFunc(quitanda);

    //calculo
    valorCesta();

    if(adicional){
        preco += ((preco*50)/100);
    }
    //frete
    preco += 15;

    //output
    cout << nome << endl;
    cout << "Cesta: " << cesta << endl;
    if(quantidadeTuberculos >= 1){
    cout << "Tuberculos: " << quantidadeTuberculos << endl;
    }
    if(quantidadeFrutas >= 1){
    cout << "Frutas: " << quantidadeFrutas << endl;
    }
    if(quantidadeFolhosas >= 1){
    cout << "Folhosas: " << quantidadeFolhosas << endl;
    }
    if(quantidadeLegumes >= 1){
    cout << "Legumes: " << quantidadeLegumes << endl;
    }
    if(quantidadeQuitanda >= 1){
    cout << "Quitandas: " << quantidadeQuitanda << endl;
    }
    if(adicional){
    if(cesta == "P" || cesta == "p"){
    cout << "Valor: " << preco << " reais" << "(" << (preco-15) <<"+ 50%)" << "+ 15 de frete" << endl;
    }
    if(cesta == "M" || cesta == "m"){
    cout << "Valor: " << preco << " reais" << "(" << (preco-15) <<"+ 50%)" << "+ 15 de frete" << endl;
    }
    if(cesta == "G" || cesta == "g"){
    cout << "Valor: " << preco << " reais" << "(" << (preco-15) <<"+ 50%)" << "+ 15 de frete" << endl;
    }
    }else {
    if(cesta == "P" || cesta == "p"){
    cout << "Valor: 50 reais + 15 de frete" << endl;
    }
    if(cesta == "M" || cesta == "m"){
    cout << "Valor: 100 reais + 15 de frete" << endl;
    }
    if(cesta == "G" || cesta == "g"){
    cout << "Valor: 200 reais + 15 de frete" << endl;
    }
    }
    cout << "Total: " << preco << " reais" << endl;
    cout << "Confirma pedido? (Sim ou Nao)";
    cin >> confirma;
}
