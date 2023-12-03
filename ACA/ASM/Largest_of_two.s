;Find the larger of two numbers

	AREA Reset, CODE, READONLY
	ENTRY
Main

	LDR R1, =0x40000000       
	LDR R2, [R1]
	ADD R1,R1,#0x4
	LDR R3,[R1]
	CMP R2, R3                
	BHI Done                  
	MOV R2, R3                
Done
	LDR R1,=0x40000008
	STR R2, [R1]
	
	END	