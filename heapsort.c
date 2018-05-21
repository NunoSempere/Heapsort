#include <stdlib.h>
#include <stdio.h>

void *create_heap(int* L1, int len);
void add_element_to_heap(int *L, int n, int len);
int extract_element_from_heap(int *L, int longitud);

int main(){
	
	int len=10;
	int L1[10];

	int i=0;
	while(i<len){ 
		L1[i]=10-i;
		i++;
	}

	//int L1[10]={10,9,3,4,5,8,1,6,2,7};
	create_heap(L1, len);

	i=0;
	while(i<len){ 
		fprintf(stdout, "L[%d]=%d\n", i, L1[i]);
		i++;
	}
	
}

void *create_heap(int* L1, int len){
	
	int *L2 = malloc(len*sizeof(int));

	int i,j;
	int *last_added;

	i=0;
	while(i<len){ // Esto se podría solucionar con una variable last_added.
		L2[i]=-1;
		i++;
	}
	

	i=0;

	while(i<len){
		add_element_to_heap(L2,L1[i], len);
		//fprintf(stdout, "\nL[%d]=%d", i, L2[i]);
		i++;
	}
	
	j=0;
	//fprintf(stdout, "\nL2:");
	/*while(j<=len-1){ 
		fprintf(stdout, "\nL[%d]=%d", j, L2[j]);
		j++;
	}*/		
	

	i=0;
	while(i<len){

		
		/*fprintf(stdout, "\nAntes de la %d-ésima extracción", i);
		j=0;
		while(j<=len-1){ 
			fprintf(stdout, "\nL[%d]=%d", j, L2[j]);
			j++;
		}	
		*/	
		L1[i] = extract_element_from_heap(L2,len);
		
		i++;


	}
	
};


void add_element_to_heap(int *L, int n, int len){

	int pos, i, j, fin,temp;
	i =0;
	while(L[i]!=-1 && i<len){
		i++;
	}
	L[i]=n;

	
	fin =0;
	while(fin==0){

		j = ((i+1 -(i+1)%2)/2) -1; 	

		// ¿Por qué los +-1?
		// Porque para utilizar el truco de que los desciendientes de n son 2n y 2n+1, tenemos que empezar a contar en el 1. Pero la máquina empieza a contar en el 0.
		
		//i = i+1;		

		if(L[i]<L[j]){
			temp = L[j];
			L[j]=L[i];
			L[i]=temp;
			i=j;
		}
		else{
			fin =1;		
		}
	}
}

int extract_element_from_heap(int *L, int longitud){

	int i, j, fin,temp, len, resultado;

	resultado = L[0]; // Lo complicado no es extraer el elemento, es modificar el montículo para que siga siendo un montículo.

	i =0;
	while(i<longitud && L[i]!=-1){
		i++;
	}

	temp = L[i-1];
	L[i-1] = -1;
	len=i-1;


	
	fin =0;	
	i=0;

	while(fin==0){ // Esto podría dar un bucle infinito, pero no debería.
		// Los descendientes de i son 
		// 2(i+1) -1 = 2i+1 y 2(i+1) +1 -1 = 2i +2, si empezamos a contar en el 0.

		if(2*i +2>len-1){
			L[i]=temp;
			fin =1;
		}		

		else{

			if( temp<= L[2*i+1] && temp<= L[2*i+2] ){
				// Pongo <=, pero también puede ser <
				L[i]=temp;
				fin =1;

			}

			else{
				//fprintf(stdout, "\nAleluya\n");	

				if(L[2*i+1]<L[2*i+2]){
					L[i] = L[2*i +1];
					i = 2*i +1;
				}

				else{
					L[i] = L[2*i +2];
					i = 2*i +2;
				}

			}			
		}		
	}
	
	return resultado;
}
