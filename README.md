# Huffman Encoder and Decoder in C++

This is a C++ implementation of the Huffman coding algorithm that:

- Reads a text string from an input file (`input.txt`)
- Builds a Huffman Tree based on character frequencies
- Encodes the text into a binary string and saves it to `encoded.bin`
- Decodes the binary string back to the original text and saves it to `decoded.txt`

## How it works

1. The program reads the entire contents of `input.txt`.
2. It calculates the frequency of each character and builds the Huffman Tree.
3. It generates Huffman codes for each character and encodes the text.
4. The encoded string (a sequence of '0' and '1' characters) is saved to `encoded.bin`.
5. The program then decodes this encoded string back to the original text.
6. The decoded text is saved to `decoded.txt`.

## Files

- `input.txt` : Input file containing the text to encode.
- `encoded.bin` : Output file containing the encoded binary string.
- `decoded.txt` : Output file containing the decoded text, which should match the input.
