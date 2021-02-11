# SOBI
// Code property:                                                     //<\br>
// ==============                                                     //<\br>
// TELECOM BRETAGNE                                                   //<\br>
// Dpt. Signal et Communications                                      //<\br>
// Technopole Brest-Iroise                                            //<\br>
// CS 83818 - 29238 Brest Cedex 3 - France                            //<\br>
//                                                                    //<\br>
// General info:                                                      //<\br>
// =============                                                      //<\br>
// program: SOBI.c                                                    //<\br>
// Adapted from: program SeparationSourceSobi.c, 26/09/2013,          //<\br>
// by J. Trubuil (SC)                                                 //<\br>
// last upate: SOBI.c, 18/11/2019, Paloma Bry, Elodie Derringer,      //<\br>
//                                 Lucas Michelis                     //<\br>
// info: thierry.chonavel@telecom-bretagne.eu                         //<\br>
//       thiery.legall1@telecom-bretagne.eu                           //<\br>
//                                                                    //<\br>
// Code info:  	                                                      //<\br>
// ==========                                                         //<\br>
// Separation of a two signals mixture observed on two sensors        //<\br>
// using SOBI algorithm                                               //<\br>
// Mixing matrix: A=[1,1;-1,2]                                        //<\br>
// Mixed signals files:  sobi_in_1.txt & sobi_in_2.txt                //<\br>
// (generated with Matlab program  "CreationMelange.m")               //<\br>
// Outputs: files sobi_out_1.txt & sobi_out_2.txt                     //<\br>
//                                                                    //<\br>
// Source code compilation and execution:                             //<\br>
// ======================================                             //<\br>
// under Ubuntu, compile and link with libm.so as follows             //<\br>
// note : replace separation.* by separation_v0.* for initial test    //<\br>
//                                                                    //<\br>
// $gcc -c math_functions.c -o math_functions.o                       //<\br>
// $gcc -c separation.c -o separation.o                               //<\br>
// $gcc SOBI.c -lm math_functions.o separation.o -o ./SOBI.exe        //<\br>
// $chmod +x SOBI.exe                                                 //<\br>
// $./SOBI.exe
