#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper use
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file_in = fopen(argv[1], "r");
    if(!file_in)
    {
        printf("Error while opening file.");
        return 1;
    }

    typedef uint8_t byte;

    byte* buff = malloc(sizeof(byte)*512);
    char* outname = malloc(sizeof(char)*8);
    int t = 0, amount;
    FILE *file_out = NULL;

    // reads the file in chunks of 512 bytes.
    while((amount = fread(buff,sizeof(byte),512,file_in)) != 0)
    {
        printf("Reading block...\n");
        //checks for jpeg signature
        int jpgsign = (buff[0]==0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3]&0xe0) == 0xe0);

        //when a jpeg signature is found
        if((jpgsign) && t == 0)
        {
            sprintf(outname,"%03i.jpg",t);
            file_out = fopen(outname, "a");
            fwrite(buff,sizeof(byte),amount,file_out);
            t++;
            continue;
        }
        else if(file_out && jpgsign)
        {
            fclose(file_out);
            sprintf(outname,"%03i.jpg",t);
            file_out = fopen(outname, "a");
            fwrite(buff,sizeof(byte),amount,file_out);
            t++;
            continue;
        }
        else if(!file_out){
            continue;
        }
        fwrite(buff,sizeof(byte),amount,file_out);

    }
    fclose(file_in);
    free(buff);
    free(outname);
}
