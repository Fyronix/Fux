<!--    colors 

"orange":   #fcaa68 (sandy brown)
"red":      #ec243c (imperial red)
"grey":     #595959 (davys grey)
"white":    #e0f2e9 (honeydew)
"purple":   #a390e4 (lavender floral)

-->

<div align="center">
<img width="150" src="./assets/fux-material-icon-435.svg" />

## Flawless Unambiguous Programming

[![version](https://img.shields.io/badge/pre--alpha-fcaa68?colorA=151515&style=for-the-badge)](./docs/state.md)
[![Apache License v2.0](https://img.shields.io/badge/Apache_License_v2.0-fcaa68?colorA=151515&style=for-the-badge)](./LICENSE)
[![C++][cpp-badge]](./docs/state.md)
[![LLVM][llvm-badge]](./docs/state.md)

</div>
 
###### Simple Hello World Program

```rust
main(argc: u64, argv: **c8): i64 {
    puts "Hello World!\n";
    return 0;
}
```

<div align="center">
<a href="./docs/state.md">Language State</a> ·
<a href="./docs/CONTRIBUTING.md">Contributing</a> ·
<a href="./docs/README.md">Documentation</a> ·
<a href="./docs/examples.md">Examples</a>
</div>
<br>

> __Warning__ \
> Please note that Fux is still in early development. \
> As of now only MacOS and Linux will be supported.

## A Modern, Flexible Programming Language for All

###### A Versatile and Innovative Language

Fux is a modern and flexible programming language, perfect for use in a variety of domains by both novice and expert developers. With its efficient use of LLVM, it provides performance similar to C++, while being portable and running on a wide range of platforms.[^1]

- **Large Core Package** \
    Fux offers a comprehensive standard library, known as the Core Package, which includes features such as a string type, buffered console I/O, file I/O, mathematics and arithmetic operations, algorithms, key-value maps and dynamic pointers.[^1][^2][^3]
- **Easy to Learn and Use** \
    For new programmers, Fux offers a safe and intuitive programming environment, with features like built-in dynamic arrays and secure memory management. Experienced C/C++ developers will find the programming environment familiar, with added features and improvements over C++.
- **Readable and Streamlined Syntax** \
    The syntax of Fux is designed to be readable and easy to understand, with a focus on seamless integration of different aspects of the language. This is achieved through the use of "pipe" / "move" operators (`<<` and `>>`), as well as the ability to define functions and variables without any keywords.[^3][^4]
- **Eliminating Common C++ Errors** \
    Fux addresses common issues with C++ by eliminating potential sources of error, such as memory leaks, through its secure memory management. Its readable syntax and intuitive integration of different language elements also reduce the likelihood of bugs, making it easier for developers to write high-quality code.

> __Note__
> 1. Fux may have limited adoption and support compared to more established programming languages.
> 2. Compatibility with other (programming) languages or technologies may be limited, which could restrict its use in certain domains.
> 3. New bugs or security issues may arise as Fux is a new prorgamming language.
> 4. As an ongoing development project, Fux may introduce new features or updates that could impact its performance, stability, or compatibility.
> 5. Fux may have fewer resources available, such as documentation, forums, or tutorials, compared to more established programming languages.

[^1]: The usage of certain features may result in decreased program performance and slower compile times.
[^2]: The inclusion of these features is not guaranteed in future versions of the language.
[^3]: Further details can be found [here](./docs/).
[^4]: Provided automatic typing is used.

## Getting Started

The compiler for this language is not finished yet. \
You can compile the source code by running `make` and then run the executeable with `./fux <filepath>`. It will output the parsed tokens and AST.

[llvm-badge]: https://img.shields.io/badge/LLVM-4c1717?logo=llvm&logoColor=white&style=for-the-badge
[cpp-badge]: https://img.shields.io/badge/C++-1a3b63?logo=cplusplus&logoColor=white&style=for-the-badge