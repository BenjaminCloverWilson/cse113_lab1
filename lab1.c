/**
 * @file lab1.c
 * @brief Geometry calculator
 * @details Takes user input as either integers or doubles.
 * and returns various geometric calculations using functions.
 * It calculates area, perimeter, and diagonal of a rectabgle,
 * the radius and circumference of a circle, the area and perimeter of a triangle,
 * and the exterior angle, sum of interior angles, individual interior angle,
 * and the area of a regular polygon.
 * 
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug None
 * @todo None
 */

#include <stdio.h>
#include <math.h>

/* function prototypes. Definitions are below main() */
int area_rectangle(int l, int w);
int perimeter_rectangle(int l, int w);
double diagonal_rectangle(int l, int w);

double area_circle(double rad);
double circumference(double rad);

double area_triangle(double a, double b);
double hypotenuse(double a, double b);
double perimeter_triangle(double a, double b);

double exterior_angle(int n);
double interior_angle(int n);
double sum_interior_angle(int n);
double area_regular_polygon(int n, double s);

/* main function */
int main(void){

    printf("Welcome to Benjamin Wilson's Geometry Calculator!\n\n");

    /* Code for rectangle input/output and function calls */
    /* hard coded values for rectangle input before calculations */
    /**
     * int rect_length = 3;
     * int rect_width = 2;
     */

    /* variables for storing rectangle input and output */
    int rect_length;
    int rect_width;
    int rect_area;
    int rect_perim;
    double rect_diag;

    /* Asks for and takes user input for rectangle  */
    printf("Please input the integer length of the rectangle: ");
    scanf("%d", &rect_length);
    printf("\nPlease input the integer width of the rectangle: ");
    scanf("%d", &rect_width);

    printf("\n----------Rectangle Calculations----------\n\n");

    /** 
     * calls area_rectangle() 
     * printf is split for display purposes only
     */
    rect_area = area_rectangle(rect_length, rect_width);
    printf("The area of your rectangle with length %d", rect_width);
    printf(" and width %d", rect_length);
    printf(" equals: %d\n\n", rect_area);

    /** 
     * calls perimeter_rectangle() 
     * printf is split for display purposes only
     */
    rect_perim = perimeter_rectangle(rect_length, rect_width);
    printf("The perimeter of your rectangle with length %d", rect_width);
    printf(" and width %d", rect_length);
    printf(" equals: %d\n\n", rect_perim);

    /** 
     * calls diagonal_rectangle() 
     * printf is split for display purposes only
     */
    rect_diag = diagonal_rectangle(rect_length, rect_width);
    printf("The diagonal of your rectangle with length %d", rect_width);
    printf(" and width %d", rect_length);
    printf(" equals: %lf\n\n", rect_diag);
    

    /* Code for circle input/output and function calls */
    /* hard coded values for circle input before calculations */
    /**
     * double radius = 2.0;
     */

    /* variables for storing circle input and output */
    double radius;
    double cir_area;
    double cir_circum;

    /* Asks for and takes user input for circle */
    printf("Please enter the radius of your circle as a floating point: ");
    scanf("%lf", &radius);

    printf("\n----------Circle Calculations----------\n\n");

    /* Calls area_circle() */
    cir_area = area_circle(radius);
    printf("The area of the cirlce with radius %lf is: %lf\n\n", radius, cir_area);

    /** 
     * calls circumference() 
     * printf is split for display purposes only
     */
    cir_circum = circumference(radius);
    printf("The circumference of the circle with radius");
    printf(" %lf is: %lf\n\n", radius, cir_circum);


    /* Code for triangle input/output and function calls */
    /* hard coded values for circle input before calculations */
    /**
     * double tri_base = 1.0;
     * double tri_height = 1.0;
     */

    /* variables for storing triangle input and output */
    double tri_base;
    double tri_height;
    double tri_area;
    double tri_perim;

    /* Asks for and takes user input for triangle */
    printf("Please enter the base of the right triangle as a floating point: ");
    scanf("%lf", &tri_base);
    printf("\nPlease enter the height of the right triangle as a floating point: ");
    scanf("%lf", &tri_height);

    printf("\n----------Triangle Calculations----------\n\n");

    /** 
     * calls area_triangle() 
     * printf is split for display purposes only
     */
    tri_area = area_triangle(tri_base, tri_height);
    printf("The area of the right triangle with a base of ");
    printf("%lf and a height of %lf is: %lf\n\n", tri_base, tri_height, tri_area);

    /** 
     * calls perimeter_triangle() 
     * printf is split for display purposes only
     */
    tri_perim = perimeter_triangle(tri_base, tri_height);
    printf("The perimeter of the right triangle with a base of ");
    printf("%lf and a height of %lf is: %lf\n\n", tri_base, tri_height, tri_perim);


    /* Code for regular polygon input/output and function calls */
    /*Hardcoded values for variables. Test cases with known output*/
    /* int sides_num = 8;
     * double poly_length = 5.0;
     */

    /* Variables for storing regular polygon input/output */
    int sides_num;
    double poly_length;
    double ext_angle;
    double total_int_angle;
    double int_angle;
    double poly_area;

    /* Asks for and takes user input for regular polygon */
    printf("Enter the number of sides of a regular polygon as an integer: ");
    scanf("%d", &sides_num);
    printf("\nEnter the length of the side of a regular polygon as a floating point: ");
    scanf("%lf", &poly_length);

    printf("\n----------Regular Polygons----------\n\n");

    /** 
     * calls exterior_angle() 
     * printf is split for display purposes only
     */
    ext_angle = exterior_angle(sides_num);
    printf("The exterior angle of a regular polygon with");
    printf(" %d sides is: %lf degrees \n\n", sides_num, ext_angle);

    /** 
     * calls sum_interior_angle() 
     * printf is split for display purposes only
     */
    total_int_angle = sum_interior_angle(sides_num);
    printf("The sum of the interior angles of a regular polygon with");
    printf(" %d sides is: %lf degrees \n\n", sides_num, total_int_angle);

    /** 
     * calls interior_angle() 
     * printf is split for display purposes only
     */
    int_angle = interior_angle(sides_num);
    printf("A single interior angle of a regular polygon with");
    printf(" %d sides is: %lf degrees \n\n", sides_num, int_angle);

    /** 
     * calls area_regular_polygon() 
     * printf is split for display purposes only
     */
    poly_area = area_regular_polygon(sides_num, poly_length);
    printf("The area of a regular polygon with ");
    printf("%d sides, each %lf", sides_num, poly_length); 
    printf(" units long, is: %lf \n\n", poly_area);

    return 0;
}

/* function definitions */

/**
 * Multiplies two integer variables, length and width
 * @param l is the length and first multiple
 * @param w is the width and second multiple
 * @return the product l * w
 */
int area_rectangle(int l, int w)
{
    return l * w;
}

/**
 * Multiplies two integer variables by 2 separatly and then adds the two products
 * @param l is the length and first variable
 * @param w is the width and second variable
 * @return the sum (2 * l) + (2 * w)
 */
int perimeter_rectangle(int l, int w)
{
    return 2 * l + 2 * w;
}

/**
 * Pythagorean Theoreom of two integer variables, length and width. Calls sqrt()
 * and pow() from the math.h library.
 * @param l is the length and first side of the pythagorean theorem
 * @param w is the width and second side of the pythagorean theorem
 * @return the square root of the sum of l^2 and w^2
 */
double diagonal_rectangle(int l, int w)
{
    return sqrt((pow(l, 2) + pow(w, 2)));
}

/**
 * Multiples an approximation of pi by the squared double variable. Calls pow()
 * from the math.h library.
 * @param rad is the variable that is squared
 * @return the product of 3.141593 * rad^2
 */
double area_circle(double rad)
{
    return 3.141593 * pow(rad, 2);
}

/**
 * Multiples a doubled approximation of pi by a double variable. Calls pow()
 * from the math.h library.
 * @param rad is the radius.
 * @return the product of 2 * 3.141593 * rad
 */
double circumference(double rad)
{
    return 2 * 3.141593 * rad;
}

/**
 * Divides the product of two double variables by 2
 * @param a is the first multiple
 * @param b is the second multiple
 * @return the quotient of (a * b) / 2
 */
double area_triangle(double a, double b)
{
    return a * b / 2;
}

/**
 * Pythagorean Theorem of two double variables
 * @param a is the first side of the Pythagorean Theorem
 * @param b is the second side of the Pythagorean Theorem
 * @return the square root of the sum of a^2 and b^2
 */
double hypotenuse(double a, double b)
{
    return sqrt((pow(a, 2) + pow(b, 2)));
}

/**
 * Adds three doubles. One of which is calculated by the prior hypotenuse()
 * @param a is the first addend
 * @param b is the second addend
 * @return the sum of a + b + the sum of the called hypotenuse() function
 * @remarks The parameters used in the hypotenuse() function are identical
 * to the parameters of this function. The sum of the hypotenuse() function
 * is then used to calculate the final sum.
 */
double perimeter_triangle(double a, double b)
{
    return a + b + hypotenuse(a, b);
}

/**
 * Divides a 360 by an integer variable
 * @param n is the denominator
 * @return the quotient of 360 / n
 */
double exterior_angle(int n)
{
    return 360 / n;
}

/**
 * The difference of an integer variable subtracted by 2 is multiplied by 180.
 * This product is then divided by the same integer variable mentioned above.
 * @param n is the minuend and the denominator
 * @return the quotient of (180 * (n - 2)) / n
 */
double interior_angle(int n)
{
    return (180 * (n - 2)) / n;
}

/**
 * The difference of an integer variable subtracted by 2 is multipled by 180.
 * @param n is the minuend
 * @return the product of 180 * (n - 2)
 */
double sum_interior_angle(int n)
{
    return 180 * (n - 2);
}

/**
 * Plugs a double variable for the length of sides, and an integer variable
 * for the number of sides into the formula for the area of a regular polygon.
 * @param n is the number of sides (second multiple in numerator and denominator)
 * in the tan() function.
 * @param s is the length of sides (its square is the first multiple of the numerator)
 * @return the area of a regular polygon depending on the number and length of
 * its sides.
 * @remarks tan() and pow() are from the math.h library. Plus, only the
 * approximation of pi is used in the tangent for the regular polygon formula.
 */
double area_regular_polygon(int n, double s)
{
    return (pow(s, 2) * n) / (4 * tan(3.141593 / n));
}