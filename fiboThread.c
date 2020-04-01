//Feito Por: Juan Victor Dutra Juan 
//TIA: 31711081

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int quantidade, soma;
int fibonacci = 10;
void *runner(void *parametro)
{
	int param = (int)parametro;
	soma = fib((int)param);
}

int fib(int n)
{
    if (n == 0){
        return 0;
    }
    else if ((n == 1) || (n == 2)){
        return 1;
    }
    else{
		return (fib(n-1) + fib(n-2));
    }
}

int main(){
	pthread_attr_t attr; 
	int i;
	int entrada;
	int entr = (int)entrada;
	pthread_attr_init(&attr);
	printf("Entre com um numero: ");
	entrada = getchar();
	entr = getchar();
	printf("\nVoce escolheu o numero: ");
	putchar(entrada);
	for(i;i<=entrada;i++){
	pthread_t thread;
	pthread_create(&thread,&attr,runner,(void*)i);
	pthread_join(thread,NULL);	
	printf("\nfib de %d eh: %d\n", i, soma);
	if (i>entr){
		break;
	}	
	}
}
