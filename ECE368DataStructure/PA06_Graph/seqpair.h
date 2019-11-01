#define BLACK 2
#define GRAY 1
#define WHITE 0

typedef struct _GRAPH{
    int S1; //index in sequence 1
    int S2; //index in sequency 2
    double width;
    double height;
    double newwid;
    double newhei;
    int colorh;
    int colorv;
    struct listnode *hcg;
    struct listnode *vcg;
}Graph;

typedef struct listnode{
    struct listnode *next;
    int index;
}ListNode;

//graph construct
void generatelist(Graph * arr, int size);
ListNode * generatenode(int num);

void DFS(Graph * arr, int * sorth, int * sortv, int number);
void dfsh(Graph * arr, int index, int * sort, int * size);
void dfsv(Graph * arr, int index, int * sort, int * size);
//void tolosort(Graph * arr, int size);
void tolosort(Graph * arr, int size, int * sorth, int * sortv);
void printoutput(Graph * arr, int number, FILE * output);

//free memory
void destroy(Graph * arr, int number);
void destroylist(ListNode * list);

//helper function
void _write(int number, Graph* arr, FILE *output);
void _printarr(int * sort, int size);
void _printlist(Graph * arr, int size);