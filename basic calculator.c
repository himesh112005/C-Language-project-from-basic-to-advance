#include<stdio.h>
#include<math.h>
double add(double, double);
double sub(double, double );
double mul(double, double); 
double division (double,double);
double modulus(double, double);
double square_root(double);
void print_menu();

int main()
{
int  choice;
double first, second, result;

while(1) {
print_menu();
scanf("%d", & choice);
if (choice == 8)
 {

break;
}



if (choice < 1 || choice > 8)
{
fprintf(stderr, "Invalid Menu Choice.");
continue;
}
if (choice == 7) {
printf("\nPlease enter the number: ");
scanf("%lf", &first);
result = square_root(first);
} else {
   printf("\nPlease enter the first number: "); 
   scanf("%lf", &first); 
printf("Now, enter the second number: ");
scanf("%lf", &second);

switch (choice) {
case 1: 
result = add(first, second);
break;
case 2 : 
result = sub(first, second);
break;
case 3:
result = mul(first, second);
break;
case 4:
result = division(first, second);
break;
case 5: 
result =modulus(first, second);
break;
case 6:
result = pow(first, second);
break;
}
}
if (!isnan(result)) {
printf("\nResult of operation is: %2f\n", result);
}
}
return 0;
}
double add(double a, double b) {
return a+b;
}
double sub(double a,double b) {
return a-b;
}
double mul(double a,double b) {
return a*b;
}
double division(double a, double b) {
if (b==0) {
fprintf(stderr, "Invalid Arguments for Division\n");
return NAN;
}
else {
return a/b;
}
}

double modulus(double a, double b) {
if ((int)b ==0) {
fprintf(stderr, "Invalid Arguments for Modulus\n"); 
return NAN;
} else
 {
     return (int)a % (int)b;
      }
       }
double square_root(double a) 
{ 
    if (a < 0) { 
        fprintf(stderr, "Invalid Argument for Square Root\n");
         return NAN;
          } else
           {
             return sqrt(a);
              }
               }
               void print_menu() {
 printf("\n\n=================================\n");
printf("🌟 Welcome to the Simple Calculator 🌟\n");
printf("=================================\n\n");
printf("Please choose one of the following options:\n");
printf("1. ➕ Add\n");
printf("2. ➖ Subtract\n");
printf("3. ✖️ Multiply\n");
printf("4. ➗ Divide\n");
printf("5. ➗ Modulus\n");
printf("6. 💪 Power\n");
printf("7. 📏 Square Root\n");
printf("8. 🚪 Exit\n");
printf("\nEnter your choice: ");

}

