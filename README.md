<!-- FUX COLORS - #fcaa68 - #ec243c -->

<img src="./art/logo.svg" width=50%></img>

# Fux


**`Flawless Unambiguous Programming`**

###### Warning: Fux is still in early development.

> Fux uses [`BaseLex`](https://github.com/Fuechs/BaseLex/), and you can too!

## The beautiful alternative for C++ 

- so you don't shoot yourself in the foot (like I do working on Fux)
- with better errors (well, better than just `Segmentation fault`) 
- providing a large standard library


```cpp
#get <core.io>

fib(num: int): int {
    return num < 2 ? num : fib(num-1) + fib(num-2);
}

main(): void {
    num := io.getint("Fibonacci of: ");
    fib(num) >> io.putln();
}
```

> More examples [`here`](#examples).

## Why Fux?

Because.

## Roadmap

- [&check;] `Lexer`
- [...] `Parser`
- [&cross;] `AST Analysis & IR`
- [&cross;] `Optimization`
- [&cross;] `Code Generation`
- [&cross;] `Virtual Machine`
- [&cross;] `Runtime`
- [&cross;] `Standard Library`

## Examples

<details>
    <summary>Hello World</summary>

<br>

```cpp
#get <core.io>

main(): void { 
    io.println("Hello World!");
}
```

</details>

<details>
    <summary>Reading Files</summary>

<br>

```cpp
#get <core.file>

main(): void { 
    filePath := "path/file.txt";
    contents := file.read(filePath);
}
```

</details>

<details>
    <summary>Vectors</summary>

<br>

```cpp
#get <core.vector>

using vector;

main(): void { 
    someArray: vector<int>;
    someArray.push(1);
}
```

</details>

<details>
    <summary>Formatted Print</summary>

<br>

```cpp
#get <core.io>

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

![forthebadge](
    https://forthebadge.com/images/badges/made-with-c-plus-plus.svg
) 