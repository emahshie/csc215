3A    # LDA 10h ; Load high value from address 0x10 into A
10
00
47    # MOV B,A ; Store high value in B
3A    # LDA 11h ; Load low value from address 0x11 into A
11
00
4F    # MOV C,A ; Store low value in C
06    # MVI B,xx ; B will be used for current value (but already set)
16    # MVI D,00 ; D = 0, will hold count
00
START_LOOP:
78    # MOV A,B ; Move current value to A
91    # SUB C    ; Subtract low value
47    # MOV B,A  ; Store result in B
FA    # JM END   ; Jump to END if result is negative (sign set)
17
00
14    # INR D    ; Increment count
C3    # JMP START_LOOP
09
00
END:
7A    # MOV A,D  ; Move count to A
32    # STA 12h  ; Store at 0x12
12
00
76    # HLT

===
10:1E # High number = 30 (change as needed)
11:05 # Low number = 5  (change as needed)