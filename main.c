#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h> // For atoi()

void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement(int32_t n, char *out);
void to_twos_complement(int32_t n, char *out);

int main(){
    FILE *file = fopen("a2_test.txt", "r");
    if (file == NULL){
        printf("Error: Couldn't open file\n");
        return 1;
    }
    FILE *resultfile = fopen("output.txt", "w");
    if (resultfile == NULL){
        printf("Error: Couldn't create output.txt\n");
        fclose(file);
        return 1;
    }
    
    char line[256];
    char result[100]; // Changed from 65 to 100 for assignment 2
    int testNum=1;
    int passedTests=0;
    while (fgets(line, sizeof(line), file) !=NULL){
        line[strcspn(line, "\n")] = '\0';
        if (line[0]=='#' || line[0]=='\0'){
            continue;
        }

        // New variables for assignment 2
        char function[50];
        char input_str[100];
        char expected_str[100];

        // Updated for new format
        if(sscanf(line, "%49s %99s %99s", function, input_str, expected_str) == 3){
            // New if/else blocks for new assignment 6 functions
            if (strcmp(function, "oct_to_bin") == 0){
                oct_to_bin(input_str, result);
            } else if (strcmp(function, "oct_to_hex") == 0){
                oct_to_hex(input_str, result);
            } else if (strcmp(function, "hex_to_bin") == 0){
                hex_to_bin(input_str, result);
            } else if (strcmp(function, "to_sign_magnitude") == 0){ // Start using atoi() for part 2 functions
                int32_t num = atoi(input_str); 
                to_sign_magnitude(num, result);
            } else if (strcmp(function, "to_ones_complement") == 0){
                int32_t num = atoi(input_str);
                to_ones_complement(num, result);
            } else if (strcmp(function, "to_twos_complement") == 0){
                int32_t num = atoi(input_str);
                to_twos_complement(num, result);
            }
            
            int passed = (strcmp(result, expected_str) == 0);
            if (passed){
                passedTests++;
            }
            
            // Updated sprintf to show string input
            char output[512];
            sprintf(output, "Test %d: %s(\"%s\") -> Expected: \"%s\", Got: \"%s\" [%s]", testNum, function, input_str, expected_str, result, passed ? "PASS":"FAIL");
            printf("%s\n", output);
            fprintf(resultfile, "%s\n", output);
            testNum++;
        }
    }
    printf("Summary: %d/%d tests passed\n", passedTests, testNum-1);
    fprintf(resultfile, "Summary: %d/%d tests passed\n", passedTests, testNum-1);
    fclose(file);
    fclose(resultfile);
    
    return 0;
}