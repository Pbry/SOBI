//====================================================================//
// Authors : Paloma Bry, Elodie Derringer, Lucas Michelis             //
// last upate: 18/11/2019                                             //
// info: thierry.chonavel@telecom-bretagne.eu                         //
//       thiery.legall1@telecom-bretagne.eu                           //
//                                                                    //
// Code info:  	                                                      //
// ==========                                                         //
// Separation of a two signals mixture using SOBI algorithm           //
//                                                                    //
//====================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "separation_v0.h"
#include "math_functions.h"

void separation_v0(double input_1[], double input_2[], double output_1[], double output_2[], int nb_samples, int time_delay)
{
    //time_delay is the number of time delays for time correlations in SOBI
    double Rx1x1[time_delay][time_delay];
    intercor(input_1,input_1,time_delay, nb_samples, Rx1x1);
    double F1 = off(time_delay, Rx1x1);
    double T1 = tr(time_delay, Rx1x1);

//    printf("R11[0][0] :  %lf\n", Rx1x1[0][0]);
//    printf("R11[1][1] :  %lf\n", Rx1x1[1][1]);
//    printf("R11[2][2] :  %lf\n", Rx1x1[2][2]);
//    printf("R11[3][3] :  %lf\n", Rx1x1[3][3]);
//    printf("R11[1][2] :  %lf\n", Rx1x1[0][1]);
//    printf("R11[2][1] :  %lf\n", Rx1x1[1][0]);

    double Rx2x2[time_delay][time_delay];
    intercor(input_2,input_2,time_delay, nb_samples, Rx2x2);
    double F2 = off(time_delay, Rx2x2);
    double T2 = tr(time_delay, Rx2x2);

    double Rx1x2[time_delay][time_delay];
    intercor(input_1,input_2,time_delay, nb_samples, Rx1x2);
    double F12 = off(time_delay, Rx1x2);
    double T12 = tr(time_delay, Rx1x2);

    double alpha = 2*F12*T12 - (F1*T2 + F2*T1);
    double beta = 2* (pow(T12,2) - T1*T2);
    double gamma = sqrt( pow(F1*T2 - F2*T1, 2) + 4*(F12*T2 - T12*F2)*(F12*T1 - T12*F1) );

    double d1 = alpha - gamma;
    double d2 = alpha + gamma;

//    printf("T1 :  %lf\n", T1);
//    printf("T2 :  %lf\n", T2);
//    printf("T12 :  %lf\n", T12);
//    printf("F1 :  %lf\n", F1);
//    printf("F2 :  %lf\n", F2);
//    printf("F12 :  %lf\n", F12);

    double A_est[2][2];
    A_est[0][0] = beta*F1 - T1*d1;
    A_est[0][1] = beta*F12 - T12*d2;
    A_est[1][0] = beta*F12 - T12*d1;
    A_est[1][1] = beta*F2 - T2*d2;

//    printf("A_est[0][0] :  %lf\n", A_est[0][0]);
//    printf("A_est[0][1] :  %lf\n", A_est[0][1]);
//    printf("A_est[1][0] :  %lf\n", A_est[1][0]);
//    printf("A_est[1][1] :  %lf\n", A_est[1][1]);

//    double norm_0 = sqrt(pow(A_est[0][0],2) + pow(A_est[1][0], 2));
//    A_est[0][0] = A_est[0][0]/norm_0;
//    A_est[1][0] = A_est[1][0]/norm_0;
//    double norm_1 = sqrt(pow(A_est[0][1],2) + pow(A_est[1][1], 2));
//    A_est[0][1] = A_est[0][1]/norm_1;
//    A_est[1][1] = A_est[1][1]/norm_1;

    inverse(A_est);


    separation_2(nb_samples, A_est, input_1, input_2, output_1, output_2);

}
