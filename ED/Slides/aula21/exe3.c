#include <stdio.h>
#include <stdlib.h>


struct Nodo {

	int info;
	struct Nodo *ant;
	struct Nodo *prox;

}no;


void main () {

	struct Nodo *inicio = NULL, *tmp, *p;
	int v,i;

	for ( v = 1; v < 6; i++)
    {
  
		tmp = (struct Nodo* ) malloc ( sizeof( struct Nodo ) );
		tmp -> info = v; 
		tmp -> prox = NULL;

		if (inicio == NULL) { // lista vazia

			inicio = tmp;
			tmp->ant = tmp->prox = NULL;

		}
		else {

			//  percorrer a lista			
			p = inicio;
			
			while ( p->prox != NULL && p->info != v) {

				p = p->prox;

			}

			if ( p->info != v ){
	
				p->prox = tmp;
				tmp->ant = p;

			}
		}

	}

	

    while (i > v)
    {
        printf( "%d\t", p->info);
		p = p->prox;

        i--;
    }
    
    
	// mostrando a lista
	// p = inicio;
	// while ( p != NULL ) {

	// 	printf( "%d\t", p->info);
	// 	p = p->prox;

	// }
	printf( "\n");

}