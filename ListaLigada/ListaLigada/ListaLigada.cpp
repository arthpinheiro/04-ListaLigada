
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	int numero;

	cout << "Digite o elemento: ";
	cin >> numero;

	NO* aInserir = posicaoElemento(numero);

		if (aInserir != NULL) {
			cout << "O elemento ja esta presente na lista! \n";
		}
		else {
			novo->valor = numero;
			novo->prox = NULL;

			if (primeiro == NULL)
			{
				primeiro = novo;
			}
			else
			{
				// procura o final da lista
				NO* aux = primeiro;
				while (aux->prox != NULL) {
					aux = aux->prox;
				}
				aux->prox = novo;
			}
		}
	

}

void excluirElemento()
{
	int numero;

	cout << "Digite o elemento a ser excluido: \n";
	cin >> numero;

	NO* auxExclusao = posicaoElemento(numero);

	if (auxExclusao != NULL) {
		NO* aux = primeiro; //variavel aux pega o valor do primeiro elemento da lista
		NO* paraExcluir = NULL; // elemento pra excluir primeiramente � null

		if (aux->valor == numero) { //aqui � o primeiro if pra verificar se o valor � o primeiro da lista
			paraExcluir = primeiro; // o elemento pra excluir vira o primeiro da lista
			primeiro = aux->prox; // j� que o primeiro ser� excluido, o primeiro agora vira o proximo valor da lista, caso n tenha outro valor ele vir� NULL
			free(paraExcluir);
			cout << "Elemento excluido com sucesso! \n";
		}
		else {
			while (aux->prox != NULL) { // caso n seja o primeiro elemento, ele vai comecar a procurar pelo prox elemento
				NO* proximo = aux->prox;
				if (proximo->valor == numero) { // aqui ele pega o valor do prox elemento e verifica se � igual ao numero digitado
					paraExcluir = aux->prox; // torna o valor paraExcluir o prox
					proximo->prox = paraExcluir->prox; //coloca o proximo valor para apontar pro proximo valor depois do valor excluido
					free(paraExcluir);
					cout << "Elemento excluido com sucesso! \n";
					break;
				}
			}
			
		}
	}
	else {
			cout << "O elemento nao esta presente na lista! \n";
	}
}

void buscarElemento()
{
	int numero;

	cout << "Digite o elemento que deseja buscar: \n";
	cin >> numero;

	NO* encontrado = posicaoElemento(numero);
	
	if (numero != NULL) {
		cout << "O elemento digitado esta na posicao: " << encontrado << endl;
	}
	else {
		cout << "Elemento nao encontrado! \n";
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}