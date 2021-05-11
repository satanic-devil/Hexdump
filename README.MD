# Hexdump

Hexdump implemented using C++

## What is Hexdump
Hexdump is an utility program that displays the content of a binary file in hexadecimal format. This program displays the address, the individual content at the address in hexadecimal format and also the printable character at the end in the location.

![Example Output of Hexdump](https://drive.google.com/file/d/1KMlZxbZ0dMd74ljZLMMn_War48YEXZRt/view?usp=sharing)
## How to Compile
You can use a GCC compiler. use the following command in Linux

```bash
  g++ app.cpp hexdump.h -o hexdump
```

# How to Run
To use Hexdump on any binary file use the following comman
```bash
  ./hexdump binary_file_name
```
