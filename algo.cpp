#include <iostream>
#include <iterator>     // std::distance
#include <functional>
#include <chrono>
#include <ctime>
#include <ratio>
#include <sys/resource.h>
#include <cstdlib> 
#include <algorithm> 
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

void Criaedesordem(int *vetor, float desordem, int tamanho){
	int i;
	int taxa = desordem*tamanho/2;
	int embaralhador[tamanho];

	for(int i = 0; i < tamanho;i++){
		vetor[i] = i;
		embaralhador[i] = i;
	}

	// for (int i = 0; i < tamanho; i++){
	// 	int r = rand() % tamanho;
	// 	int temp = vetor[i];
	// 	vetor[i] = vetor[r];
	// 	vetor[r] = temp;
	// }
	std::random_shuffle(&vetor[0], &vetor[tamanho]);

		print(&vetor[0], &vetor[tamanho]);

	// for(i=0;i<taxa;i++){
	// 	swap(&vetor[embaralhador[i]], &vetor[embaralhador[taxa - 1 -i]]);
	// }

	print(&vetor[0], &vetor[tamanho]);
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

void shell_sort(int *vetor, int size)
{
 int i , j , aux;
 int espaco = 1;
  
 do {
  espaco = 3*espaco+1;
 } while(espaco < size);
  
 while(espaco>=1){
  espaco /= 3;
  for(i = espaco; i < size; i++) {
   aux = vetor[i];
   j = i - espaco;
   while (j >= 0 && aux < vetor[j]) {
    vetor[j + espaco] = vetor[j];
    j -= espaco;
   }
   vetor[j + espaco] = aux;
  }
 }
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

void ChamQuickSort(int *vetor, int Tamanho){
	using namespace std::chrono;
	std::cout << "\nquicksort \n";
	//print(&vetor[0], &vetor[Tamanho]);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i=0;i<5;i++){
		quicksort(&vetor[0], &vetor[Tamanho]);
	}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

		//print(&vetor[0], &vetor[Tamanho]);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
}

void ChamMergeSort(int *vetor, int Tamanho){
	using namespace std::chrono;
	std::cout << "\nmergesort \n";
	//print(&vetor[0], &vetor[Tamanho]);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i=0;i<5;i++){

		mergesort(&vetor[0], &vetor[Tamanho-1]);
	}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

		//print(&vetor[0], &vetor[Tamanho]);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
}

void ChamSelectionSort(int *vetor, int Tamanho){
	using namespace std::chrono;
	std::cout << "\nselection_sort \n";
	//print(&vetor[0], &vetor[Tamanho]);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i=0;i<5;i++){
		selection_sort(vetor, Tamanho);
	}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

		//print(&vetor[0], &vetor[Tamanho]);
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
}

void ChamShellSort(int *vetor, int Tamanho){
	using namespace std::chrono;
	std::cout << "\nshell_sort \n";
		//print(&vetor[0], &vetor[Tamanho]);
	 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for(int i=0;i<5;i++){
			shell_sort(vetor, Tamanho);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		//print(&vetor[0], &vetor[Tamanho]);	
		std::cout << "[" << Tamanho << "]" << "-->" << "It took me " << time_span.count()/5 << " seconds. \n";
	
	
}

void vetores(int *vetor, int *vetor2, int *vetor3, int *vetor4, int tamanho, float Ordenacao);
void vetores(int *vetor, int *vetor2, int *vetor3, int *vetor4, int tamanho, float Ordenacao){
	int i;
	for(i=0;i<tamanho;i++){
		vetor[i]=i;
	}
	for(i=0;i<tamanho;i++){
		vetor2[i] = vetor3[i] = vetor4[i] = vetor[i];
	}

}

int main(){
	int TamanhoFinal, Tamanho = 1;
	float Ordenacao;
	float Ord[4] = {0, 0.25, 0.5, 1};
	using namespace std::chrono;
	std::cout << "Digite o tamanho do vetor \n";
	std::cin >> TamanhoFinal; 
	for(int i=0;i<4;i++){
		Ordenacao = Ord[i];
		std::cout << "\n\n\n fator ordenacao: " << Ordenacao << "\n\n\n";
		while(TamanhoFinal >= Tamanho){
			int vetor[Tamanho];
			int vetor2[Tamanho];
			int vetor3[Tamanho];
			int vetor4[Tamanho];
			vetores(vetor, vetor2, vetor3, vetor4, Tamanho, Ordenacao);	
			ChamMergeSort(vetor, Tamanho);
			ChamQuickSort(vetor2, Tamanho);
			ChamSelectionSort(vetor3, Tamanho);
			ChamShellSort(vetor4, Tamanho);
			Tamanho = Tamanho * 10;
		}
		Tamanho = 1;
	}
}







// class gnuplot {
// public: 
// 	gnuplot();
// 	-gnuplot();
// 	void operator () (const strig & command);
// protected:
// 	FILE *gnuplotpipe;
// };
// gnuplot::gnuplot(){
// 	gnuplotpipe = popen("gnuplot -persist", "w");
// 	if (!gnuplotpipe){
// 		cerr<<("Gnuplot not found!")
// 	}
// }
// gnuplot::-gnuplot(){
// 	fprintf(gnuplotpipe,"exit\n");
// 	pclose(gnuplotpipe);
// }
// void gnuplot::operator() (const string & command){
// 	fprintf(gnuplotpipe, "%s\n",command.c_str());
// 	fflush(gnuplotpipe);
// }
// #endif
