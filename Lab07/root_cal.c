#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double newtonRaphson(double n) {
    double approximation = 1.0; // 初始猜测值
    double new_approximation;

    do {
        new_approximation = 0.5 * (approximation + n / approximation);
        if (fabs(new_approximation - approximation) < 1e-9) {
            break;
        }
        approximation = new_approximation;
    } while (1);

    return approximation;
}

void hidden_factor(double coeff) {
    if(fabs(coeff - 1.0) < 1e-6) {  // Coefficient is 1
        // Don't print 1
    } else if(fabs(coeff + 1.0) < 1e-6) {  // Coefficient is -1
        printf("-");
    } else {
        printf("%g", coeff);
    }
}

int main() {
    double a, b, c;
    printf("Enter coefficients a, b, and c of the quadratic equation (a*x^2 + b*x + c = 0), separated by spaces: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double _discriminant = b * b - 4 * a * c;
    if(_discriminant < 0) {
        printf("The equation has no real roots.\n");
    } else {
        double discriminant = newtonRaphson(_discriminant);
        printf("The sqrt value of discriminant: %g\n", discriminant);
        if(discriminant < 0) {
            printf("The equation has no real roots.\n");
        } else if(discriminant == 0) {
            double root = -b / (2 * a);
            printf("The equation ");
            hidden_factor(a);
            printf("x^2 + ");
            hidden_factor(b);
            printf("x + %g has only one root: %g", c, root);
        } else {
            double root1 = (-b + discriminant) / (2 * a);
            double root2 = (-b - discriminant) / (2 * a);
            printf("The equation ");
            hidden_factor(a);
            printf("x^2 + ");
            hidden_factor(b);
            printf("x + %g has two roots: %g and %g\n", c, root1, root2);
        }
    }
    return 0;
}