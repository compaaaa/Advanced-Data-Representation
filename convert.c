#include <stdint.h>
#include <string.h>
#include <stdio.h>

void oct_to_bin(const char *oct, char *out){
    out[0]='\0'; // Initialize output string

    for (int i=0; oct[i]!='\0'; i++){
        switch (oct[i]){ // To find matching octal digits
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
void oct_to_hex(const char *oct, char *out){
    out[0]='\0';
    // Convert octal to binary
    char bin_buffer[100];
    oct_to_bin(oct, bin_buffer);

    // Pad binary string to make length a multiple of 4
    int bin_len = strlen(bin_buffer);
    int pad = (4 - (bin_len % 4)) % 4; // Calculates how many 0s to add

    char pad_bin[104];
    pad_bin[0]='\0';

    for (int i = 0; i < pad; i++){
        strcat(pad_bin, "0");
    }
    strcat(pad_bin, bin_buffer);
    // Group by 4 and convert each to hex
    int pad_len = strlen(pad_bin);

    for (int i = 0; i < pad_len; i+=4){
        char chunk[5];
        strncpy(chunk, pad_bin + i, 4);
        chunk[4] = '\0';
        if (strcmp(chunk, "0000") == 0){
            strcat(out, "0");
        } else if (strcmp(chunk, "0001") == 0){
            strcat(out, "1");
        } else if (strcmp(chunk, "0010") == 0){
            strcat(out, "2");
        } else if (strcmp(chunk, "0011") == 0){
            strcat(out, "3");
        } else if (strcmp(chunk, "0100") == 0){
            strcat(out, "4");
        } else if (strcmp(chunk, "0101") == 0){
            strcat(out, "5");
        } else if (strcmp(chunk, "0110") == 0){
            strcat(out, "6");
        } else if (strcmp(chunk, "0111") == 0){
            strcat(out, "7");
        } else if (strcmp(chunk, "1000") == 0){
            strcat(out, "8");
        } else if (strcmp(chunk, "1001") == 0){
            strcat(out, "9");
        } else if (strcmp(chunk, "1010") == 0){
            strcat(out, "A");
        } else if (strcmp(chunk, "1011") == 0){
            strcat(out, "B");
        } else if (strcmp(chunk, "1100") == 0){
            strcat(out, "C");
        } else if (strcmp(chunk, "1101") == 0){
            strcat(out, "D");
        } else if (strcmp(chunk, "1110") == 0){
            strcat(out, "E");
        } else if (strcmp(chunk, "1111") == 0){
            strcat(out, "F");
        }
    }
}
void hex_to_bin(const char *hex, char *out){
    out[0] = '\0';

    for (int i = 0; hex[i] != '\0'; i++){
        switch (hex[i]){
            case '0':
                strcat(out, "0000");
                break;
            case '1':
                strcat(out, "0001");
                break;
            case '2':
                strcat(out, "0010");
                break;
            case '3':
                strcat(out, "0011");
                break;
            case '4':
                strcat(out, "0100");
                break;
            case '5':
                strcat(out, "0101");
                break;
            case '6':
                strcat(out, "0110");
                break;
            case '7':
                strcat(out, "0111");
                break;
            case '8':
                strcat(out, "1000");
                break;
            case '9':
                strcat(out, "1001");
                break;
            case 'a':
            case 'A':
                strcat(out, "1010");
                break;
            case 'b':
            case 'B':
                strcat(out, "1011");
                break;
            case 'c':
            case 'C':
                strcat(out, "1100");
                break;
            case 'd':
            case 'D':
                strcat(out, "1101");
                break;
            case 'e':
            case 'E':
                strcat(out, "1110");
                break;
            case 'f':
            case 'F':
                strcat(out, "1111");
                break;
            default:
                strcat(out, "invalid");
                break;
        }
    }
}