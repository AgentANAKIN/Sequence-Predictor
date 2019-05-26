// acknowledgements
// https://www.fibonicci.com/numerical-reasoning/number-sequences/
// https://math.stackexchange.com/questions/3060249/how-to-test-whether-a-number-is-of-the-form-nn1n2-6
// https://youtu.be/3oFGZDamTDM

// This code tries to determine the next number in a sequence (for non-mathematicians).

// import dependencies
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {



// local variables
double a, b, c; // quadratic variables
double d; // arithmetic common difference
int i, j; // for counting in a loop
int n; // the next number in the sequence
double r; // geometric common ratio
double x, y, z; // random reusable variables
double result;



// sample sequences
//double sequence[6] = {25, 23, 21, 19, 17, 15}; // sample arithmetic sequence
//double sequence[7] = {2187, 729, 243, 81, 27, 9, 3}; // sample geometric sequence
//double sequence[7] = {6, 10, 15, 21, 28, 36, 45}; // sample triangular numbers
//{}double sequence[4] = {45, 36, 28, 21}; // sample triangular numbers
//double sequence[7] = {9, 16, 25, 36, 49, 64, 81}; // sample square numbers
//double sequence[3] = {100, 81, 64}; // sample square numbers
//double sequence[7] = {27, 64, 125, 216, 343, 512, 729}; // sample cube numbers
//double sequence[3] = {729, 512, 343}; // sample cube numbers
//double sequence[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}; // sample fibonacci sequence
//double sequence[4] = {34, 21, 13, 8}; //sample fibonacci sequence
//double sequence[5] = {1, 3, 9, 19, 33}; // sample quadratic sequence
//double sequence[5] = {7, 13, 19, 25, 31}; // sample linear sequence
//double sequence[5] = {28, 25, 22, 19, 16, 13}; // sample linear sequence 
//double sequence[7] = {20, 35, 56, 84, 120, 165, 220}; // sample tetrahedral sequence
//double sequence[5] = {220, 165, 120, 84, 56}; // sample tetrahedral sequence
//double sequence[9] = {19, 23, 29, 31, 37, 41, 43, 47, 53}; // sample prime numbers
//double sequence[5] = {53, 47, 43, 41, 37}; // sample prime numbers
//double sequence[8] = {3, 8, 15, 24, 35, 48, 63, 80}; // solved SoloLearn challenge
double sequence[5] = {2, -4, 6, -8, 10}; // YouTube tutorial
//double sequence[6] = {111, 113, 117, 119, 123, 137}; // SoloLearn Challenge
//double sequence[4] = {123, 117, 108, 99}; // SoloLearn challenge
//double sequence[7] = {7, 8, 5, 5, 3, 4, 4}; // unknown



// determine the position of the next number
n = (sizeof(sequence) / sizeof(double)) + 1;



// display the sequence on screen
printf("%f", sequence[0]);
for (i = 1; i < (n - 1); i++){
    printf(", %f", sequence[i]);
}
printf(", ...\n\n");



// arithmetic sequence
if ((sequence[1] - sequence[0]) == (sequence[2] - sequence[1])){
    d = (sequence[1] - sequence[0]);
    result = (sequence[0] + ((n - 1) * d));
    printf("arithmetic: %f\ncommon difference: %f\n\n", result, d);
} 

// geometric sequence
x = (sequence[1] / sequence[0]);
y = (sequence[2] / sequence[1]);
z = (sequence[3] / sequence[2]);
if ((x == y) && (x == z)){
    r = (sequence[1] / sequence[0]);
    result = sequence[0] * pow(r, n - 1);
    printf("geometric: %f\ncommon ratio %f\n\n", result, r);
}

// triangular numbers
x = ((sqrt((8 * sequence[0]) + 1) - 1) / 2);
y = ((sqrt((8 * sequence[1]) + 1) - 1) / 2);
z = ((sqrt((8 * sequence[2]) + 1) - 1) / 2);
if ((y == (x + 1)) && (z == (x + 2))){
    i = (n - 2);
    x = sequence[i];
    y = ((sqrt((8 * x) + 1) - 1) / 2);
    z = (y + 1);
    result = ((pow(z, 2) + z) / 2);
    printf("triangular: %f\n\n", result);
} else if ((y == (x - 1)) && (z == (x - 2))){
    i = (n - 2);
    x = sequence[i];
    y = ((sqrt((8 * x) + 1) - 1) / 2);
    z = (y - 1);
    result = ((pow(z, 2) + z) / 2);
    printf("triangular: %f\n\n", result);
} 

// square numbers
x = sqrt(sequence[0]);
y = sqrt(sequence[1]);
z = sqrt(sequence[2]);
if ((y == (x + 1)) && (z == (x + 2))){
    i = (n - 2);
    x = sequence[i];
    y = sqrt(x);
    z = (y + 1);
    result = pow(z, 2);
    printf("square: %f\n\n", result);
} else if ((y == (x - 1)) && (z == (x - 2))){
    i = (n - 2);
    x = sequence[i];
    y = sqrt(x);
    z = (y - 1);
    result = pow(z, 2);
    printf("square: %f\n\n", result);
}

// cube numbers
x = cbrt(sequence[0]);
y = cbrt(sequence[1]);
z = cbrt(sequence[2]);
if ((y == (x + 1)) && (z == (x + 2))){
    i = (n - 2);
    x = sequence[i];
    y = cbrt(x);
    z = (y + 1);
    result = pow(z, 3);
    printf("cube: %f\n\n", result);
} else if ((y == (x - 1)) && (z == (x - 2))){
    i = (n - 2);
    x = sequence[i];
    y = cbrt(x);
    z = (y - 1);
    result = pow(z, 3);
    printf("cube: %f\n\n", result);
}

// fibonacci sequence
if ((sequence[2] == (sequence[1] + sequence[0])) && (sequence[3] == (sequence[2] + sequence[1]))){
    i = (n - 2);
    j = (n - 3);
    result = sequence[i] + sequence[j];
    printf("fibonacci: %f\nadd previous 2 numbers\n\n", result);
} else if ((sequence[2] == (sequence[0] - sequence[1])) && (sequence[3] == (sequence[1] - sequence[2]))){
    i = (n - 2);
    j = (n - 3);
    result = sequence[j] - sequence[i];
    printf("reverse fibonacci: %f\nsubtract last number from previous number\n\n", result);
}

// quadratic sequence
x = sequence[1] - sequence[0];
y = sequence[2] - sequence[1];
z = sequence[3] - sequence[2];
if ((y - x) == (z - y)){
    a = .5 * (y - x);
    x = sequence[0] - (a * pow(1, 2));
    y = sequence[1] - (a * pow(2, 2));
    z = sequence[2] - (a * pow(3, 2));
    b = y - x;
    c = x - b;
    result = (a * pow(n, 2)) + (b * n) + c;
    printf("quadratic: %f\n%fn^2 + %fn + %f\n\n", result, a, b, c);
}

// linear sequence
x = sequence[1] - sequence[0];
y = sequence[2] - sequence[1];
z = sequence[3] - sequence[2];
if ((x == y) && (x == z)){
    c = sequence[0] - x;
    result = (x * n) + c;
    printf("linear: %f\n(%f * %i) + %f\n\n", result, x, n, c);
}

// tetrahedral sequence
i = 0;
for (j = 0; j < (n - 1); j++){
    x = ((6 * sequence[j]) + cbrt(6 * sequence[j]));
    y = cbrt(x);
    z = (int)(y + .5) - 1; 
//    printf("x %f y %f a %f\n\n", x, y, z);
    if (((z * (z + 1) * (z + 2)) / 6) == sequence[j]){
        i = 1;
    } else {
        break;
    }
}
if ((i == 1) && (sequence[1] > sequence[0])){
    result = ((z + 1) * (z + 2) * (z + 3)) / 6;
    j = z + 1;
    printf("tetrahedral: %f\n(%i(%i + 1)(%i + 2)) / 6\n\n", result, j, j, j);
} else if ((i == 1) && (sequence[0] > sequence[1])){
    result = ((z - 1) * (z) * (z + 1)) / 6;
    j = z - 1;
    printf("tetrahedral: %f\n(%i(%i + 1)(%i + 2)) / 6\n\n", result, j, j, j);
}

// prime numbers
for (i = 0; i < (n - 1); i++){
    x = sequence[i];
    for (j = 2; j < x; j++){
        if ((int)x % j == 0){
            i = n + 1;
            break;
        } 
    }
}
if (i == (n - 1)){
    x = sequence[n - 2];
    if (sequence[1] > sequence[0]){
        x = x + 1;
        j = 2;
        while (j < x){
            for (j = 2; j < x; j++){
                if ((int)x % j == 0){
                    x = x + 1;
                    break;
                }
            }
            
        }
    } else if (sequence[0] > sequence[1]) {
        x = x - 1;
        j = 2;
        while (j < x){
            for (j = 2; j < x; j++){
                if ((int)x % j == 0){
                    x = x - 1;
                    break;
                }
            }
            
        }
    }
    printf("The next prime number is: %f\n\n", x);
}

    return 0;
}
