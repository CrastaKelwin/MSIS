 ;Adding two 32-bit numbers 
	
	AREA RESET, CODE, READONLY	
	ENTRY

Main			
	LDR	R1, Value1		; Load the first number
	LDR	R2, Value2		; Load the second number
	ADD	R3, R1, R2		; ADD them together into R1 (x = x + y)
	STR	R3, Result		; Store the result
	SWI	&11				; All Done

Value1	DCD	&37E3C123		; First value to be added
Value2	DCD	&367402AA		; Second value to be added
Result	DCD	&0				; Storage for result
	END