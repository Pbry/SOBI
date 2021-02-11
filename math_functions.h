#ifndef MATH_FUNCTIONS_H_INCLUDED
#define MATH_FUNCTIONS_H_INCLUDED


double dot_product(double s1[], double s2[], int n);
double norm(double s1[], int n);
double tr(int n, double M[n][n]);
double off(int n,double M[n][n]);
void add_matrix(int l, int c, double M1[l][c], double M2[l][c], double M12[l][c]);
void subarray(double a[], int b, int e, double s_a[e-b+1]);
void array_matrix_product(int n, double M1[n][1], double M2[n], double result[n][n]);
void separation_2(int n,double M[2][2], double s1[n], double s2[n], double output1[n], double output2[n]);
void array_transpose(int n, double a[n], double a_t[n][1]);
void transpose(int l, int c, double M[l][c], double M2[c][l]);
void inverse(double M[2][2]);
void intercor(double s1[], double s2[], int w, int n, double cov[w][w]);


#endif // MATH_FUNCTIONS_H_INCLUDED
