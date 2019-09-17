#include <iostream>
#include <iterator>     // std::distance
#include <functional>
#include <chrono>
#include <ctime>
#include <ratio>
#include <sys/resource.h>

void swap ( int *a, int* b )
{
    int c;
  c=*a; *a=*b; *b=c;
}



void print( int * f, int * l )
{
    std::cout << "[ ";
    while ( f != l )  std::cout << *f++ << " ";
    std::cout << "] \n";
}

void Criaedesordem(int vetor[], float desordem, int tamanho){
	int i;
	int taxa = desordem*tamanho/2;
	for(i=0;i<taxa;i++){
		vetor[i] = i;
	}
	for(i=0;i<taxa;i++){
		swap(&vetor[i], &vetor[taxa - i -1]);
	}
}


void merge(int *first, int *meio, int *last){
	int i, j, k;
	int tam1 = std::distance(first , meio + 1);
	int tam2 = std::distance(meio, last);

	int L[tam1], R[tam2];

	for(i=0;i<tam1;i++){
		L[i] = *(first + i);
	}

	for(i=0;i<tam2;i++){
		R[i] = *(meio + 1 + i);
	}
	int *f1 = &L[0];
	int *l1 = &L[tam1];
	int *f2 = &R[0];
	int *l2 = &R[tam2];
	int *f3 = first;

	 while(f1 < l1 || f2 < l2){
        if(f1 == l1){
            *f3 = *f2;
            f3++;
            f2++;
        }else if(f2 == l2){
            *f3 = *f1;
            f3++;
            f1++;
        }
        else if(*f1<*f2){
            *f3 = *f1;
            f3++;
            f1++;
        }else if(*f2<*f1){
            *f3 = *f2;
            f3++;
            f2++;
        }

    }
	
}

void mergesort(int *first, int *last){
	if(first<last){	
	int *meio =  first + (last - first)/2; 
	mergesort(first, meio);
	mergesort(meio + 1, last);
	merge(first, meio, last);

	}
}



int * partition( int *first, int *last, int * pivot)
{
    int *fast, *slow;
    fast = first;
    slow = first;
    while(fast<pivot+1){
        if(*fast < *pivot){
            swap(fast, slow);
            slow++;
        }
          fast++;
    }
    swap(pivot, slow);
    return slow;
}

void quicksort(int *first, int *last){
	if(first<last){	
	int *pivot = partition(first, last, last-1);
	quicksort(first, pivot);
	quicksort(pivot+1, last);
	

	}
}

int selection_sort(int *vetor,int tamanho);

int selection_sort(int *vetor,int tamanho){
	int i, menor, tam;
		tam=0;	
		while(tam<tamanho){
			menor = vetor[tam];
			for(i=tam;i<tamanho;i++){
				if(vetor[i]< menor ){
					menor = vetor[i];
					swap(&vetor[i], &vetor[tam]);
				}
			}
		tam++;
		}
} 

void shell_sort(int *a, int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < size);
  
 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}

void AlocarMemoria(){
	const rlim_t kStackSize = 128L * 1024L * 1024L;
	struct rlimit rl;
	int resultado;

  resultado = getrlimit(RLIMIT_STACK, &rl);
  if (resultado == 0)
  {
      if (rl.rlim_cur < kStackSize){
          rl.rlim_cur = kStackSize;
          resultado = setrlimit(RLIMIT_STACK, &rl);  
     }
	}
}

void ChamQuickSort(int TamanhoFinal, float Ordenacao){
	using namespace std::chrono;
	int Tamanho = 1;
	std::cout << "\nquicksort \n";
	while(TamanhoFinal >= Tamanho){
	 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int i=0;i<5;i++){
			int vetor[Tamanho];
			Criaedesordem(vetor, Ordenacao, Tamanho);
			quicksort(&vetor[0], &vetor[Tamanho]);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
		Tamanho = Tamanho * 10;
	}
}

void ChamMergeSort(int TamanhoFinal, float Ordenacao){
	using namespace std::chrono;
	int Tamanho = 1;
	std::cout << "\nmergesort \n";
	while(TamanhoFinal >= Tamanho){
	 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int i=0;i<5;i++){

			int vetor[Tamanho];
			Criaedesordem(vetor, Ordenacao, Tamanho);
			mergesort(&vetor[0], &vetor[Tamanho-1]);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
		Tamanho = Tamanho * 10;
	}
}

void ChamSelectionSort(int TamanhoFinal, float Ordenacao){
	using namespace std::chrono;
	int Tamanho = 1;
	std::cout << "\nselection_sort \n";
	while(TamanhoFinal >= Tamanho){
	 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int i=0;i<5;i++){
			int vetor[Tamanho];
			Criaedesordem(vetor, Ordenacao, Tamanho);
			selection_sort(vetor, Tamanho);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
		Tamanho = Tamanho * 10;
	}
}

void ChamShellSort(int TamanhoFinal, float Ordenacao){
	using namespace std::chrono;
	int Tamanho = 1;
	std::cout << "\nshell_sort \n";
	while(TamanhoFinal >= Tamanho){
	 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int i=0;i<5;i++){
			int vetor[Tamanho];
			Criaedesordem(vetor, Ordenacao, Tamanho);
			shell_sort(vetor, Tamanho);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
		Tamanho = Tamanho * 10;
	}
}

int main(){
	int TamanhoFinal;
	float Ordenacao;
	float Ord[4] = {0, 0.5, 0.75, 1};
	using namespace std::chrono;
	std::cout << "Digite o tamanho do vetor \n";
	std::cin >> TamanhoFinal; 
	for(int i=0;i<4;i++){
		Ordenacao = Ord[i];
		std::cout << "\n\n\n fator ordenacao: " << Ordenacao << "\n\n\n";

		ChamMergeSort(TamanhoFinal, Ordenacao);
		ChamQuickSort(TamanhoFinal, Ordenacao);
		ChamSelectionSort(TamanhoFinal, Ordenacao);
		ChamShellSort(TamanhoFinal, Ordenacao);
	} 
}
