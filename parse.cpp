//Chip 8 Disassembler
//Written By Carson Goodwin
//Apr 6 2023

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void printOpcode(unsigned short data){

    unsigned char opBit = (unsigned char)((data>>8) & 0xf0);//first 4 bytes, next 4 are zeroed. EX: 0x80, 0x70
    unsigned char endBit = (unsigned char)(data & 0x000f); //last 4 bytes, first 4 are zeroed. EX: 0x08, 0x07
    unsigned short addr = data & 0x0fff;//12 byte address, first 4 bytes are 0.
    unsigned char lowByte = (unsigned char)(data & 0x00ff);//back half of the data address.
    unsigned char xByte = (unsigned char)((data >> 8) & 0x0f);//second 4 byte chunk. first 4 are zeroed. EX: 0x08, 0x07
    unsigned char yByte = ((unsigned char)((data) & 0x00f0)>> 4) & 0x0F;//third 4 byte chunk. first 4 are zeroed. EX: 0x08, 0x07
    if(opBit == 0x00){
        if(endBit == 0x00){
            printf("CLS: ");
        }
        else{
            printf("RET: ");
        }

    }
    else if(opBit == 0x10){
        printf("JP %03X: ",addr);
    }
    else if(opBit == 0x20){
        printf("CALL %03X: ",addr);
    }
    else if(opBit == 0x30){
        printf("SE V%01X, %02X: ",xByte,lowByte);

    }
    else if(opBit == 0x40){
        printf("SNE V%01X, %02X: ",xByte,lowByte);

    }
    else if(opBit == 0x50){
        printf("SE V%01X, V%01X: ",xByte,yByte);

    }
    else if(opBit == 0x60){
        printf("LD V%01X, %02X: ",xByte,lowByte);
    }
    else if(opBit == 0x70){
        printf("ADD V%01X, %02X: ",xByte,lowByte);

    }
    else if(opBit == 0x80){
        if(endBit == 0x00){
            printf("LD V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x01){
            printf("OR V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x02){
            printf("AND V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x03){
            printf("XOR V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x04){
            printf("ADD V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x05){
            printf("SUB V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x06){
            printf("SHR V%01X, V%01X: ",xByte,yByte);
        }
        else if(endBit == 0x07){
            printf("SUBN V%01X, V%01X: ",xByte,yByte);
        }
        else{//0E
            printf("SHL V%01X, V%01X: ",xByte,yByte);
        }
    }
    else if(opBit == 0x90){
        printf("SNE V%01X, V%01X: ",xByte,yByte);
    }
    else if(opBit == 0xA0){
        printf("LD I, %03X: ",addr);
    }
    else if(opBit == 0xB0){
        printf("JP V0, %03X: ",addr);

    }
    else if(opBit == 0xC0){
        printf("RND V%01X, %02X: ",xByte,lowByte);
    }
    else if(opBit == 0xD0){
        printf("DRW V%01X, V%01X, %01X: ",xByte,yByte,endBit);
    }
    else if(opBit == 0xE0){
        if(lowByte == 0x9E){
            printf("SKP V%01X: ",xByte);
        }
        else{//lowByte == 0xA1
            printf("SKNP V%01X: ",xByte);
        }
    }
    else{//0xF0
        if(lowByte == 0x07){
            printf("LD V%01X, DT: ",xByte);
        }
        else if(lowByte == 0x0A){
            printf("LD V%01X, K: ",xByte);
        }
        else if(lowByte == 0x15){
            printf("LD DT, V%01X: ",xByte);
        }
        else if(lowByte == 0x18){
            printf("LD ST, V%01X: ",xByte);
        }
        else if(lowByte == 0x1E){
            printf("ADD I, V%01X: ",xByte);
        }
        else if(lowByte == 0x29){
            printf("LD F, V%01X: ",xByte);
        }
        else if(lowByte == 0x33){
            printf("LD B, V%01X: ",xByte);
        }
        else if(lowByte == 0x55){
            printf("LD [I], V%01X: ",xByte);
        }
        else{//lowByte == 0x65
            printf("LD V%01X, [I]: ",xByte);
        }
    }

}


int parse(char* filename){
    FILE *fptr;
    long length;
    char *buffer;
    fptr = fopen(filename,"rb");
    if(fptr == NULL){
        printf("Could not open file");
        exit(1);
    }//Load rom into 0x200 
    if(fptr){
        fseek (fptr, 0, SEEK_END);
        length = ftell (fptr);
        fseek (fptr, 0, SEEK_SET);
        buffer = (char*)malloc ((length+1)*sizeof(char));
        if(buffer){
            fread (buffer, sizeof(char), length, fptr);
        }
        fclose(fptr);
    }
    for(long i = 0;i<length;i+=2){
        unsigned short data = (((unsigned char)buffer[i]<<8)|(unsigned char)buffer[i+1]);
        printOpcode(data);
        printf("0x%04X\n",data);

    }
    free(buffer);
    return 0;
}

int main(){
    parse((char*)"test.ch8");
    return 0;
}