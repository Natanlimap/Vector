#include <iostream>

void vetores(int *vetor, int *vetor2, int *vetor3, int *vetor4, int tamanho);
void vetores(int *vetor, int *vetor2, int *vetor3, int *vetor4, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		vetor[i]=i;
	}
	for(i=0;i<tamanho;i++){
		vetor2[i] = vetor3[i] = vetor4[i] = vetor[i];
	std::cout<<vetor2[i];
	}

}
int main(){
	int tamanho = 10;
	int vetor[tamanho];
	int vetor2[tamanho];
	int vetor3[tamanho];
	int vetor4[tamanho];
	vetores(vetor, vetor2, vetor3, vetor4, tamanho);		
	
}
