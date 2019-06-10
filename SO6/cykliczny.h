#define N 5

struct cykliczny
{
    int size;
    int head;
    int tail;
    char data[N];
};

void push(struct cykliczny*, char);
void pull(struct cykliczny*);
