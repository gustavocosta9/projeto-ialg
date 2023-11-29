/* --------    Nome: Gustavo Costa        -----------
-----------Universidade Federal de Lavras -----------*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;


struct base{
	long long codigo;
	char descricao [100];
	char situacao [100];
	float preco_custo;
	float preco_venda;
	bool disponibilidade = true; //variável para conferir se a base está ativa ou inativa
};


void binarioInicio(){ //função responsável por ler o csv e transformar em binario

	//Ler o arquivo csv.
	ifstream ler("base11_OK.csv"); //ponteiro do arquivo.
	string linha; 
	base produto;
	
	//Limpar o arquivo se ele já existir:
	ofstream limpaBin ("arqBinario", ios_base::binary | ios_base::trunc);
	limpaBin.close();
	
	//Abrir o binário para a escrita inicial.
	ofstream binarioInicial("arqBinario", ios_base::binary | ios_base::app);
	
	while(getline(ler, linha)){ //Vai ler até o \n de cada linha.
 		
 		stringstream linhaInteira;
 		linhaInteira << linha; //Estou utilizando o operador de inserir na variável do tipo stringstream que pode converter string em num.
 		string fim;
 		
 		
 		
 		getline(linhaInteira, fim, ';');
 		stringstream (fim) >> produto.codigo; 
 		
 		getline(linhaInteira, fim, ';');
 		strcpy (produto.descricao, fim.c_str());
 		
 		getline(linhaInteira, fim, ';');
 		stringstream (fim) >> produto.situacao;
 		
 		getline(linhaInteira, fim,';'); 		
 		stringstream (fim) >> produto.preco_custo;
 		
 		getline(linhaInteira, fim, '\n');
 		stringstream (fim) >> produto.preco_venda;
 			
 		binarioInicial.write((char *) &produto, sizeof(base)); //Inserindo o produto direto no arquivo Bin.
	}
	
	ler.close();
	binarioInicial.close();
}


void adicionarNovo(){ //função responsável por adicionar produto na base de dados
	
	string descricaoS;
	base R;
	cout<<"Digite o ID do produto: ";
	cin>>R.codigo;
	cin.ignore();
	
	cout<<"Digite a descricao do produto: ";
	getline(cin, descricaoS);
	strcpy(R.descricao, descricaoS.c_str());
	
	cout<<"Digite a situacao do produto (Liberado ou Regulado): ";
	cin>>R.situacao; //tipo char, mas leu como string.
	
	cout<<"Digite o preco de custo do produto: ";
	cin>>R.preco_custo;
	
	cout<<"Digite o preco de venda do produto: ";
	cin>>R.preco_venda;
	
	ofstream inserir("arqBinario", ios_base::binary | ios_base::app); //Adicionando a variável R direto no Bin.
	inserir.write((char *) &R, sizeof(base));
	
	inserir.close();
	cout<<"Dados adicionados com sucesso."<<endl<<endl;
}


void buscaID(){//função responsável por buscar os produtos por ID
	
	long long IDprocurado;
	base IDcomparado;
	int verif = 0;
	
	cout<<"Digite o ID do produto: ";
	cin >> IDprocurado;
	
	ifstream procurarID ("arqBinario", ios_base::binary);
	
	while(procurarID.read((char *) &IDcomparado, sizeof(base))){
	
			if(IDprocurado == IDcomparado.codigo and IDcomparado.disponibilidade == true){
				cout<<IDcomparado.codigo<<" "<<IDcomparado.descricao<<" "<<IDcomparado.situacao<<" "<<IDcomparado.preco_custo<<" "<<IDcomparado.preco_venda<<endl;
				verif++;
			}
	}
	
	if(verif==0){ //Caso não ache a ID na busca, a variavel de verificacao nao se altera, logo = ID não existe.
		cout<<"ID NAO ENCONTRADO!"<<endl;
	}	
	
	procurarID.close();
	cout<<endl;
}


void buscaCusto(){//função responsável por buscar os produtos por preço de custo
	
	float custo_procurado;
	base custo_comparado;
	int verif2=0;
	
	cout<<"Digite o preco de custo do produto: ";
	cin >> custo_procurado;
	
	ifstream procurarCusto ("arqBinario", ios_base::binary);
	while (procurarCusto.read((char*) &custo_comparado, sizeof(base))){
			if(custo_procurado == custo_comparado.preco_custo and custo_comparado.disponibilidade == true){
				cout<<custo_comparado.codigo<<" "<<custo_comparado.descricao<<" "<<custo_comparado.situacao<<" "<<custo_comparado.preco_custo<<" "<<custo_comparado.preco_venda<<endl;
				verif2++;
			}
	}
	if(verif2==0){
		cout<<"PRECO DE CUSTO NAO ENCONTRADO!"<<endl;
	}
	procurarCusto.close();
	cout<<endl;
}


void busca(){//menu de busca
	cout<<"METODOS DE BUSCA:"<<endl;
	cout<<"Digite (1) para busca por ID."<<endl;
	cout<<"Digite (2) para busca por preco de custo."<<endl;
	int operacao4;
	cin>>operacao4;
	cout<<endl;
	if(operacao4 == 1){
		buscaID();
	} else if(operacao4 == 2){
		buscaCusto();
	}
}


void deletaProduto(){//função responsável por deletar os produtos por ID
	long long IDprocurado;
	int i = 0, aux_indice;
	base IDcomparado, aux;
	cout<<"Digite o ID do produto que deseja apagar: ";
	cin >> IDprocurado;
	
	ifstream procurarID ("arqBinario", ios_base::binary);
	
	while(procurarID.read((char *) &IDcomparado, sizeof(base))){
		if(IDprocurado == IDcomparado.codigo){
			aux_indice = i;
			aux = IDcomparado;
		}
		i++;
	}
	procurarID.close();
	
	aux.disponibilidade = false;
	
	fstream localizaID ("arqBinario", ios_base::binary | ios_base::out | ios_base::in);
	localizaID.seekp(aux_indice * sizeof(base));
	localizaID.write((char *) &aux, sizeof(base));
	localizaID.close();
	
	cout<<"Arquivo apagado com sucesso."<<endl<<endl;
}


void intercala_codigo(base a[], int inicio, int meio, int fim){
    int i = inicio, j = meio + 1;
    int tamanho = fim - inicio + 1;
    base aux[tamanho]; // vetor auxiliar
    
    for (int k=0; k < tamanho; k++) {
        if ((i <= meio) and (j <= fim)){ 
            if (a[i].codigo <= a[j].codigo){ 
                aux[k] = a[i]; // copia trecho1 em aux[]
                i++;             // avanÃ§a em trecho1
            } else { // 
                aux[k] = a[j]; // copia trecho2 em aux[]
                j++;             // avanca em trecho2
             }    
             } else if (i > meio) { // terminou o trecho1    
            aux[k] = a[j];
            j++;
        } else {                  // terminou o trecho2
            aux[k] = a[i];
            i++;
        }        
    }    
    // terminando: copiar de aux[] em a[inicio:fim]
    for (int k=0; k < tamanho; k++){ 
        a[inicio + k] = aux[k];
    }
}


void mergesort_codigo(base a[], int inicio, int fim){
	
    int meio;
    
    if (inicio < fim) {
        meio = (inicio + fim)/2; 
        mergesort_codigo(a, inicio, meio);
        mergesort_codigo(a, meio+1, fim);
        intercala_codigo(a, inicio, meio, fim);
    }
}


void intercala_preco(base a[], int inicio, int meio, int fim){
    int i = inicio, j = meio + 1;
    int tamanho = fim - inicio + 1;
    base aux[tamanho]; // vetor auxiliar
    
    for (int k=0; k < tamanho; k++) {
        if ((i <= meio) and (j <= fim)){ 
            if (a[i].preco_custo <= a[j].preco_custo){ 
                aux[k] = a[i]; // copia trecho1 em aux[]
                i++;             // avanÃ§a em trecho1
            } else { // 
                aux[k] = a[j]; // copia trecho2 em aux[]
                j++;             // avanca em trecho2
             }    
             } else if (i > meio) { // terminou o trecho1    
            aux[k] = a[j];
            j++;
        } else {                  // terminou o trecho2
            aux[k] = a[i];
            i++;
        }        
    }    
    // terminando: copiar de aux[] em a[inicio:fim]
    for (int k=0; k < tamanho; k++){ 
        a[inicio + k] = aux[k];
    }
}


void mergesort_preco(base a[], int inicio, int fim){
    
    int meio;
    
    if (inicio < fim) {
        meio = (inicio + fim)/2; 
        mergesort_preco(a, inicio, meio);
        mergesort_preco(a, meio+1, fim);
        intercala_preco(a, inicio, meio, fim);
    }
}


void ordenacao(){//menu de ordenação e atualiozação do arquivo
    
	ifstream leitura("arqBinario", ios_base::binary);
	leitura.seekg(0, ios::end);
	int tamanho = leitura.tellg()/sizeof(base);
	base aux;
	base remedios[tamanho];
		
	for(int i = 0; i < tamanho; i++){	
		leitura.seekg(i * sizeof(base));
		leitura.read((char *) &aux, sizeof(base));
		remedios[i] = aux;
	}
	leitura.close();
		
	cout<<"METODOS DE ORDENACAO:"<<endl;
	cout<<"Digite (1) para ordenar por ID."<<endl;
	cout<<"Digite (2) para ordenar por preco de custo."<<endl;
	int operacao2;
	cin>>operacao2;
	if(operacao2 == 1){
		mergesort_codigo(remedios, 0, tamanho-1);
	} else if(operacao2 == 2){
		mergesort_preco(remedios, 0, tamanho-1);
	}
		
	ofstream limpaBin ("arqBinario", ios_base::binary | ios_base::trunc);
	limpaBin.close();
		
	ofstream reescreveBin ("arqBinario", ios_base::binary | ios_base::app);
	for(int i = 0; i < tamanho; i++) {
		reescreveBin.seekp(i * sizeof(base));
		if(remedios[i].disponibilidade == true)
			reescreveBin.write((char *) &remedios[i], sizeof(base));
	}
	reescreveBin.close();
	cout << "Ordenacao concluida" << endl;
	
	if (operacao2 != 1 and operacao2 != 2) {
		cout << "Opcao de ordenacao invalida" << endl;
	}
	cout<<endl;
}


void impressao(){//função responsável por imprimir o arquivo binário
	
	cout<<"Digite (1) para imprimir um trecho."<<endl<<"Digite (0) para imprimir todos os dados."<<endl;
	int operacao5, indice = 1;
	cin>>operacao5;
	base imprimir;
	
	ifstream leitura("arqBinario", ios_base::binary | ios_base::ate);
	
	int inicio, fim = leitura.tellg()/sizeof(base);
	
	
	if(operacao5 == 1){
		cout<<"Digite a posicao inicial da impressao:"<<endl;
		cin>>inicio;
		cout<<"Digite a posicao final da impressao:"<<endl;
		cin>>fim;
		for(int i=inicio-1;i<=fim-1;i++){
			
			leitura.seekg(i * sizeof(base));
			leitura.read((char *) &imprimir, sizeof(base));
			if(imprimir.disponibilidade == true){
				cout<<indice<<" "<<imprimir.codigo<<" "<<imprimir.descricao<<" "<<imprimir.situacao<<" "<<imprimir.preco_custo<<" "<<imprimir.preco_venda<<endl;
				indice++;
			}
		}
	}
	else if(operacao5 == 0){
		for(int i = 0; i < fim; i++){
			
			leitura.seekg(i * sizeof(base));
			leitura.read((char *) &imprimir, sizeof(base));
			if(imprimir.disponibilidade == true){
				cout<<indice<<" "<<imprimir.codigo<<" "<<imprimir.descricao<<" "<<imprimir.situacao<<" "<<imprimir.preco_custo<<" "<<imprimir.preco_venda<<endl;
				indice++;
			}
		}
	}
	cout<<endl;
}


void exportacao(){//função responsável por exportar os dados para um arquivo csv
    ofstream escrita("baseAtualizada.csv");//novo arquivo csv
	ifstream leitura("arqBinario", ios_base::binary);//leitura do binário
	leitura.seekg(0, ios::end);
	int tamanho = leitura.tellg()/sizeof(base);
	base gravacao;
	
	for(int i = 0; i < tamanho; ++i){//escrita do arquivo novo + conferindo se os dados são válidos
		leitura.seekg(i * sizeof(base));
		leitura.read((char *) &gravacao, sizeof(base));
		if(gravacao.disponibilidade == true){
			escrita<<gravacao.codigo<<";"<<gravacao.descricao<<";"<<gravacao.situacao<<";"<<gravacao.preco_custo<<";"<<gravacao.preco_venda<<"\n";
		}
	}
	
	escrita.close();
	leitura.close();
	cout<<"Exportacao feita com sucesso!"<<endl<<endl;
}


int main(){

	binarioInicio();
	
	int decisao = 1;
	while(decisao != 0){
		
		//menu de inicialização
		cout<<"MENU DE ACOES: APERTE A TECLA CORRESPONDENTE PARA CADA ACAO."<<endl;
		cout<<"(1) Adicionar um novo produto ao banco de dados."<<endl;
		cout<<"(2) Selecionar um metodo de ordenacao."<<endl;
		cout<<"(3) Apagar um produto ja existente."<<endl;
		cout<<"(4) Metodos de busca de um produto."<<endl;
		cout<<"(5) Imprimir um trecho do banco de dados."<<endl;
		cout<<"(6) Exportar os dados para um arquivo CSV."<<endl;
		cout<<"(7) Finalizar o programa."<<endl;
		
		int num;
		cin>>num;
		system("clean||cls"); //código para limpar a tela de execução no windows(clean) e linux(cls)
		
		switch (num){
			case 1:
				adicionarNovo();
				break;
			
			case 2:
				ordenacao();
				break;
			
			case 3:
				deletaProduto();
				break;
				
			case 4:
				busca();
				break;
				
			case 5:
				impressao();
				break;
				
			case 6:
				exportacao();
				break;
				
			case 7:
				decisao = 0;
				break;
		
		}
	}
	return 0;
}
