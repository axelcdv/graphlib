#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

void insert_edge (Edge *list, int x, int y)
{
	Edge *temp = list;
	Edge new_edge;
	new_edge.x = x;
	new_edge.y = y;
	new_edge.next = temp;
	list = &new_edge;
}

void create_random_graph (int max_edges)
{
	Graph g;
	unsigned int iseed = (unsigned int)time(NULL);
	srand(iseed);
	for (int i = 1; i < MAXV + 1; ++i)
	{
		g.vertices[i].num_edges = (int) (rand() - max_edges * (rand() / max_edges));
		for (int j = 0; j < g.vertices[j].num_edges; ++j)
		{
			
		}
	}
}

int main(int argc, char const *argv[])
{
	printf("Main\n");
	return 0;
}