#include <iostream>
#define tamanho 5
using namespace std;

//define a estrutura que será a fila
//a estrutura armazena a indicação do inicio e final da fila e um vetor com os itens (valores) da fila
typedef struct{
    int ini = 0;
    int fim = 0;
    int item [tamanho] ;
} FILA;

//retorna se a fila está vazia ou não
bool filaVazia(FILA p){
    if(p.ini == p.fim) {
        return true;
    } else {
        return false;
    }
}

//retorna se a fila está cheia ou não
bool filaCheia(FILA p) {
	int tam = sizeof(p.item)/sizeof(int); //determina o tamanho do vetor
	
    if (p.fim < tam) {
        return false;
    } else {
        return true;
    }
}

//adiciona valor na fila
void enfilera(FILA &p, int x){
    p.item[p.fim++] = x;
}

//remove valor da fila
int desenfilera(FILA &p){
    return (p.item[p.ini++]) ;
}

//mostra os valores armazenados na fila
void mostraFila(FILA p) {
	cout << "Valores da fila: ";
	for (int i = p.ini; i < p.fim; i++) {
		cout << p.item[i] << " ";
	}
	cout << "\n";
}


//Código para testar a implementação
int main(){
    FILA s; //criar a fila
    
    //Verificar que a fila está vazia
    if(filaVazia(s)) {
        cout<<"A fila esta vazia."<<endl;
    } else {
        cout<<"A fila nao esta vazia."<<endl;
    }
    
    //Enfilera valor e verifica se a fila está vazia
    enfilera(s,10);
    if(filaVazia(s)) {
        cout<<"A fila esta vazia."<<endl ;
    } else {
        cout<<"A fila nao esta vazia."<<endl;
    }
    
    //Insere 3 elementos na fila
    enfilera(s,20);
    enfilera(s,30);
    enfilera(s,40);

	//Mostra os valores da fila
    mostraFila(s);
    
    //Verifica que a fila está cheia
    if(filaCheia(s)) {
        cout<<"A fila esta cheia."<<endl;
    } else {
        cout<<"A fila nao esta cheia."<<endl;
    }
    
    //Enfilera valor e verifica se a fila esta cheia
    enfilera(s,50);
    mostraFila(s);
    if(filaCheia(s)) {
        cout<<"A fila esta cheia."<<endl;
    } else {
        cout<<"A fila nao esta cheia."<<endl;
    }
    
    //Desempilha e mostrar o valor desempilhado
    cout<<"Valor removido da fila: "<< desenfilera(s) <<endl;

	mostraFila(s);

    if(filaCheia(s)) {
        cout<<"A fila esta cheia."<<endl;
    } else {
        cout<<"A fila nao esta cheia."<<endl;
    }
    
    return 0;
}
