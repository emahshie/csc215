

| STEP | SWITCHES 0-7 | HEX | DESCRIPTION                          |
|------|--------------|-----| -------------------------------------|
|  0   |              |     | RESET                                |
|  1   | 00 111 010   | 3A  | Load A from 0030                     |
|  2   | 00 110 000   | 30  | Low byte                             |
|  3   | 00 000 000   | 00  | High byte                            |
|  4   | 01 000 111   | 47  | Move A to B                          |
|  5   | 00 111 010   | 3A  | Load A from 0040                     |
|  6   | 01 000 000   | 40  | Low byte                             |
|  7   | 00 000 000   | 00  | High byte                            |
|  8   | 1000 0000    | 80  | Add B to A (A = num1 + num2)         |
|  9   | 01 001 111   | 4F  | Move sum to C                        |
| 10   | 00 111 010   | 3A  | Load A from 0050                     |
| 11   | 01 010 000   | 50  | Low byte                             |
| 12   | 00 000 000   | 00  | High byte                            |
| 13   | 10 000 001   | 81  | Add C to A (A = num3 + (num1+num2))  |
| 14   | 00 110 010   | 32  | Store result at 0060                 |
| 15   | 01 100 000   | 60  | Low byte                             |
| 16   | 00 000 000   | 00  | High byte                            |
| 17   | 01 110 110   | 76  | Halt                                 |
