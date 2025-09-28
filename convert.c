#include <stdint.h>
#include <string.h>
#include <stdio.h>

void oct_to_bin(const char *oct, char *out){
    out[0]='\0';

    for (int i=0; oct[i]!='\0'; i++){
        switch (oct[i]){
            case '0':
                strcat(out, "000");
                break;
            case '1':
                strcat(out, "001");
                break;
            case '2':
                strcat(out, "010");
                break;
            case '3':
                strcat(out, "011");
                break;
            case '4':
                strcat(out, "100");
                break;
            case '5':
                strcat(out, "101");
                break;
            case '6':
                strcat(out, "110");
                break;
            case '7':
                strcat(out, "111");
                break;
            default:
                strcat(out, "inv");
        }
    }
}