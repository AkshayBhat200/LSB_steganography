LSB steganography is used to hide confidential data within a cover image. In this project i use a bitmap image as a cover image to encode a secret message into it . As the method used is LSB steganography ,it is difficult for the human eye to detect any modification in the image after encoding.The project also includes the decoding part.

Use the below command to compile the files:
gcc -Wall *.c  .

use the below command to encode the secret message in secret.txt file into the bitmap image beautiful.bmp:
./a.out -e beautiful.bmp secret.txt  .

After executing this command a new image file named stego_img.bmp will be created in your folder which has the encoded message
use the below command to decode the secret message in stego_img.bmp file and store it in my_decoded_file.txt
./a.out -d stego_img.bmp my_decoded_file.txt  .

If your on windows and you get errors you can use the commands below instead

gcc -Wall *.c 

./a -e beautiful.bmp secret.txt 

./a -d stego_img.bmp my_decoded_file.txt
