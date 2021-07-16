#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t make_nbo(char* filename){
    FILE *fd = fopen(filename, "rb");
    if (fd == NULL) {
        printf("File %s not exists", filename);
        return -1;
    }

    uint32_t res;
    fread(&res, sizeof(uint32_t), 1, fd);
    fclose(fd);

    return ntohl(res);
}

int main(int argc, char* argv[]){

    if (argc != 3){
        printf("Usage: %s <file1.bin> <file2.bin>", argv[0]);
        return -1;
    }

    uint32_t num1 = make_nbo(argv[1]);
    uint32_t num2 = make_nbo(argv[2]);
    uint32_t res = num1+num2;

    printf("%d(%#x) + %d(%#x) = %d(%#x)\n", num1, num1, num2, num2, res, res);

    return 0;
}
