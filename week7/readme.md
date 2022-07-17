# 2's Complement and Floats

## 2's Complement

- 2's complement is how we represent negative integers in binary
- It allows us to subtract numbers by simply adding a negative number
- We don't have to design a new subtracting circuit in the CPU
- There's only 1 way to write 0
- See the [flowcharts](2's%20Complement.pdf) for conversion

## IEEE 754 Floating Point

- First bit is the sign
- Next 8 bits is the biased exponent (actual exponent + 127)
- Last 23 bits is the mantissa
- Conversions are properly best demonstrated by rewatching the tutorial (or finding another source). It's difficult to convey what to do in text.
