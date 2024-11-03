#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#define BAR_LENGTH 20
#define MAX_TASKS 10

typedef struct {
     int id;
      int progress;
       int step;
        } Task;

void print_bar(Task task);
void clear_screen();
void initialize_tasks(Task tasks[]);
void update_tasks(Task tasks[], int *tasks_incomplete);

int main() {
Task tasks[MAX_TASKS];
srand(time(NULL));

initialize_tasks(tasks);
 int tasks_incomplete = 1; 
 while (tasks_incomplete) { 
    tasks_incomplete = 0; 
    clear_screen(); 
   update_tasks(tasks, &tasks_incomplete);


    sleep(1); 
    }

printf("All tasks complete!\n");
return 0;
}
void clear_screen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif 
}

void initialize_tasks(Task tasks[]) {
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;
    }
}


void update_tasks(Task tasks[], int *tasks_incomplete) {
     for (int i = 0; i < MAX_TASKS; i++) { 
        tasks[i].progress += tasks[i].step;
       if (tasks[i].progress > 100) {
         tasks[i].progress = 100;
      } else if (tasks[i].progress < 100) {
           *tasks_incomplete = 1; 

        }
        print_bar(tasks[i]);
    }
}

void print_bar(Task task) {
    int bars_to_show = (task.progress * BAR_LENGTH) / 100;
    printf("Task %d: [", task.id);
    for (int i = 0; i < BAR_LENGTH; i++) {
        if (i < bars_to_show) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", task.progress);
}
