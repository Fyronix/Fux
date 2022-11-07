<!--    colors 

"orange":   #fcaa68 (sandy brown)
"red":      #ec243c (imperial red)
"grey":     #595959 (davys grey)
"white":    #e0f2e9 (honeydew)
"purple":   #a390e4 (lavender floral)

-->

<img src="./art/fux-material-icon.svg" width=50%></img>

![total lines](https://aschey.tech/tokei/github/fuechs/fux?color=a390e4&style=for-the-badge)
![top language](https://img.shields.io/github/languages/top/fuechs/fux?color=fcaa68&style=for-the-badge)
![version](https://img.shields.io/badge/version-alpha-ec243c?style=for-the-badge)
---

**`Flawless Unambiguous Programming`**

###### Warning: Fux is still in early development.

## The beautiful alternative for C++ 

- so you don't shoot yourself in the foot (like I do working on Fux)
- with better errors (well, better than just `Segmentation fault`) 
- providing a large standard library


```cpp
get core.io;

using io;

fib(num: i32): i32 {
    if (num < 2) 
        return num;
    return fib(num - 1) + fib(num - 2);
}

main(): void {
    num := getint("Fibonacci of: ");
    fib(num) >> putln();
}
```

> More examples [`here`](#examples).

## Why Fux?

To be a valid alternative to C++ to experienced developers and the go-to language for newbies looking into learning their first programming language, Fux is very flexible.

While it is possible to program in a pythonic style,

```cpp
name := "Fuechs"; // automatic typing
```

Legacy C developers can find strict typing and already known features like pointers very useful.

```cpp
number: float = 1.0;
address -> float = &number;
```

> As already mentioned above, Fux ships with a large standard library, ready to use.
> It includes, but is not limited to, Utility, (File) IO and Maths. 

## Setup

Since Fux is still in an early development stage, there are no setup methods yet.

## Roadmap

- [&check;] `Error`
- [&check;] `Lexer`
- [...] `Parser`
- [&cross;] `AST Analysis`
- [&cross;] `Optimization`
- [&cross;] `Code Generation`
- [&cross;] `Virtual Machine`
- [...] `Runtime`
- [...] `Syntax`
- [...] `Standard Library`

## Examples

<details>
    <summary>Hello World</summary>

<br>

```cpp
get core.io;

main(): void { 
    io.putln("Hello World!");
}
```

</details>

<details>
    <summary>Reading Files</summary>

<br>

```cpp
get core.file;
get core.io;

using file;

main(): void { 
    filePath := "path/file.txt";
    file := File(filePath, 'r');
    if (!?file) // check if file does not (-> !) exist (-> ?)
        io.err(1, "Could not open "+filePath);
    contents := file.read();
}
```

</details>

<details>
    <summary>Arrays</summary>

<br>

```cpp
main(): void { 
    someArray: i32[];
    someArray[] << 1; // someArray = {1}
    someArray[] << 3; // someArray = {1, 3}
}
```

</details>

<details>
    <summary>Formatted Print</summary>

<br>

```cpp
get core.io;

main(): void {
    res := 1;
    io.printf("Result: %i", res);
}
```

</details>

<details>
    <summary>Loops</summary>

<br>

```cpp
main(): void {

    string := "Some String";

    /// For-In Loop

    for (c: char) in (string) // {
        doSomething();
    // }

    /// For Loop

    for (i: u8; i < 10; ++i) // {
        doSomething();
    // }

    /// While Loop

    while (true) // {
        doSomething();
    // }

}
```

</details>

---
