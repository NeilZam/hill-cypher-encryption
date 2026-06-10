# Hill Cipher Encryption

A cryptography application written in C that encrypts plaintext using the Hill Cipher algorithm. The program reads a key matrix and a plaintext file, applies matrix-based encryption using modular arithmetic, and outputs the key matrix, processed plaintext, and resulting ciphertext.

---

## How It Works

The Hill Cipher is a classical encryption technique that treats blocks of plaintext as vectors and multiplies them against a key matrix under modulo 26. Each block of letters is converted to numbers (a=0, z=25), multiplied by the key matrix, and converted back to letters. The key size determines the block size used during encryption.

---

## Getting Started

### Prerequisites

- GCC compiler
- Linux or Unix-based terminal (tested on Eustis)

### Compile

```bash
gcc -o hill hill.c
```

### Run

```bash
./hill <key_file> <plaintext_file>
```

- `<key_file>` — a text file containing the matrix size followed by the matrix values
- `<plaintext_file>` — a text file containing the plaintext to encrypt (only alphabetic characters are processed)

---

## File Format

**Key file example (2x2 matrix):**
```
2
3 3
2 5
```

**Plaintext file example:**
```
hello world
```

---

## Sample Output

```
Key matrix:
   3   3
   2   5

Plaintext:
helloworld

Ciphertext:
rudmsikshr
```

Non-alphabetic characters are stripped from the plaintext. If the plaintext length is not a multiple of the key size, it is padded with the letter 'x'.

---

## Concepts Used

- Cryptography
- Matrix Operations
- Modular Arithmetic
- File Input/Output
- Dynamic Memory Allocation

## Technologies

- C
- GCC
- Command Line

---

## Notes

- Supports key matrices up to 9x9
- Input files use simple 8-bit ASCII encoding
- All execution commands have been tested on Eustis

---

## What I Learned

This project introduced classical encryption techniques and deepened my understanding of matrix-based algorithms, modular arithmetic, and file processing in C.
