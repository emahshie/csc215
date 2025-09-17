3A 10 00   # LDA 10h
47         # MOV B, A
3A 11 00   # LDA 11h
4F         # MOV C, A
16 00      # MVI D, 00h
78         # MOV A, B
91         # SUB C
47         # MOV B, A
14         # INR D
FA 09 00   # JP 0009h (LOOP)
7A         # MOV A, D
32 12 00   # STA 12h
76         # HLT
