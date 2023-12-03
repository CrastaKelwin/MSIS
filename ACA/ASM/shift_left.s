	AREA RESET, CODE, READONLY
	ENTRY

Main
	LDR R1, Value         ; Load the value to be shifted
	MOV R1, R1, LSL #0x1  ; SHIFT LEFT one bit
	LDR R0, Result       
	STR R1, [R0]


Value DCD &4242            ; Value to be shifted
Result DCD &40000000               ; Space to store result
	
	END