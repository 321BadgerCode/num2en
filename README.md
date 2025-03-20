# Number to English Words Converter

## Description
This is a simple C++ program that takes a positive number as a command-line argument and outputs its English representation. For example, an input of `100` will result in `One Hundred`.

## Compilation
To compile the program, use the following command:

```sh
g++ ./main.cpp -o number_to_english
```

## Usage
Run the program with a positive number as an argument:

```sh
./number_to_english 100
```

### Example Output
```sh
$ ./number_to_english 100
One Hundred
```

## Requirements
- A C++ compiler (e.g., `g++`)
- The input number must be a positive integer

## Notes
- This program only supports positive integers.
- It handles standard number formatting up to a reasonable limit (e.g., thousands, millions, etc.).

## License
[MIT](LICENSE)