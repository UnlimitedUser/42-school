#define MAXV 1000

typedef struct			s_edgenode
{
	int					index;
	int					weight;
	struct edgenode		*next;
}						t_edgenode;

typedef struct			s_graph
{
	t_edgenode			*edges[MAXV];
	int					degree[MAXV];
	int					nvertices;
	int					nedges;
	unsigned int		directed : 1;
}						t_graph;