	AREA mycode, CODE, READONLY
	ENTRY
	
	LDR R0,=value1;
	LDR R1,[R0]; load lower 32 of val 1
	LDR R2,[R0,#4]; load upper 32 of val 1
	LDR R0,=value2;
	LDR R3,[R0];load lower 32 of val 2
	LDR R4,[R0,#4];load upper 32 of val 2
	ADDS R1,R1,R3; lower 32 bit answer
	ADC R2,R2,R4; upper 32 bit answer
STOP B STOP

value1 DCD 0xF1223344,0x55667788
value2 DCD 0xF2345678,0x12345678

	END