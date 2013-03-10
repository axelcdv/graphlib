#define MAXV	10

typedef enum
{
	UNDISCOVERED,
	DISCOVERED,
	PROCESSED
} State;

typedef struct edge_element
{
	int x;
	int y;
	edge_element* next;
} Edge;

typedef struct 
{
	int v;
	int num_edges;
	Edge *edges;
} Vertex;

typedef struct 
{
	Vertex vertices[MAXV +1];
	State states[MAXV + 1];
} Graph;