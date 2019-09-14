#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define SS_INF_NUMBER 14565
#define SL_INF_NUMBER 98286

int SolveSqare(double a, double b, double c, double *x1, double *x2);

int SolveLine(double a, double b, double *x);

bool is_zero(double x);

int main() {
    printf("#Solve the quadratic equation\n"
           "#(c) Denren, Version 1.1 \n\n"

           "#Please enter a, b, c:\n");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    scanf("%lf %lf %lf", &a, &b, &c);

    int nTotal = SolveSqare(a, b, c, &x1, &x2);

    switch (nTotal) {
        case 0:
            printf("No answer!\n");
            break;
        case 1:
            printf("x = %lg\n", x1);
            break;
        case 2:
            printf("x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case SS_INF_NUMBER:
            printf("Infinitely many roots\n");
            break;
        default:
            printf("main(): ERROR output. nTotal=%d", nTotal);
    }
    printf("\n");
    return 0;
}

bool is_zero(double x) {
    double eps = 1e-8;
    if (x <= eps && x >= -eps)
        return 1;
    else
        return 0;
}

int SolveLine(double a, double b, double *x) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(x != NULL);

    if (a == 0 && b == 0) {
        return SL_INF_NUMBER;
    } else if (a == 0) {
        return 0;
    } else {
        *x = -b / a;
        return 1;
    }
}

//--------------------------------------------------------
//! Solver a square equation ax^2 + bx + c = 0
//!
//! @param [in]  a a-coefficient
//! @param [in]  b b-coefficient
//! @param [in]  c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2st root
//!
//! @return Number of roots
//!
//! @note In case of infinity number of roots,
//!       returns SS_INF_NUMBER
//--------------------------------------------------------

int SolveSqare(double a, double b, double c, double *x1, double *x2) {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0) {
        int SolveL = SolveLine(b, c, x1);
        if (SolveL == SL_INF_NUMBER) {
            return SS_INF_NUMBER;
        } else if (SolveL == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        double D = b * b - 4 * a * c;
        if (is_zero(D)) {
            *x1 = -b / (2 * a);
            return 1;
        } else if (D > 0) {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return 2;
        }
    }
}

