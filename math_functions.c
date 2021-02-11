//====================================================================//
// Authors : Paloma Bry, Elodie Derringer, Lucas Michelis             //
// last upate: 18/11/2019                                             //
// info: thierry.chonavel@telecom-bretagne.eu                         //
//       thiery.legall1@telecom-bretagne.eu                           //
//                                                                    //
// Code info:                                                         //
// ==========                                                         //
// Mathematical operations on arrays and matrixes                     //
//                                                                    //
//====================================================================//

#include <stdio.h>
#include <stdlib.h>
#include "math_functions.h"
#include <math.h>

double dot_product(double s1[], double s2[], int n)
{
    double result = 0.0;
    for (int i=0; i<n; i++)
    {
        result = result + s1[i]*s2[i];
    }
    return result;
}

double norm(double s1[], int n)
{
    double result = 0.0;
    result = sqrt(dot_product(s1, s1, n));
    return result;
}

void array_matrix_product(int n, double M1[n][1], double M2[n], double result[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j] += M1[i][1]*M2[j] ;
        }

    }
}

void separation_2(int n,double M[2][2], double s1[n], double s2[n], double output1[n], double output2[n])
{
    for(int i=0;i<n;i++)
    {
       output1[i] = M[0][0]*s1[i] + M[0][1]*s2[i];
       output2[i] = M[1][0]*s1[i] + M[1][1]*s2[i];
    }
}


double tr(int n, double M[n][n])
{
    double result = 0.0;
    for (int i=0; i<n; i++)
    {
        result = result + M[i][i];
    }
    return result/(n);
}

double off(int n,double M[n][n])
{
    double result = 0.0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (j!=i)
            {
                result += M[i][j];
            }
        }
    }
    result = result/n/(n-1);
    return result;
}

void add_matrix(int l, int c, double M1[l][c], double M2[l][c], double M12[l][c])
{
    for (int i=0; i<l; i++)
    {
        for (int j=0; j<c; j++)
        {
           M12[i][j]=M1[i][j]+M2[i][j];
        }
    }
}

void subarray(double a[], int b, int e, double s_a[e-b+1])
{
    for (int i=0;i<e-b+1;i++)
    {
        s_a[i] = a[b+i];
    }
}

void array_transpose(int n, double a[n], double a_t[n][1])
{
    for (int i=0;i<n;i++)
    {
        a_t[i][1] = a[i];
    }
}

void transpose(int l, int c, double M[l][c], double M2[c][l])
{
    for (int i=0; i<l; i++)
    {
        for (int j=0; j<c; j++)
        {
            M2[j][i]=M[i][j];
        }
    }
}

void inverse(double M[2][2])
{
    double a = M[0][0];
    double b = M[0][1];
    double c = M[1][0];
    double d = M[1][1];
    double det_inv = 1/(a*d - b*c);
    M[0][0] = det_inv * d;
    M[0][1] = -det_inv * b;
    M[1][0] = -det_inv * c;
    M[1][1] = det_inv * a;
}

//intercor : w is the size of the window used for averaging, n is the number of samples
void intercor(double s1[], double s2[], int w, int n, double cov[w][w])
{

    for(int i=0;i<w;i++)
    {
        for(int j=0;j<w;j++){
            cov[i][j] = 0;
        }
    }

    int threshold = n/w;
    for (int i=0;i<threshold;i++)
    {
        double suba1[w];
        double suba2[w];
        double transpsub[w][1];
        double prod[w][w];
        for (int i=0;i<w;i++)
        {
            suba1[i] = 0;
            suba2[i] = 0;
            transpsub[i][1] = 0;
            for (int j=0;j<w;j++)
            {
                prod[i][j] = 0;
            }
        }
        subarray(s2, i*w, (i+1)*w-1, suba2);
        subarray(s1, i*w, (i+1)*w-1, suba1);
        array_transpose(w, suba1,transpsub);
        array_matrix_product(w, transpsub, suba2, prod);
        add_matrix( w, w, cov, prod, cov);
    }
    int d = n/w;
//    printf("n :  %lf\n", n);
//    printf("w :  %lf\n", w);
//    printf("d :  %lf\n", d);
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<w; j++)
        {
            cov[i][j]=cov[i][j]/d;
        }
    }
}


