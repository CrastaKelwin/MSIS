	AREA RESET, CODE,READONLY
	ENTRY
MAIN
	LDR R1, Value           ;Load the value to be disassembled
	LDR R2, MASK			; Load the bitmask
	MOV R3, R1, LSR #0x4    ; Copy just the high order nibble into R3
	MOV R3, R3, LSL #0x8    ; Now left shift it one byte
	AND R1, R1, R2 			; AND the original number with the bitmask
	ADD R1, R1, R3 			; Add the result of that to what we moved into R3
	LDR R4, Result          ; Store the result
	STR R1, [R4]
Value DCB &5F
	ALIGN
MASK DCW &000F
	ALIGN
Result DCD &40000000
	
	END