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

struct control_buttons                                                                              // Структура управления для различных типов ввода
{
    int down;
    int up;
    int left;
    int right;
};

struct control_buttons default_controls[CONTROLS] =                                                 // Массив для управления стрелками и клавишами
{
    { KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT },                                                      // Управление стрелками для второй змейки
    { 'f', 'r', 'd', 'g' }                                                                          // Управление второй  змейкой
};

typedef struct tail_t                                                                               // Структура для хвоста змейки
{
    int x;                                                                                          // Координата X хвоста
    int y;                                                                                          // Координата Y хвоста
} tail_t;

typedef struct snake_t                                                                              // Структура для змейки
{
    int x;                                                                                          // Координата X головы змейки
    int y;                                                                                          // Координата Y головы змейки
    int direction;                                                                                  // Текущее направление движения змейки
    size_t tsize;                                                                                   // Текущий размер хвоста
    struct tail_t* tail;                                                                            // Массив, содержащий сегменты хвоста
    int gamer;                                                                                     // Номер игрока (1 или 2)
    int food_eaten;                                                                                 // Количество съеденной еды (счетчик)
} snake_t;

typedef struct food_t                                                                               // Структура для еды
{
    int x;                                                                                          // Координата X еды
    int y;                                                                                          // Координата Y еды
    int active;                                                                                     // Флаг активности (1 - активное, 0 - съедено)
    time_t spawn_time;                                                                              // Время появления еды
} food_t;


void setColor(int snakeNum)                                                                      // Функция для отображения змейки по цвету
{
    if (snakeNum == 1)
    {
        attron(COLOR_PAIR(1));                                                                      // Змейка 1 (красная)
    }
    else if (snakeNum == 2)
    {
        attron(COLOR_PAIR(2));                                                                      // Змейка 2 (желтая)
    }
}

void initTail(struct tail_t t[], size_t size)                                                       // Инициализация хвоста змейки
{
    struct tail_t init_t = { 0, 0 };
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}

void initHead(struct snake_t* head, int x, int y, int gamer)                                       // Инициализация головной части
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
    head->gamer = gamer;
    head->food_eaten = 0;
}

void initSnake(snake_t* head, size_t size, int x, int y, int gamer)                                // Инициализация всей змеи
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

void go(snake_t* head)                                                                              // Голова змеи и ее движение
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
    setColor(head->gamer);                                                                         // Устанавливаю цвет змейки в зависимости от игрока
    mvprintw(head->y, head->x, "%c", ch);                                                           // Отображаем голову в иной позиции
    refresh();                                                                                      // Обновление экрана
}

void goTail(snake_t* snake)                                                                         // Ф-ия отображения хвоста
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

int isCrush(snake_t* snake, snake_t* snake2)                                                    // ? столкновение змейки с хвостом или другой змейкой (проверка)
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

int isCollideWithSnake(snake_t* snake, int x, int y)                                                // Проверяю коллизии с змейкой, с едой например
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

void changeDirection(snake_t* snake, int ch)                                                        // Изменяем направление движения змейки
{
    if (ch == default_controls[snake->gamer - 1].up && snake->direction != DOWN) snake->direction = UP;
    else if (ch == default_controls[snake->gamer - 1].down && snake->direction != UP) snake->direction = DOWN;
    else if (ch == default_controls[snake->gamer - 1].left && snake->direction != RIGHT) snake->direction = LEFT;
    else if (ch == default_controls[snake->gamer - 1].right && snake->direction != LEFT) snake->direction = RIGHT;
}

void putFood(food_t food[], int count, snake_t* snake1, snake_t* snake2)                            // Подкидываем еды
{
    for (int i = 0; i < count; i++)
    {
        while (isCollideWithSnake(snake1, food[i].x, food[i].y) || isCollideWithSnake(snake2, food[i].x, food[i].y))                                                                                         // Пытаюсь разместить еду в случайных местах
        {
            food[i].x = rand() % COLS;
            food[i].y = rand() % LINES;
        }
        food[i].active = 1;                                                                         // Статус еды
        food[i].spawn_time = time(NULL);                                                            // Время появления еды
        attron(COLOR_PAIR(2));                                                                      // Цвет еды
        mvprintw(food[i].y, food[i].x, "&");
        attroff(COLOR_PAIR(2));                                                                     // Сбрасываю цвет
        refresh();                                                                                  // Обновляю экран
    }
}

int haveEat(snake_t* snake, food_t food[])                                                          // Проверяю на поедание еды
{
    for (int i = 0; i < MAX_FOOD_SIZE; i++)
    {
        if (snake->x == food[i].x && snake->y == food[i].y)                                         // Проверяю, совпадают ли координаты еды и змеи
        {
            food[i].active = 0;                                                                     // Если еда съедена, помечаю её как неактивную

            return 1;                                                                               // Возвращаю 1, если еда съедена
        }
    }

    return 0;                                                                                       // Если еда не съедена, то 0
}

void refreshFood(food_t food[], int count, snake_t* snake1, snake_t* snake2)                        // Оффициант, повторите!
{
    time_t current_time = time(NULL);                                                               // Текущее время

    for (int i = 0; i < count; i++)
        {
        if (!food[i].active || (current_time - food[i].spawn_time > FOOD_EXPIRE_SECONDS))           // Если еда устарела или была съедена, делаем новую
        {
            do
            {
                food[i].x = rand() % COLS;
                food[i].y = rand() % LINES;
            }
            while (isCollideWithSnake(snake1, food[i].x, food[i].y) \
                   || isCollideWithSnake(snake2, food[i].x, food[i].y));
            food[i].active = 1;                                                                     // Помечаем еду как активную
            food[i].spawn_time = current_time;                                                      // Обновляю время появления еды
            attron(COLOR_PAIR(3));                                                                  // Цвет еды
            mvprintw(food[i].y, food[i].x, "$");
            attroff(COLOR_PAIR(3));
            refresh();
        }
    }
}

void StartMenu()                                                                                      // Стартовое меню
{
    clear();
    box(stdscr, 30, 30);                                                                              // Рисую рамку
    mvprintw(5, 10, "GO SNAKE!");
    mvprintw(7, 10, "ENTER FOR START");
    refresh();
    timeout(-25);                                                                                    // Блокирую getch(), пока не будет нажат символ
    while (getch() != '\n') {}                                                                       // Ожидаю нажатие Enter
    timeout(100);                                                                                   // Возвращаю timeout после меню, чтобы дальше ожидать ввод с небольшой задержкой
    clear();                                                                                        // Очищаю экран после старта игры
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
    initscr();                                                                                      // Инициализируем ncurses
    timeout(200);                                                                                   // Задаем время задержки в 100 мс
    noecho();                                                                                       // Отключаем эхо ввода
    cbreak();                                                                                       // Отключаем буферизацию
    keypad(stdscr, TRUE);                                                                           // Включаю поддержку специальных клавиш, включая стрелки
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    srand(time(NULL));
    snake_t snake1, snake2;
    initSnake(&snake1, START_TAIL_SIZE, 20, 10, 1);
    initSnake(&snake2, START_TAIL_SIZE, 40, 10, 2);
    food_t food[FOOD_COUNT];                                                                        // Инициализируем еду
    putFood(food, FOOD_COUNT, &snake1, &snake2);
    StartMenu();                                                                                    // Стартовое меню

    while (1)
    {
        SnakeScores(&snake1, &snake2);                                                              // Отображаем счёт
        go(&snake1);
        goTail(&snake1);
        go(&snake2);
        goTail(&snake2);

        if (haveEat(&snake1, food))                                                                 // Проверка на съедение еды
        {
            snake1.food_eaten++;
            addTail(&snake1);
            putFood(food, FOOD_COUNT, &snake1, &snake2);                                            // Подкидываем пищи
        }
        if (haveEat(&snake2, food))
        {
            snake2.food_eaten++;
            addTail(&snake2);
            putFood(food, FOOD_COUNT, &snake1, &snake2);
        }
        refreshFood(food, FOOD_COUNT, &snake1, &snake2);

        // Ввод управляющих клавиш
        int ch = getch();                                                                           // Ввод управляющих клавиш
        if (ch == STOP_GAME)
        {
            puts("GO OUT");
            break;
        }
                                                                                            // Завершаю игру, если нажата 'e'
        changeDirection(&snake1, ch);

        changeDirection(&snake2, ch);

        if (isCrush(&snake1, &snake2))
            break;                                                                                  // Завершение, если змейки столкнулись
    }
    endwin();
    return 0;
}
