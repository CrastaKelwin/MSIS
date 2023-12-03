;4. Find the square root of a number present in 0x40000000. Store the result back in 0x40000030 
	
	AREA RESET,CODE,READONLY
    ENTRY
	
Main
    LDR R2,=0x40000000      ; Load R2 with address location 0x40000000
    LDR R2,[R2]             ; Load the contents in R2
    LDR R0,=0x01            ; Initialize a counter R0=1
    LDR R1,=0x01            ; Initialize a counter R1=1

loop1    
    SUB R2,R2,R0            ; Initially subtract R2=R2-R0
    CMP R2,#0               ; Check if R2 is zero ; R2=0
    BEQ loop                ; Branch to loop if R2=0
    ADD R0,#2               ; Increment R0 by 2 every time ; R0=R0+2
    ADD R1,#1               ; Increment R1 by 1 every time ; R1=R1+1 ; Number of iterations of R1 gives the square root value
    B loop1                 ; Branch to loop1

loop
    LDR R3, =0x40000030     ; Load R3 with address 0x40000030 where the result has to be stored
    STR R1, [R3]            ; Store the result value in R1
STOP B STOP
   
   END