;8. Find whether the 32-bit number is negative or a positive number.
	AREA RESET, CODE, READONLY
    ENTRY
MAIN
    LDR R0, NUM         ; Load the register R0 with the number
    LDR R1, COMPARE     ; Load R1 with compare variable of value 0x80000000 to check for negative number
    AND R1, R1, R0      ; And R1(compare variable) and R0(actual value)
    CMP R1, #0          ; Check if R1=0
    BEQ POS             ; If R1=0 the number is positive hence branch to POS
    MOV R0, #1          ; If number is negative make R0=1
    B STOP
POS
    MOV R0, #0          ; If number is positive make R0=0 
STOP B STOP
    
NUM DCD 0x82345678
COMPARE DCD 0x80000000
    
	END