3A    # LDA 10h ; Load high number from memory (address 0x10) into A
10
00
47    # MOV B,A ; Store high number in B
3A    # LDA 11h ; Load low number from memory (address 0x11) into A
11
00
4F    # MOV C,A ; Store low number in C
16    # MVI D,00h ; Initialize count (D) to 0
00
78    # MOV A,B ; Move current high value into A
91    # SUB C ; Subtract low from high (A = A - C)
47    # MOV B,A ; Store new value back in B
14    # INR D ; Increment count
FA    # JP LOOP ; Jump to loop if sign flag is not set (A >= 0)
0A
00
7A    # MOV A,D ; Move count into A
32    # STA 12h ; Store count in memory (address 0x12)
12
00
76    # HLT ; Halt

===
10:1E # High number (0x1E = 30 decimal)
11:05 # Low number (0x05 = 5 decimal)