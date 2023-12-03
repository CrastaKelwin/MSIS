;6. Consider a 32-bit number present in 0x40000000. Find the number of ones and zero present in the 32-bit number. 
; Store the result in 0x40000004 and 0x40000008. 
	
	AREA RESET,CODE,READONLY
    ENTRY

MAIN			
	LDR R0, =0x40000000     ;Load the address of value1
    LDR R1, [R0]            ;Store value located at address pointed by R0
    MOV R2, #32             ;Counter set to 31F

JUMP    
	MOVS R1, R1, LSR #1     ;Logical right shift by 1 bit and set carry if carry is generated
    ADDCS R3, R3, #1        ;R3 holds number of ones
    ADDCC R4, R4, #1        ;R4 holds the number of zeros
    SUB R2, R2, #1          ;Decrementing count by 1
    CMP R2, #00             ;Check if counter has reached the msb (32nd bit)
    BNE JUMP    
    LDR R0, =0x40000004     ;Load the address where number of 1s are to be stored
    STR R3, [R0]            ;Store the count of 1s in the address stored in R0
    STR R4, [R0, #4]        ;Store the count of 1s in the address stored in R0, after incrementing location by 4 bytes (32 bits)
    
STOP  B  STOP
    END