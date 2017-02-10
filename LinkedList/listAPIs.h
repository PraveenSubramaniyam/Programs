typedef struct listStruct list;

struct listStruct {
  int value;
  list *next;
};


void insert(list **head, int value);

int delete(list **head, int value);

void search(list *head, int value);


void print(list *head);
