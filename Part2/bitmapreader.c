#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


FILE* file_reader = NULL;
long long file_length;
unsigned char* file_buffer = NULL;
BITMAPFILEHEADER* bitmap_file_header = NULL;
BITMAPV5HEADER* bitmapv5_header = NULL;
int main(int argc, char** argv)
{
    if(argc < 2)
    {   
        printf("error: Type an input file name to read.");
        exit(-1);
    }
    file_reader = fopen(argv[1], "rb");

    if(!file_reader)
    {
        printf("error: Fİle cannot be open to read.");
        exit(-2); 
    }

    fseek(file_reader, 0, SEEK_END);   
    file_length = ftell(file_reader); 

    file_buffer = malloc(file_length);
    
    fseek(file_reader, 0, SEEK_SET);
    fread(file_buffer, sizeof(unsigned char), file_length, file_reader);

    bitmap_file_header = (BITMAPFILEHEADER*)file_buffer;

}