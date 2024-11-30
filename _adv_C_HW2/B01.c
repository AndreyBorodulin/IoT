//B0
/*
Описана структура данных:

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

Требуется реализовать только одну функцию, которая в данном списке находит
адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока.
Если список пустой, то функция должна возвращать NULL.
Если есть несколько таких блоков, то вернуть адрес любого из них.
Прототип функции: uint64_t findMaxBlock(list *head)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;


// в тест грузим данную функцию
// begin

size_t totalMemoryUsage(list *head)
{
     if (head == NULL)
    {
        return 0;
    }

    size_t sum = 0;
    while(head != NULL)
    {
        sum += head -> size;
        head = head -> next;
    }

    return sum;
}
// end

void ShowList(list *head)
{
    while(head)
    {
        printf("address = % " PRIu64 " size = %d\n", head->address, (unsigned)head->size);
        head = head -> next;
    }
    puts("\n");
}


void insert(list **a, uint64_t address, size_t size)
{
    list *temp;
    temp = malloc(sizeof(list));
    temp -> next = *a;
    temp-> address = address;
    temp -> size = size;
    *a=temp;
}


uint64_t findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return 0;
    }
    uint64_t address = head->address;
    size_t size = head->size;
    uint64_t max = address;

    while(head != NULL)
    {
        if(head->size > size)
        {
            size = head->size;
            max = head->address;
        }
        head = head->next;
    }
    return max;
}


int main(void) {

    list *head = NULL;

    insert(&head, 140525067852320, 10);
    insert(&head, 140525067852350, 30);
    insert(&head, 140525067852900, 100);

    ShowList(head);

    //printf("% "PRIu64" ", findMaxBlock(head));
    printf("%u", (unsigned)totalMemoryUsage(head));

    return 0;
}

















