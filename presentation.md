## **Memory Map**
| Address | Value | Description        |
|---------|-------|---------------------|
| 0030    | 34    | Number 1, low byte  |
| 0031    | 12    | Number 1, high byte |
| 0040    | 78    | Number 2, low byte  |
| 0041    | 56    | Number 2, high byte |
| 0050    | 00    | (Result, low byte)  |
| 0051    | 00    | (Result, high byte) |

- **Number 1:** 0x1234 (low byte 0x34 at 0x0030, high byte 0x12 at 0x0031)
- **Number 2:** 0x5678 (low byte 0x78 at 0x0040, high byte 0x56 at 0x0041)
- **Result:** Will be stored at 0x0050/0x0051

| Addr  | Value | Switches (binary) | Instruction      | Description                    |
|-------|-------|-------------------|------------------|--------------------------------|
| 0100  | 3A    | 0011 1010         | LDA 0030         | Load low byte of num1 into A   |
| 0101  | 30    | 0011 0000         |                  | Address low byte               |
| 0102  | 00    | 0000 0000         |                  | Address high byte              |
| 0103  | 47    | 0100 0111         | MOV B,A          | Copy A to B                    |
| 0104  | 3A    | 0011 1010         | LDA 0040         | Load low byte of num2 into A   |
| 0105  | 40    | 0100 0000         |                  | Address low byte               |
| 0106  | 00    | 0000 0000         |                  | Address high byte              |
| 0107  | 80    | 1000 0000         | ADD B            | Add B to A                     |
| 0108  | 4F    | 0100 1111         | MOV C,A          | Store sum of low bytes in C    |
| 0109  | 3A    | 0011 1010         | LDA 0031         | Load high byte of num1 into A  |
| 010A  | 31    | 0011 0001         |                  | Address low byte               |
| 010B  | 00    | 0000 0000         |                  | Address high byte              |
| 010C  | 47    | 0100 0111         | MOV B,A          | Copy A to B                    |
| 010D  | 3A    | 0011 1010         | LDA 0041         | Load high byte of num2 into A  |
| 010E  | 41    | 0100 0001         |                  | Address low byte               |
| 010F  | 00    | 0000 0000         |                  | Address high byte              |
| 0110  | 88    | 1000 1000         | ADC B            | Add B to A plus carry          |
| 0111  | 57    | 0101 0111         | MOV D,A          | Store sum of high bytes in D   |
| 0112  | 32    | 0011 0010         | STA 0051         | Store high result              |
| 0113  | 51    | 0101 0001         |                  | Address low byte               |
| 0114  | 00    | 0000 0000         |                  | Address high byte              |
| 0115  | 79    | 0111 1001         | MOV A,C          | Copy low result to A           |
| 0116  | 32    | 0011 0010         | STA 0050         | Store low result               |
| 0117  | 50    | 0101 0000         |                  | Address low byte               |
| 0118  | 00    | 0000 0000         |                  | Address high byte              |
| 0119  | 76    | 0111 0110         | HLT              | Halt program                   |
