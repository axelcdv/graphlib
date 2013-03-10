#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void process_vertex_early (Graph g, int v)
{
	printf("Processing vertex %d early\n", v);
	return;
}

void process_vertex_late (Graph g, int v)
{
	printf("Processing vertex %d late\n", v);
	return;
}

void process_edge (Graph g, Edge *e)
{
	printf("Edge %d - %d\n", e->x, e->y);
	return;
}

void bfs (Graph g, int v)
{
	static int finished = 0;
	Edge *edge;

	if (finished == 1)
	{
		return;
	}

	if (g.states[v] == UNDISCOVERED)
	{
		g.states[v] = DISCOVERED;
		process_vertex_early(g, v);
		edge = g.vertices[v].edges;
		for (int i = 0; i < g.vertices[v].num_edges; ++i)
		{
			process_edge(g, edge);
			if (g.states[edge->y] != PROCESSED)
			{
				bfs(g, edge->y);
			}	
			edge = edge->next;
		}
	}
}

int rest (int a, int b)
{
	return (int) (a - b * (int) (a / b));
}

void insert_edge (Edge** list, int x, int y)
{
	Edge *new_edge;
	new_edge = (Edge *) malloc(sizeof(Edge));
	
	new_edge->x = x;
	new_edge->y = y;	

	new_edge->next = *list;
	*list = new_edge;
}

/**
 * Determines if an edge between node x and node y already exists
 * @param  list the list of edges of node x
 * @param  y    the target node
 * @return      true if an edge exists, false otherwise
 */
bool already_linked (Edge *list, int y)
{
	if (list == NULL)
	{
		return false;
	}
	else if (list->y == y)
	{
		return true;
	}
	else
	{
		return already_linked (list->next, y);
	}
}

/**
 * Prints all the out edges from a vertex
 * @param g    the graph
 * @param list the list of outgoing edges
 */
void print_edges (Graph g, Edge* list)
{
	if (list == NULL)
	{
		return;
	}

	printf("\t %d -> %d", list->x, list->y);
	print_edges(g, list->next);
}

/**
 * Maximum of two integers
 * @param  a first integer
 * @param  b second integer
 * @return   max of a and b
 */
int max (int a, int b)
{
	return (a < b) ? b : a;
}

/**
 * Creates a random undirected graph by linking vertices at random, with a given maximum
 * number of edges per node. Avoids i->i edges.
 * @param max_edges the maximum number of edges per node
 */
Graph create_random_graph (int max_edges)
{
	Graph g;
	unsigned int iseed = (unsigned int)time(NULL);
	srand(iseed);
	int num_edges;
	int y;
	
	for (int k = 1; k < MAXV + 1; ++k)
	{
		Vertex v;
		v.v = k;
		v.num_edges = 0;
		
		v.edges = NULL;
		g.vertices[k] = v;
	}

	for (int i = 1; i < MAXV + 1; ++i)
	{
		printf("\nNode %d:\t", i);
		num_edges = max(1, rest(rand(), max_edges));
		while (g.vertices[i].num_edges < num_edges)
		{
			do
			{
				y = 1 + rest(rand(), MAXV);
			}
			while (already_linked(g.vertices[i].edges, y) || y == i);
			
			insert_edge(&g.vertices[i].edges, i, y);
			g.vertices[i].num_edges++;
			
			insert_edge(&g.vertices[y].edges, y, i);
			g.vertices[y].num_edges++;
		}
		printf("num edges: %d\t", g.vertices[i].num_edges);
		print_edges(g, g.vertices[i].edges);	
	}

	return g;
}

int main(int argc, char const *argv[])
{
	Graph g = create_random_graph(5);
	return 0;
}