#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y 2
#define CONTROLS 2
#define FOOD_COUNT 5
enum { LEFT = 1, UP, RIGHT, DOWN, STOP_GAME = 'e' };
enum { MAX_TAIL_SIZE = 100, START_TAIL_SIZE = 3, MAX_FOOD_SIZE = 20, FOOD_EXPIRE_SECONDS = 10 };

struct control_buttons                                                                              // ��������� ���������� ��� ��������� ����� �����
{
    int down;
    int up;
    int left;
    int right;
};

struct control_buttons default_controls[CONTROLS] =                                                 // ������ ��� ���������� ��������� � ���������
{
    { KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT },                                                      // ���������� ��������� ��� ������ ������
    { 'f', 'r', 'd', 'g' }                                                                          // ���������� ������  �������
};

typedef struct tail_t                                                                               // ��������� ��� ������ ������
{
    int x;                                                                                          // ���������� X ������
    int y;                                                                                          // ���������� Y ������
} tail_t;

typedef struct snake_t                                                                              // ��������� ��� ������
{
    int x;                                                                                          // ���������� X ������ ������
    int y;                                                                                          // ���������� Y ������ ������
    int direction;                                                                                  // ������� ����������� �������� ������
    size_t tsize;                                                                                   // ������� ������ ������
    struct tail_t* tail;                                                                            // ������, ���������� �������� ������
    int gamer;                                                                                     // ����� ������ (1 ��� 2)
    int food_eaten;                                                                                 // ���������� ��������� ��� (�������)
} snake_t;

typedef struct food_t                                                                               // ��������� ��� ���
{
    int x;                                                                                          // ���������� X ���
    int y;                                                                                          // ���������� Y ���
    int active;                                                                                     // ���� ���������� (1 - ��������, 0 - �������)
    time_t spawn_time;                                                                              // ����� ��������� ���
} food_t;


void setColor(int snakeNum)                                                                      // ������� ��� ����������� ������ �� �����
{
    if (snakeNum == 1)
    {
        attron(COLOR_PAIR(1));                                                                      // ������ 1 (�������)
    }
    else if (snakeNum == 2)
    {
        attron(COLOR_PAIR(2));                                                                      // ������ 2 (������)
    }
}

void initTail(struct tail_t t[], size_t size)                                                       // ������������� ������ ������
{
    struct tail_t init_t = { 0, 0 };
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}

void initHead(struct snake_t* head, int x, int y, int gamer)                                       // ������������� �������� �����
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
    head->gamer = gamer;
    head->food_eaten = 0;
}

void initSnake(snake_t* head, size_t size, int x, int y, int gamer)                                // ������������� ���� ����
{
    tail_t* tail = (tail_t*)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    if (tail == NULL)
    {
        perror("NOT possible to allocate memory for snake tail");
        exit(1);
    }
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y, gamer);
    head->tail = tail;
    head->tsize = size + 1;
}

void go(snake_t* head)                                                                              // ������ ���� � �� ��������
{
    char ch = 'Z';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    head->x = (head->x < 0) ? 0 : (head->x >= max_x) ? max_x - 1 : head->x;
    head->y = (head->y < 0) ? 0 : (head->y >= max_y) ? max_y - 1 : head->y;
    mvprintw(head->y, head->x, " ");
    switch (head->direction)
    {
    case LEFT:
        head->x = (head->x <= 0) ? max_x - 1 : head->x - 1;
        break;
    case RIGHT:
        head->x = (head->x >= max_x - 1) ? 0 : head->x + 1;
        break;
    case UP:
        head->y = (head->y <= 0) ? max_y - 1 : head->y - 1;
        break;
    case DOWN:
        head->y = (head->y >= max_y - 1) ? 0 : head->y + 1;
        break;
    }
    setColor(head->gamer);                                                                         // ������������ ���� ������ � ����������� �� ������
    mvprintw(head->y, head->x, "%c", ch);                                                           // ���������� ������ � ���� �������
    refresh();                                                                                      // ���������� ������
}

void goTail(snake_t* snake)                                                                         // �-�� ����������� ������
{
    mvprintw(snake->tail[snake->tsize - 1].y, snake->tail[snake->tsize - 1].x, " ");
    for (size_t i = snake->tsize - 1; i > 0; i--)
    {
        snake->tail[i] = snake->tail[i - 1];
        mvprintw(snake->tail[i].y, snake->tail[i].x, "x");
        mvaddch(snake->tail[i].y, snake->tail[i].x, ACS_DIAMOND);
    }

    snake->tail[0].x = snake->x;
    snake->tail[0].y = snake->y;
}

int isCrush(snake_t* snake, snake_t* snake2)                                                    // ? ������������ ������ � ������� ��� ������ ������� (��������)
{
    for (size_t i = 1; i < snake->tsize; i++)
    {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
        {
            printf("FATAL_CRASH, SORRY BRO!!!");
            exit (1);
        }
    }
    if (snake->x == snake2->x && snake->y == snake2->y)
    {
        printf("FATAL_CRASH, SORRY BRO!!!");
        exit (1);
    }

    return 0;
}

int isCollideWithSnake(snake_t* snake, int x, int y)                                                // �������� �������� � �������, � ���� ��������
{
    if (snake->x == x && snake->y == y)
        return 1;
    for (size_t i = 0; i < snake->tsize; i++)
    {
        if (snake->tail[i].x == x && snake->tail[i].y == y)
        return 1;
    }
    return 0;
}

void changeDirection(snake_t* snake, int ch)                                                        // �������� ����������� �������� ������
{
    if (ch == default_controls[snake->gamer - 1].up && snake->direction != DOWN) snake->direction = UP;
    else if (ch == default_controls[snake->gamer - 1].down && snake->direction != UP) snake->direction = DOWN;
    else if (ch == default_controls[snake->gamer - 1].left && snake->direction != RIGHT) snake->direction = LEFT;
    else if (ch == default_controls[snake->gamer - 1].right && snake->direction != LEFT) snake->direction = RIGHT;
}

void putFood(food_t food[], int count, snake_t* snake1, snake_t* snake2)                            // ����������� ���
{
    for (int i = 0; i < count; i++)
    {
        while (isCollideWithSnake(snake1, food[i].x, food[i].y) || isCollideWithSnake(snake2, food[i].x, food[i].y))                                                                                         // ������� ���������� ��� � ��������� ������
        {
            food[i].x = rand() % COLS;
            food[i].y = rand() % LINES;
        }
        food[i].active = 1;                                                                         // ������ ���
        food[i].spawn_time = time(NULL);                                                            // ����� ��������� ���
        attron(COLOR_PAIR(2));                                                                      // ���� ���
        mvprintw(food[i].y, food[i].x, "&");
        attroff(COLOR_PAIR(2));                                                                     // ��������� ����
        refresh();                                                                                  // �������� �����
    }
}

int haveEat(snake_t* snake, food_t food[])                                                          // �������� �� �������� ���
{
    for (int i = 0; i < MAX_FOOD_SIZE; i++)
    {
        if (snake->x == food[i].x && snake->y == food[i].y)                                         // ��������, ��������� �� ���������� ��� � ����
        {
            food[i].active = 0;                                                                     // ���� ��� �������, ������� � ��� ����������

            return 1;                                                                               // ��������� 1, ���� ��� �������
        }
    }

    return 0;                                                                                       // ���� ��� �� �������, �� 0
}

void refreshFood(food_t food[], int count, snake_t* snake1, snake_t* snake2)                        // ���������, ���������!
{
    time_t current_time = time(NULL);                                                               // ������� �����

    for (int i = 0; i < count; i++)
        {
        if (!food[i].active || (current_time - food[i].spawn_time > FOOD_EXPIRE_SECONDS))           // ���� ��� �������� ��� ���� �������, ������ �����
        {
            do
            {
                food[i].x = rand() % COLS;
                food[i].y = rand() % LINES;
            }
            while (isCollideWithSnake(snake1, food[i].x, food[i].y) \
                   || isCollideWithSnake(snake2, food[i].x, food[i].y));
            food[i].active = 1;                                                                     // �������� ��� ��� ��������
            food[i].spawn_time = current_time;                                                      // �������� ����� ��������� ���
            attron(COLOR_PAIR(3));                                                                  // ���� ���
            mvprintw(food[i].y, food[i].x, "$");
            attroff(COLOR_PAIR(3));
            refresh();
        }
    }
}

void StartMenu()                                                                                      // ��������� ����
{
    clear();
    box(stdscr, 30, 30);                                                                              // ����� �����
    mvprintw(5, 10, "GO SNAKE!");
    mvprintw(7, 10, "ENTER FOR START");
    refresh();
    timeout(-25);                                                                                    // �������� getch(), ���� �� ����� ����� ������
    while (getch() != '\n') {}                                                                       // ������ ������� Enter
    timeout(100);                                                                                   // ��������� timeout ����� ����, ����� ������ ������� ���� � ��������� ���������
    clear();                                                                                        // ������ ����� ����� ������ ����
}

void SnakeScores(snake_t* snake1, snake_t* snake2)
{
    mvprintw(0, 0, "[Gamer 1 Score - %d]", snake1->food_eaten );
    mvprintw(LINES - 1, COLS - 20, "[Gamer 2 Score - %d]", snake2->food_eaten);
}

void addTail(snake_t *head)
{
    head -> tsize++;
}

int main(void)
{
    initscr();                                                                                      // �������������� ncurses
    timeout(200);                                                                                   // ������ ����� �������� � 100 ��
    noecho();                                                                                       // ��������� ��� �����
    cbreak();                                                                                       // ��������� �����������
    keypad(stdscr, TRUE);                                                                           // ������� ��������� ����������� ������, ������� �������
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    srand(time(NULL));
    snake_t snake1, snake2;
    initSnake(&snake1, START_TAIL_SIZE, 20, 10, 1);
    initSnake(&snake2, START_TAIL_SIZE, 40, 10, 2);
    food_t food[FOOD_COUNT];                                                                        // �������������� ���
    putFood(food, FOOD_COUNT, &snake1, &snake2);
    StartMenu();                                                                                    // ��������� ����

    while (1)
    {
        SnakeScores(&snake1, &snake2);                                                              // ���������� ����
        go(&snake1);
        goTail(&snake1);
        go(&snake2);
        goTail(&snake2);

        if (haveEat(&snake1, food))                                                                 // �������� �� �������� ���
        {
            snake1.food_eaten++;
            addTail(&snake1);
            putFood(food, FOOD_COUNT, &snake1, &snake2);                                            // ����������� ����
        }
        if (haveEat(&snake2, food))
        {
            snake2.food_eaten++;
            addTail(&snake2);
            putFood(food, FOOD_COUNT, &snake1, &snake2);
        }
        refreshFood(food, FOOD_COUNT, &snake1, &snake2);

        // ���� ����������� ������
        int ch = getch();                                                                           // ���� ����������� ������
        if (ch == STOP_GAME)
        {
            puts("GO OUT");
            break;
        }
                                                                                            // �������� ����, ���� ������ 'e'
        changeDirection(&snake1, ch);

        changeDirection(&snake2, ch);

        if (isCrush(&snake1, &snake2))
            break;                                                                                  // ����������, ���� ������ �����������
    }
    endwin();
    return 0;
}
