// gooseChip 02/01/22
// Written by Carson Goodwin (carson.goodwin32@gmail.com)
// Research used: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

#include <stdio.h>

using namespace std;

int main(){

    //Define processor registers

    char v0,v1,v2,v3,v4,v5,v6,v7,v8,v9,va,vb,vc,vd,ve,vf;//General Purpose 8 bit registers v0-vf
    v0=v1=v2=v3=v4=v5=v6=v7=v8=v9=va=vb=vc=vd=ve=vf=0;//Initialize all registers to 0

    short I = 0; //16 bit register I (stores memory addresses). Initialize to 0.

    char soundTmr,delayTmr; //Special purpose 8 bit registers
    soundTmr=delayTmr=0; //Initialize to 0

    short PC = 0; //16 bit program counter. Initialize to 0.

    char SP = 0; //8 bit stack pointer.

    short stackArr[16] = { }; //array of 16 16 bit values for stack. Initialized to 0.


    //Define display parameters

    int dispX,dispY; //Set display resolution mode. Just supports 64x32 for now.
    dispX = 64;
    dispY = 32;

    char dispArr[dispX/8][dispY/8] = { }; //array of 8 bit values for holding current output.


    //Define hardware sprites (hex digits 0-f)
    //Store sprites as 5 columns of 8 bit values for an 8x5 resolution
    char 0spr[1][5] = {240},{144},{144},{144},{240};
    char 1spr[1][5] = {32},{96},{32},{32},{112};
    char 2spr[1][5] = {240},{16},{240},{128},{240};
    char 3spr[1][5] = {240},{16},{240},{16},{240};
    char 4spr[1][5] = {144},{144},{240},{16},{16};
    char 5spr[1][5] = {240},{128},{240},{16},{240};
    char 6spr[1][5] = {240},{128},{240},{144},{240};
    char 7spr[1][5] = {240},{16},{32},{64},{64};
    char 8spr[1][5] = {240},{144},{240},{144},{240};
    char 9spr[1][5] = {240},{144},{240},{16},{240};
    char aspr[1][5] = {240},{144},{240},{144},{144};
    char bspr[1][5] = {224},{144},{224},{144},{224};
    char cspr[1][5] = {240},{128},{128},{128},{240};
    char dspr[1][5] = {224},{144},{144},{144},{224};
    char espr[1][5] = {240},{128},{240},{128},{240};
    char fspr[1][5] = {240},{128},{240},{128},{128};

    while(1){//loop forever and start emulation loop.

    }


    return 0;
}