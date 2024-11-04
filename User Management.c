#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<conio.h>
#include <stdbool.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30
#define MIN_PASSWORD_LENGTH 8

typedef struct {
char username[CREDENTIAL_LENGTH];
char password[CREDENTIAL_LENGTH];

} User;


User users[MAX_USERS];
int user_count = 0;


void register_user();
int login_user();
void delete_user_by_index(int user_index);
void delete_user_by_name();
void change_password(int user_index);
void fix_fgets_input(char*);
void input_credentials(char* username, char* password);
int check_password_complexity(char* password);
void display_users();


int main() {
int option;
int user_index = -1;
bool logged_in = false;


while (1) {

if (!logged_in) {
printf ("\nWelcome to User Management");
printf("\n1. Register");
printf("\n2. Login");
printf("\n3. Display Users");
printf("\n4. Exit");
printf("\n===============================================");
printf("\nSelect an option");
scanf("%d" , &option);
getchar();


switch (option) {
case 1: 
register_user();
break;

case 2:
user_index = login_user();
if (user_index >= 0) {
printf("\nLogin successfull! Welcome, %s!\n",
              users[user_index].username);
              logged_in = true;
} else {

printf("\nLogin failed! Incorrect username or password.\n");
}
break;

case 3:
 display_users(); 
break;

case 4:
printf("\nExisting Program.\n");
return 0;

default :
printf("\nInvalid option. Please try again.\n");
break;
}
}else { printf("\n========== User Dashboard ==========");
 printf("\n1. Change Password");
 printf("\n2. Delete Account");
 printf("\n3. Logout");
 printf("\n===================================="); 
printf("\nSelect an option: ");
 scanf("%d", &option);
getchar();
switch (option) { 
case 1:
 change_password(user_index);
 break;
 case 2:
delete_user_by_index(user_index);
logged_in = false; 
user_index = -1; 
break;
 case 3: logged_in = false;

 user_index = -1;
 printf("\nLogged out successfully.\n"); 
break; 
default:
 printf("\nInvalid option. Please try again.\n"); 
break; 
}
 }

}
return 0;
}

void register_user() {
 if (user_count == MAX_USERS) {
printf("\nMaximum %d users are supported! No more registration allowed!\n", MAX_USERS);
return;
}

int new_index = user_count;
printf("\nRegister a new user");
input_credentials(users[new_index].username, users[new_index].password);

if (check_password_complexity(users[new_index].password)) {
 user_count++;
 printf("\nRegistration successful!\n");
 } else { 
printf("\nRegistration failed! Password must be at least %d characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n", MIN_PASSWORD_LENGTH);
 }
 }


int login_user() {
char username[CREDENTIAL_LENGTH];
char password[CREDENTIAL_LENGTH];

input_credentials(username, password);

for (int i = 0; i < user_count; i++) {
 if (strcmp(username, users[i].username) == 0 &&
 strcmp(password, users[i].password) == 0) { 
return i;
 }
} 
return -1;
}



void delete_user_by_index(int user_index) {
 if (user_index < 0 || user_index >= user_count) {
 printf("\nInvalid user index!\n");
 return;
 }
 for (int i = user_index; i < user_count - 1; i++) { 
users[i] = users[i + 1];
 } 
user_count--; 
printf("\nAccount deleted successfully.\n"); 
}

void change_password(int user_index) {
 char new_password[CREDENTIAL_LENGTH];
 printf("\nEnter new password (masking enabled): ");
 fflush(stdout); 
char ch; 
int i = 0;
 while ((ch = _getch()) != '\r') { 
 if (ch == '\b' && i > 0) {
i--; 
printf("\b \b");

} else if (ch != '\b') {
 new_password[i++] = ch; 
printf("*");
 }
 }
new_password[i] = '\0'; 
printf("\n");
 if (check_password_complexity(new_password)) { 
strcpy(users[user_index].password, new_password);
 printf("\nPassword changed successfully!\n");
 } else {
 printf("\nPassword change failed! Password must be at least %d characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n", MIN_PASSWORD_LENGTH);
 }
 }


void input_credentials(char* username, char* password) {
printf("\nEntre  username: ");
fgets(username, CREDENTIAL_LENGTH, stdin);
fix_fgets_input(username);

printf("Entre password (masking enabled): ");
fflush(stdout);


char ch;
int i = 0;
 while ((ch = _getch()) != '\r') {
   if (ch == '\b' && i > 0) {
    i--; 
     printf("\b \b");
      } else if (ch != '\b') {
       password[i++] = ch; 
        printf("*"); 
         }
           }
       password[i] = '\0';
        printf("\n");
 }

void fix_fgets_input(char* string) {
 int index = strcspn(string, "\n");
 string[index] = '\0';
}

int check_password_complexity(char* password) {
 int length = strlen(password);
 int has_upper = 0, has_lower = 0, has_digit = 0;

for (int i = 0; i < length; i++) {
 if (password[i] >= 'A' && password[i] <= 'Z') has_upper = 1; 
if (password[i] >= 'a' && password[i] <= 'z') has_lower = 1;
 if (password[i] >= '0' && password[i] <= '9') has_digit = 1;
 }

return length >= MIN_PASSWORD_LENGTH && has_upper && has_lower && has_digit;
 }

void display_users() {
 printf("\nRegistered Users:\n");
 for (int i = 0; i < user_count; i++) { 
printf("%d. %s\n", i + 1, users[i].username); 
} 
}

void delete_user_by_name() {
 char username[CREDENTIAL_LENGTH]; 
printf("\nEnter username to delete: "); 
fgets(username, CREDENTIAL_LENGTH, stdin); 
fix_fgets_input(username);
 for (int i = 0; i < user_count; i++) {
 if (strcmp(username, users[i].username) == 0) {
 for (int j = i; j < user_count - 1; j++) { 
users[j] = users[j + 1]; 
}
 user_count--; 
printf("\nUser %s deleted successfully!\n", username);
 return;
 }
 }
 printf("\nUser not found!\n");
 }


void update_password() {
 char username[CREDENTIAL_LENGTH];
 char new_password[CREDENTIAL_LENGTH];

 printf("\nEnter username: "); 
fgets(username, CREDENTIAL_LENGTH, stdin);
 fix_fgets_input(username);

for (int i = 0; i < user_count; i++) {
 if (strcmp(username, users[i].username) == 0) {
 printf("\nEnter new password: ");
 input_credentials(NULL, new_password);
 if (check_password_complexity(new_password)) { 
strcpy(users[i].password, new_password);
 printf("\nPassword updated successfully!\n"); 
} else { 
printf("\nPassword update failed! Password must be at least %d characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n", MIN_PASSWORD_LENGTH);
 } 
return;
 }
 }
 printf("\nUser not found!\n"); 
 }

