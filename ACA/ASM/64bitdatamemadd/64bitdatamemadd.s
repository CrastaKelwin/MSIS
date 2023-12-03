	AREA mycode,CODE,READONLy
	ENTRY
	
	LDR R0,value1Address;
	LDR R1,[R0]; load lower 32 of val 1
	LDR R2,[R0,#4]; load upper 32 of val 1
	LDR R0,value2Address;
	LDR R3,[R0];load lower 32 of val 2
	LDR R4,[R0,#4];load upper 32 of val 2
	ADDS R1,R1,R3; lower 32 bit answer
	ADC R2,R2,R4; upper 32 bit answer
	LDR R0,ResultAddress;
	STR R1,[R0]
	STR R2,[R0,4]
STOP B STOP

value1Address DCD 0x40000008
value2Address DCD 0x40000010
ResultAddress DCD 0x40000000
	
	END