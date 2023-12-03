
	AREA program,CODE,READONLY
    ENTRY
 /*   
    LDR R0,=0x40000000      ; Register Rd
    LDR R0,[R0]
    MOV R1,#32            ; Counter register
label
        MOVS R0,R0,LSR #0x1  ; Logical right shift of number
        ADDCS R3,R3,#1      ; R3 holds number of ones
        ADDCC R4,R4,#1      ; R4 holds number of zeros
        SUB R1,R1,#1        ; decrementing counter value
        CMP R1,#00
        BNE label
        
        LDR R5,=0x40000004
        STR R3,[R5]
        LDR R6,=0x40000008
        STR R4,[R6]
        
        END
			*/