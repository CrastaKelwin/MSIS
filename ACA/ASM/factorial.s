;3. Find the factorial of a number. 

	AREA RESET, CODE, READONLY	
	ENTRY

START 
	LDR R0, NUM        ; Load the value of which the factorial to be calculated 
	SUB R1, R0, #1     ; R1=R0-1
TOP
	CMP R1, #0         ; Check if the value is 0
	BEQ STOP           ; Branch to stop if the value is 0
	MUL R2, R1,R0      ; R0=R0*R1
	SUB R1,R1, #1      ; Decrement the counter value R1=R1-1
	B TOP              ; Branch to top
	
STOP B STOP
NUM DCD 5
	
	END