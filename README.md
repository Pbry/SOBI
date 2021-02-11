# SOBI
// Code property:                                                     //
// ==============                                                     //
// TELECOM BRETAGNE                                                   //
// Dpt. Signal et Communications                                      //
// Technopole Brest-Iroise                                            //
// CS 83818 - 29238 Brest Cedex 3 - France                            //
//                                                                    //
// General info:                                                      //
// =============                                                      //
// program: SOBI.c                                                    //
// Adapted from: program SeparationSourceSobi.c, 26/09/2013,          //
// by J. Trubuil (SC)                                                 //
// last upate: SOBI.c, 18/11/2019, Paloma Bry, Elodie Derringer,      //
//                                 Lucas Michelis                     //
// info: thierry.chonavel@telecom-bretagne.eu                         //
//       thiery.legall1@telecom-bretagne.eu                           //
//                                                                    //
// Code info:  	                                                      //
// ==========                                                         //
// Separation of a two signals mixture observed on two sensors        //
// using SOBI algorithm                                               //
// Mixing matrix: A=[1,1;-1,2]                                        //
// Mixed signals files:  sobi_in_1.txt & sobi_in_2.txt                //
// (generated with Matlab program  "CreationMelange.m")               //
// Outputs: files sobi_out_1.txt & sobi_out_2.txt                     //
//                                                                    //
// Source code compilation and execution:                             //
// ======================================                             //
// under Ubuntu, compile and link with libm.so as follows             //
// note : replace separation.* by separation_v0.* for initial test    //
//                                                                    //
// $gcc -c math_functions.c -o math_functions.o                       //
// $gcc -c separation.c -o separation.o                               //
// $gcc SOBI.c -lm math_functions.o separation.o -o ./SOBI.exe        //
// $chmod +x SOBI.exe                                                 //
// $./SOBI.exe
