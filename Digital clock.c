#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

void fill_time(char*, int);
void fill_date(char*);
int input_format();
void clear_screen();

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

int main () {
char time[50] = " " , date [100] = " ";
int format = input_format();

while (1) {
   fill_time(time, format);
fill_date(date);
clear_screen();
printf(GREEN "=====================================\n"RESET);
printf(BLUE " 🌟 Current Time: %s 🌟\n" RESET, time); 
printf(GREEN "====================================\n");
 printf(CYAN "📅 Date: %s\n" RESET, date); 
printf(GREEN "====================================\n" RESET);
sleep(1); 
}
return 0;
}
void clear_screen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

int input_format() {
int format;
printf(YELLOW "\nChoose the time format: " RESET);
printf(GREEN "\n1. 24 Hour format " RESET);
printf(BLUE "\n2. 12 Hour format (default): " RESET);
printf(YELLOW "\nMake a choice(1/2): "RESET);
scanf("%d", &format);
return format;
}

void fill_date(char* buffer) {
time_t raw_time;
struct tm *current_time;

time(&raw_time);
current_time = localtime(&raw_time);
strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void fill_time(char* buffer, int format) {
 time_t raw_time;
 struct tm *current_time;
 
time(&raw_time);
current_time = localtime(&raw_time);
if (format == 1) {
 strftime(buffer, 50, "%H:%M:%S", current_time);
}
else {
strftime(buffer, 50, "%I:%M:%S %p", current_time);
}
} 