#ifndef FONTS_H
#define FONTS_H

#include "CONF.H" 

static const int S[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,1},
    {0,0,0,0,1},
    {1,1,1,1,1}};                                          
static const int C[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,1,1}};
static const int O[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}};
static const int R[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,1,1,1},
    {1,0,0,1,0},
    {1,0,0,0,1}};
static const int E[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,1}};
static const int L[FONT_SIZE][FONT_SIZE] = {
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,1,1}};
static const int I[FONT_SIZE][FONT_SIZE] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0}};
static const int F[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,0},
    {1,0,0,0,0},
    {1,0,0,0,0}};


static const int NUM0[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {0,1,1,1,0}};  
static const int NUM1[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0}};
static const int NUM2[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {1,1,1,1,1}};
static const int NUM3[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,0},
    {0,0,0,0,1},
    {0,1,1,1,0},
    {0,0,0,0,1},
    {1,1,1,1,0}};
static const int NUM4[FONT_SIZE][FONT_SIZE] = {
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1},
    {0,0,0,0,1},
    {0,0,0,0,1}};
static const int NUM5[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,1},
    {1,0,0,0,0},
    {0,1,1,1,1},
    {0,0,0,0,1},
    {1,1,1,1,1}};
static const int NUM6[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,0},
    {1,0,0,0,1},
    {0,1,1,1,0}};
static const int NUM7[FONT_SIZE][FONT_SIZE] = {
    {1,1,1,1,1},
    {0,0,0,0,1},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,1,0,0,0}};          
static const int NUM8[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {0,1,1,1,0},
    {1,0,0,0,1},
    {0,1,1,1,0}};
static const int NUM9[FONT_SIZE][FONT_SIZE] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {0,1,1,1,1},
    {0,0,0,1,0},
    {0,0,1,0,0}};

static const int (*digitTable[10])[FONT_SIZE][FONT_SIZE] = {&NUM0, &NUM1, &NUM2, &NUM3, &NUM4, &NUM5, &NUM6, &NUM7, &NUM8, &NUM9};                                      

static const int COLON[FONT_SIZE][FONT_SIZE] = {
    {1,1,0,0,0},
    {1,1,0,0,0},
    {0,0,0,0,0},
    {1,1,0,0,0},
    {1,1,0,0,0}};
#endif