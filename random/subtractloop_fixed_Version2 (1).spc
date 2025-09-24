3A    # LDA 10h ; Load high value
10
00
47    # MOV B,A ; B = high
3A    # LDA 11h ; Load low value
11
00
4F    # MOV C,A ; C = low
16    # MVI D,00 ; D = 0 (count)
00
78    # LOOP: MOV A,B ; A = current value
91    # SUB C        ; A = A - low
F8    # JM END       ; Jump if negative (sign set)
15
00
47    # MOV B,A      ; Store new value in B
14    # INR D        ; D++
C3    # JMP LOOP
09
00
END:
7A    # MOV A,D      ; A = D (count)
32    # STA 12h      ; Store count at 0x12
12
00
76    # HLT

===
10:1E # High = 30
11:05 # Low  = 5