	AREA mycode, CODE, READONLY
	ENTRY
	
	LDR R0,=value1;
	LDRH R1,[R0]
	LDR R0,=value2;
	LDRH R2,[R0]
	ADD R3,R2,R1
STOP B STOP

value1 DCD 0x1122
value2 DCD 0x4433

	END