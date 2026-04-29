# 常见报错
1. runtime error: addition of unsigned offset to 0x502000000130 overflowed to 0x502000000128 (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior
vector 下标越界（负数下标导致无符号溢出）
2. AddressSanitizer: heap-buffer-overflow on address ...
READ of size 4 ...
heap-buffer-overflow（数组下标越界）
