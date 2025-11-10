; ASCII CHARACTERS

CR      EQU     0DH             

LF      EQU     0AH             

CTRLZ   EQU     1AH            

; CP/M BDOS FUNCTIONS

RCONF   EQU     1               

WCONF   EQU     2              

RBUFF   EQU     10              

; CP/M ADDRESSES

RBOOT   EQU     0               

BDOS    EQU     5               

TPA     EQU     100H            

        ORG     TPA             

START:  LXI     SP,STAK         

; MAIN PROGRAM - ADD TWO 3-DIGIT NUMBERS

MAIN:   CALL    TWOCR           ; DOUBLE SPACE

        CALL    SPMSG

        DB      'ADD 3 Digit Numbers',0

        CALL    TWOCR

        ; GET FIRST NUMBER

        CALL    SPMSG

        DB      'ENTER NUMBER: ',0

        CALL    GETNUM          ; GET NUMBER INTO HL

        SHLD    NUM1            ; SAVE FIRST NUMBER

        ; GET SECOND NUMBER

        CALL    SPMSG

        DB      'ENTER SECOND NUMBER: ',0

        CALL    GETNUM          ; GET NUMBER INTO HL

        SHLD    NUM2            ; SAVE SECOND NUMBER

        ; ADD THE NUMBERS

        LHLD    NUM1            ; LOAD FIRST NUMBER

        XCHG                    ; MOVE TO DE

        LHLD    NUM2            ; LOAD SECOND NUMBER

        DAD     D               ; HL = HL + DE

        SHLD    RESULT          ; SAVE RESULT

        ; DISPLAY RESULT

        CALL    CCRLF

        CALL    SPMSG

        DB      'SUM: ',0

        LHLD    RESULT

        CALL    PRTNUM          ; PRINT THE NUMBER

        ; ASK TO CONTINUE

        CALL    CCRLF

        CALL    SPMSG

        DB      'AGAIN?',0

        CALL    GETYN

        JZ      MAIN            ; IF YES, DO ANOTHER

        ; EXIT TO CP/M

        JMP     RBOOT

; GET A DECIMAL NUMBER FROM CONSOLE (0-999)

; RETURNS VALUE IN HL

GETNUM: CALL    CIMSG           ; GET INPUT LINE

        CALL    CCRLF

        LXI     H,INBUF+2       ; POINT TO FIRST CHARACTER

        LXI     D,0             ; CLEAR RESULT IN DE

GNUM1:  MOV     A,M             ; GET CHARACTER

        ORA     A               ; CHECK FOR END

        JZ      GNUM2           ; DONE IF ZERO

        CPI     '0'             ; CHECK IF DIGIT

        JC      GNUM1X          ; SKIP IF NOT

        CPI     '9'+1

        JNC     GNUM1X          ; SKIP IF NOT

        ; MULTIPLY DE BY 10

        PUSH    H               ; SAVE POINTER

        PUSH    D               ; SAVE CURRENT RESULT

        MOV     H,D             ; COPY DE TO HL

        MOV     L,E

        DAD     H               ; HL = DE \* 2

        DAD     H               ; HL = DE \* 4

        POP     D               ; RESTORE ORIGINAL DE

        PUSH    D               ; SAVE IT AGAIN

        DAD     D               ; HL = DE \* 5

        DAD     H               ; HL = DE \* 10

        POP     D               ; CLEAN UP STACK

        XCHG                    ; RESULT TO DE

        ; ADD DIGIT TO RESULT

        POP     H               ; RESTORE POINTER

        MOV     A,M             ; GET DIGIT CHARACTER

        SUI     '0'             ; CONVERT TO BINARY

        ADD     E               ; ADD TO LOW BYTE

        MOV     E,A

        MVI     A,0

        ADC     D               ; ADD CARRY TO HIGH BYTE

        MOV     D,A

GNUM1X: INX     H               ; NEXT CHARACTER

        JMP     GNUM1

GNUM2:  XCHG                    ; RESULT TO HL

        RET

; PRINT  FROM HL 

PRTNUM: LXI     D,NUMBUF+5      ; POINT TO END OF BUFFER

        MVI     B,0             ; DIGIT COUNTER

PRTN1:  LXI     D,10            ; DIVISOR

        CALL    DIVIDE          ; HL/ 10, A = rem

        ADI     '0'             ; CONVERT TO ASCII

        PUSH    PSW             ; SAVE DIGIT

        INR     B               ; COUNT DIGITS

        MOV     A,H             ; CHECK IF DONE

        ORA     L

        JNZ     PRTN1           ; CONTINUE IF NOT ZERO

PRTN2:  POP     PSW             ; GET DIGIT

        CALL    CO              ; PRINT IT

        DCR     B               ; COUNT DOWN

        JNZ     PRTN2

        RET

; DIVIDE HL BY 10, RESULT IN HL, REMAINDER IN A

DIVIDE: PUSH    B

        PUSH    D

        LXI     B,0             ; BC WILL HOLD RESULT

        LXI     D,10            ; DIVISOR

DIV1:   MOV     A,H             ; Check high byte first

        ORA     A               ; Is H zero?

        JNZ     DIV2            ; If not, HL >= 256, continue dividing

        MOV     A,L             ; Check low byte

        CMP     E               ; Compare with 10

        JC      DIV3            ; If L < 10, done

DIV2:   MOV     A,L             ; SUBTRACT 10 FROM HL

        SUB     E

        MOV     L,A

        MOV     A,H

        SBB     D

        MOV     H,A

        INX     B               ; INCREMENT RESULT

        JMP     DIV1

DIV3:   MOV     A,L             ; REMAINDER TO A

        MOV     H,B             ; RESULT TO HL

        MOV     L,C

        POP     D

        POP     B

        RET

; STORAGE FOR NUMBERS

NUM1:   DW      0

NUM2:   DW      0

RESULT: DW      0

NUMBUF: DS      6
