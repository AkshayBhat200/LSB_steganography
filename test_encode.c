/*
Name:Akshay Bhat M
Date:24/12/2023
Description:Steganography-This C program implements a basic LSB (Least Significant Bit) image steganography technique. LSB steganography involves hiding information in the least significant bits of the pixel values of an image, here we have done it on a bitmap image.
Input:./a -e beautiful.bmp secret.txt stego.bmp
Output:------------------Selected encoding--------------------------
Read and validate encode arguments is a success
Opened files successfully
width = 1024
height = 768
Checked capacity successfully
Copied bmp header successfully
Encoded magic string successfully
Encoded secret file extension size successfully
Encoded secret file extension successfully
Encoded secret file size successfully
Encoded secret file data successfully
Copied remaining data successfully
------Steganography done successfully check stego.bmp file for the encoded image------
Input:./a -d stego.bmp decode.txt
Output:-------------Selected decoding------------------------
Read and validate decode arguments is a success
Files opened successfully
Decoded magic string Successfully
Decoded file extension size Succesfully
Decoded Secret File Extension Succesfully
Decoded secret file size Successfully
Decoded secret file data Successfully
------Decoding completed check decode.txt file for the secret message------
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{
    // Function call for check operation type
    if (check_operation_type(argv) == e_encode)
    {
        printf("------------------Selected encoding--------------------------\n");
        // Declare structure variable
        EncodeInfo encInfo;
        // Read and validate encode arguments
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and validate encode arguments is a success\n");
            
            // Function call for encoding
            if (do_encoding(&encInfo) == e_success)
            {
                printf("------Steganography done successfully check stego.bmp file for the encoded image------\n");
            }
            else
            {
                printf("Failed to encode\n");
                return e_failure;
            }
        }
        else
        {
            printf("Read and validate encode arguments is a failure\n");
            return e_failure;
        }
    }
    // Function call for check operation type
    else if (check_operation_type(argv) == e_decode)
    {
        printf("-------------Selected decoding------------------------\n");
        // Declare structure variables
        DecodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == d_success)
        {
            printf("Read and validate decode arguments is a success\n");
            // Function call for do decoding
            if (do_decoding(&decInfo) == d_success)
            {
                printf("-----Decoding completed check decode.txt file for the secret message------ \n");
            }
            else
            {
                printf("Failed to decode\n");
                return e_failure;
            }
        }
        else
        {
            printf("Read and validate decode arguments is a failure\n");
            return e_failure;
        }
    }
    else
    {
        printf("Invalid option\nKindly pass for\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }
    return 0;
}
