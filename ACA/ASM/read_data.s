; Read data from 0x40000000 and Store on 0x40000004
	
	AREA RESET, CODE, READONLY
	ENTRY

Main
	LDR	R0, =0x40000000		; Load the address value into R0
	LDR R1,Value            ; Load the value into R1
	STR R1,[R0]             ; Store the R1 value into location 0x40000000
	LDR R2, =0x40000004     ; Load the address value into R2
	STR R1, [R2]            ; Store the result in R2
	
Value DCD &12345678

	END