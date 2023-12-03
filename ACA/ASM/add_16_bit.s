;2. Implement a 16-bit addition. Assume data is present in code memory. 
	
	AREA RESET, CODE, READONLY	
	ENTRY
Main
	LDR R0, =NUM        ; Load the address of the value
	LDRH R1, [R0]       ; Load the lower 16 bits of the 32 bit number into R1
	LDRH R2, [R0, #2]    ; Load the higher 16 bits of the 32 bit number into R2
	ADD R3, R1, R2      ; Add the contents of R1 and R2 and store it in R3
	LDR R4, =0x40000000 ; Load the address where the result has to be stored i.e 0x40000000
	STR R3, [R4]       ; Store the result (contents of R3) in R4 
STOP B STOP
	
NUM DCD 0x12345678
	
	END