 ; 5. Consider an array of 5 32-numbers present from location 0x40000000. Find the sum of these numbers and store back in 0x40001000.
	 
	 AREA RESET, CODE, READONLY
	 ENTRY
	 
Main
	 LDR R0, =5           ; Initializing counter register
	 LDR R1, =0x40000000  ; Loading base address to a register
LOOP
     LDR R2,[R1],#4       ; Loading value from array and updating (increment) the address 
	 ADD R3,R3,R2         ; Sum is stored in R3 register
	 SUB R0, R0, #1       ; Decrementing counter value
	 CMP R0, #00          ; Checking counter value
	 BNE LOOP
	 LDR R4, =0x40001000  ; Load the address location where the result has to be stored
	 STR R3, [R4]         ; Store the Result in register R3 and address location 0x40001000
	  
	 END