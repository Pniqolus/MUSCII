# MUSCII
**M**odernized and **U**tilitarian **S**tandard **C**ode for **I**nformation **I**nterchange, pronounced "musky" (Probably needs a better name).

A modern alternative for ASCII that no one asked for...

![MUSCII](images/MUSCII.png)

## Brief Overview
 * All of the non-control ASCII characters were preserved (except for the 'DEL' character)
 * All C escape codes were preserved
 * Every non-shift character is present within the first 64 positions, with every shift character present in the last 64.
 * Any shift operation can be performed using a logical OR with the number 64 (i.e. one bit flip).
 * The control characters are directly opposite of the first 8 decimal numbers (0-7).
 * All base conversions up to base 36 are trivial, requiring only a cast operation.

---
Please give a star if you like the idea ... Please ...
