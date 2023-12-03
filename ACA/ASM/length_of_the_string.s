; 7. Find the length of the string character.

	AREA Reset, CODE, READONLY
	ENTRY
Main
	LDR R0, =Data1      ; Load the address of the lookup table
	EOR R1,R1,R1        ; Clear the register R1 to store the contents
	LDR R4, CharCount   ; Initialze the character counter
	
Loop
	LDRB R2, [R0], #1   ; Load the first byte into R2
	CMP R2, #CR         ; Compare with Carriage Return
	BEQ Done            ; Branch to Done if R2 and CR are equal
	ADD R1,R1, #1       ; Increment the Counter value
	BAL Loop            ; Branch to Loop until the counter reaches last character
Done 
	STR R1, [R4]        ; Store the string length count in R1
	
Data1
	DCB "Hello", CR
	ALIGN
		
CharCount DCD &40000000
CR EQU 0x0D
	
	END