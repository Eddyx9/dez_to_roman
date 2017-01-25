/* roman_number.c */
#include <stdio.h>

int rom_number [256];

void output(int limit);

/* Which chars are needed?
 * Find values for roman chars */
int transformation(int number) {
    const int steps [13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };    //steps for different chars
    int i=0, j=0;
    
    while(number > 0) {
        if(number/steps [j] >= 1) {
            rom_number [i] = steps [j];
            number -= steps [j];
            i++;
        }
        else {
            j++;
        }
    }
    //output(i);
    return i;
}

/* Output right char for value */
void output(int limit) {
    int i;
    printf("roman number:\t");
    
    for(i=0; i < limit; i++) {          //output char
        
        switch(rom_number [i]) {
            case 1:     printf("I");
                        break;
            case 4:     printf("IV");
                        break;
            case 5:     printf("V");
                        break;
            case 9:     printf("IX");
                        break;
            case 10:    printf("X");
                        break;
            case 40:    printf("XL");
                        break;
            case 50:    printf("L");
                        break;
            case 90:    printf("XC");
                        break;
            case 100:   printf("C");
                        break;
            case 400:   printf("CD");
                        break;
            case 500:   printf("D");
                        break;
            case 900:   printf("CM");
                        break;
            case 1000:  printf("M");
                        break;
        }
    }
    printf("\n");
}


int main(void) {
    int number;
    
    printf("decimal number:\t");
    scanf("%i", &number);           //input
    
    if(number > 3999) {                             //max. size
        printf("Please enter a smaller number\n");
        return 1;
    }
    //transformation(number);
    output(transformation(number));
    return 0;
}