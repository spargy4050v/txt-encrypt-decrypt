# Text Encryption and Decryption Tool

## Overview
This C program implements a simple text encryption and decryption system that operates on character frequency. The program reads text from a file, encrypts it into another file, and then decrypts it into a third file.

## Features
- Text input and storage in a file
- Character-by-character encryption based on frequency
- Decryption of encrypted text
- File I/O operations

## How It Works
1. **Writing**: The program accepts text input from the user and writes it to a file (`test.txt`)
2. **Encryption**: Each alphabetic character in the text is encrypted by shifting it forward by its frequency count in the text
3. **Reading**: The encrypted text can be read from the file (`encrypt.txt`)
4. **Decryption**: The encrypted text is decrypted by shifting each character backward by its frequency count in the encrypted text and written to another file (`decrypt.txt`)

## Limitations
As noted in the program warnings:
- Decryption fails if the data contains the following symbols: `^ _ [ ] \ { } |`
- It also fails for cases where different characters encrypt to the same character:
  - Example: In "aab", count(a)=2, a+2=c, count(b)=1, b+1=c
  - Encrypt: "ccc" → Decrypt: ambiguous result

## Usage
1. Compile the program:
   ```bash
   gcc -o encrypt_decrypt code.c
2. Run the executable:
   ```bash
   ./encrypt_decrypt
3. When prompted, enter the text you want to encrypt
4. The program will:
    - Write your text to `test.txt`
    - Encrypt it to `encrypt.txt` and display the encrypted text
    - Decrypt it to `decrypt.txt` and display the decrypted text
## Functions
- `write(FILE*)`: Accepts user input and writes to a file
- `read(FILE*)`: Reads and displays file contents
- `freq(char, FILE*)`: Calculates the frequency of a character in a file
- `encrypt(FILE*, FILE*)`: Encrypts contents from one file to another
- `decrypt(FILE*, FILE*)`: Decrypts contents from one file to another
## Example
```bash
Warning: Decryption fails if the data contains the following symbols:
_ [ ] { } |
It also fails for cases like Ex: aab
count(a)=2, a+2=c, count(b)=1, b+1=c
Encrypt: ccc Decrypt: ...

Enter data to encrypt
Hi I'm encrypter
Encryption is completed
Reading the data
Ij J'n godtzqugt
Decryption is completed
Reading the data
Hi I'm encrypter 
```
## Requirements
- Standard C compiler (e.g., GCC)
- Standard I/O library
## Files Created
- `test.txt`: Contains the original text
- `encrypt.txt`: Contains the encrypted text
- `decrypt.txt`: Contains the decrypted text
### Note
This encryption algorithm is for educational purposes only and not suitable for securing sensitive information.
