	AREA Program, CODE, READONLY
	ENTRY

Main
	LDR R0, =Value1 ; Pointer to first value
	LDR R1, [R0] ; Load first part of value1
	LDR R2, [R0, #4] ; Load lower part of value1
	LDR R0, =Value2 ; Pointer to second value
	LDR R3, [R0] ; Load upper part of value2
	LDR R4, [R0, #4] ; Load lower part of value2
	ADDS R6, R2, R4 ; Add lower 4 bytes and set carry flag
	ADC R5, R1, R3 ; Add upper 4 bytes including carry
	LDR R0, =0x40000000 ; Pointer to Result
	
	STR R5, [R0] ; Store upper part of result
    LDR R0, =0x40000004 ; Pointer to Result
	STR R6, [R0] ; Store lower part of result

Value1 DCD &12A2E640, &F2100123 ; Value to be added
Value2 DCD &001019BF, &40023F51 ; Value to be added

	END