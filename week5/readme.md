# Week 5

## Integer Base Conversion

This week is about number representation and conversions between various bases. As such, it's probably best demonstrated by rewatching the tutorial. Here are some basic tips:

- To go from decimal to hex or octal, first convert it to binary
- To convert from binary to hex:
  - From right to left, group the bits in groups of 4
  - You can pad with 0s on the left if you don't have enough to make a group of 4
  - Convert each group of 4 to a hex digit individually
- To convert from binary to octal:
  - Do the same thing as hex except with groups of 3

## Bitwise Operations

The bitwise operations that we use are:

- AND (`&`)
- OR (`|`)
- XOR (`^`)
- NOT (`~`)
- Left shift (`<<`)
- Right shift (`>>`)

Please see the full truth tables in [drawings.pdf](drawings.pdf). Useful rules we derive from the truth tables are:

- `x & 0 = 0`, anything ANDed with 0 is 0. This is useful for forcing bits to be 0.
- `x & 1 = x`, anything ANDed with 1 is itself. This is useful in conjunction with the above to not change bits when ANDing.
- `x | 1 = 1`, anything ORed with 1 is 1. This is useful for forcing bits to be 1.
- `x | 0 = x`, anything ORed with 0 is itself. This is useful in conjunction with the above to not change bits when ORing.
- `x ^ 1 = ~x`, anything XORed with 1 is the opposite of itself. This is useful for toggling bits.
- `x ^ 0 = x`, anything XORed with 0 is itself. This is useful in conjunction with the above to not change bits when XORing.

## Random Things to Note

- It's preferable to convert binary literals into hex when writing C.
- C number literals are 32 bits by default. You must cast the literal if you want to do bit operations in larger bit widths.
- When doing bitwise operations (especially shifting), ensure you use *unsigned* data types. Shifting signed data types is implementation defined (depends on the compiler).
