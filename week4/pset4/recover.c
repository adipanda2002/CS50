#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t byte;

#define size_of_block 512
#define size_of_file_name 8

bool new_jpeg(byte buffer[]);
 
int main(int argc, char *argv[])
{
    if (argc != 2) //reminds user of correct usage
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *openfile = fopen(argv[1], "r");
    if (openfile == NULL)
    {
        printf("Could not open file\n");
        return 1;
        // error message when forensic image cannot be opened
    }
    
    byte buffer[size_of_block];
    
    int file_counter = 0;
    bool found_jpeg1 = false;
    FILE *closefile;
    // reads into the buffer
    while (fread(buffer, size_of_block, 1, openfile))
    {
        if (new_jpeg(buffer)) //check if a new jpeg has started
        {
            if (!found_jpeg1) 
            {
                found_jpeg1 = true;
            }
            else
            {
                fclose(closefile);
            }
            
            // create a new file for the next jpeg
            char filename[size_of_file_name];
            sprintf(filename, "%03i.jpg", file_counter++);
            closefile = fopen(filename, "w");
            if (closefile == NULL)
            {
                return 1;
            }
            fwrite(buffer, size_of_block, 1, closefile);
           
        }
        else if (found_jpeg1)
        {
            fwrite(buffer, size_of_block, 1, closefile);
            //continue to write the previous file 
        }
        
        
    }
    fclose(closefile);
    fclose(openfile);
    //close files after use
 
}

//function to determine whether a jpeg is present
bool new_jpeg(byte buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
