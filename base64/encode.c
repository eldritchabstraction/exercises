#include <stdio.h>

const char base64_map[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode(char* p_input, char* p_output) {
    int index = 0;
    // 1 of 4
    index = p_input[0] >> 2;
    p_output[0] = base64_map[index];

    // 2 of 4
    index = ((p_input[0] & 0x03) << 4) | ((p_input[1] & 0xF0) >> 4);
    p_output[1] = base64_map[index];

    // 3 of 4
    index = ((p_input[1] & 0x0F) << 2) | ((p_input[2] & 0xC0) >> 6);
    p_output[2] = base64_map[index];

    // 4 of 4
    index = p_input[2] & 0x3F;
    p_output[3] = base64_map[index];
}

int main(void) {
    // allocate memory for a 3 char input and a 4 char output
    char input[3] = {0x00, 0x45, 0xF2};
    char output[5] = "0000";

    printf("Initial output = %s\n", output);

    encode(input, output);

    printf("Final output = %s\n", output);
}
