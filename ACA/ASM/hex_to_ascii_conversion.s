;9. Convert a given number from 0x40000000 hex value to ASCII.
	AREA PROGRAM,CODE,READONLY
    ENTRY
MAIN
    LDR R0,=0x40000000   ; Load the base address with R0=0x40000000
    LDRB R0,[R0]         ; Load the contents into R0
    CMP R0,#0x0A         ; Compare if R0 is less than 0x0A(10 in decimal) i.e 0-9
    BLT NEXT             ; If less than 9 branch to NEXT
    ADD R0,R0,#7         ; If R0 IS greater than R0 and 7

NEXT
    ADD R0,R0,#0x30      ; If less than 9 ADD 30 
    LDR R2,=0x40000004   ; Load the address location value R2 with 0x40000004 where the result has to be stored
    STRB R0,[R2]         ; Store the result in R2
STOP
    B STOP
    
	END