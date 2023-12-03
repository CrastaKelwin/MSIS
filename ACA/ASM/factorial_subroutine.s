;10. Using subroutine, find the factorial of a number.	
	
	AREA RESET, CODE, READONLY	
	ENTRY
	
	LDR R0,=06      ; Load R0 with value 5 (number of which the factorial has to be calculated)
	BL factorial    ; Branch to factorial
STOP B STOP
	
factorial
	PUSH {R4,LR}	;push R4 and LR onto the top of the stack ;stack<=>sdmdb sp!,{R4,LR} 
	MOV	R4,R0		;make a copy of R0 
    CMP	R0,#0		;compare R0 with 0 
    BNE	not_zero	;branch to not_zero if not equal	 
	MOV	R0,#1		;R0=1 
 	B	last
not_zero 
 	SUB	R0,R0,#1	 ;R0=R0-1 
 	BL	factorial	 ;call recursively factorial 
 	MOV	R1,R4		
 	MUL	R0,R1,R0	 ;R0=R0*R1 
last
 	POP	{R4,LR}		 ;pop	<=>	ldmia sp! {r4,lr} 
	BX	LR 
	
	END