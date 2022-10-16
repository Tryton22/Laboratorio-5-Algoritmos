// Codigo asociado a algoritmo de Dijkstra para encontrar camino mas corto
// Implementacion de grafos y respresentacion en matriz de adyacencia

#include <limits.h>
#include <stdio.h>

// Numero de vertices del grafo (constante)
#define V 9

// funcion para encontrar arista de menor valor,
// desde el set de vertices aun no incluidos en el camino de arbol mas corto 
int DistanciaMinima(int dist[], bool marcador[])
{
	// Inicializa valor minimo
	int min = INT_MAX, indice_min;

	for (int v = 0; v < V; v++)
		if (marcador[v] == false && dist[v] <= min)
			min = dist[v], indice_min = v;

	return indice_min;
}

// imprime distancia menor desde vertice fuente
void ImprimirDistanciaMenor(int dist[], int n)
{
    const char* abc[V+1]={"a","b","c","d","e","f","g","h","i","\0"};
	printf("Distancia de vertice desde fuente\n");
	for (int i = 0; i < V; i++)
        if (dist[i]!=INT_MAX)
		    printf("%s->%d \t\t %d\n",abc[i] , i, dist[i]);
        else
            printf("%s->%d \t\t no hay conexion\n",abc[i] , i);
}

// Funcion asociada a algoritmo de dijkstra
void dijkstra(int grafo[V][V], int fuente)
{
    // valor dist[i] sera la menor distancia entre 
    // vertice fuente('0') y vertice 'i'
	int dist[V];

    //marcador[i] sera 'true' si vertice i es incluido en camino mas corto
	bool marcador[V];

	// Inicializa todas las distancias como infinitas
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, marcador[i] = false;

	// Distancia desde fuente siempre es cero
	dist[fuente] = 0;

	// encuentre camino mas corto desde todos los vertices
	for (int count = 0; count < V - 1; count++) {
        // escoge el minimo de distancia del vertice desde el set de vertices
        // aun no procesados. 'u' es siempre igual a fuente en primera iteracion
		int u = DistanciaMinima(dist, marcador);

		// marca el vertice escogido como procesado (true)
		marcador[u] = true;

        // actualiza valor de distancia de los vertices adjuntos al vertice actual
		for (int v = 0; v < V; v++)
            
            // actualiza dist[v] bajo las condiciones
            // vertice no esta en marcador
            // hay una arista de u a v
            // valor de camino desde fuente a v a traves de u es menor al
            // valor actual de dist[v]
			if (!marcador[v] && grafo[u][v] && dist[u] != INT_MAX
				&& dist[u] + grafo[u][v] < dist[v])
				dist[v] = dist[u] + grafo[u][v];
	}

	ImprimirDistanciaMenor(dist, V);
}

// funcion principal
int main()
{
	int grafo[V][V] = { { 0, 10, 0, 2, 1, 0, 0, 0, 0 },
						{ 0, 0, 3, 0, 0, 0, 0, 0, 0 },
						{ 0, 4, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 4, 0, 0, 6, 0, 0 },
						{ 0, 8, 0, 0, 0, 7, 0, 1, 0 },
						{ 0, 2, 8, 0, 0, 0, 0, 1, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 2, 0 },
						{ 0, 0, 0, 9, 0, 2, 5, 0, 0 },
						{ 0, 0, 0, 0, 0, 7, 0, 6, 0 } };

	dijkstra(grafo, 0);

	return 0;
}
