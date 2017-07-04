;Trevor Barnes
;Lab 6
;Decimal Converter
;1330240
;T-Th 1:00-3:00
;Sina Hassani

.ORIG x3000
     
	AND R0, R0, 0
	AND R1, R1, 0
	AND R5, R5, 0
        AND R6, R6, 0

	LEA R0, GREETING
	TRAP x22

	AND R0, R0, 0
	ADD R1, R1, 12
        
LOOP
	ADD R1, R1, R0
	IN
	JSR TWOCOMP
	ADD R1, R1, R0
	JSR TWOCOMP

BRnp LOOP

TWOCOMP NOT R0, R0
	ADD R0, R0, 1
	RET

HALT

GREETING .STRINGZ	"Enter a number to be converted. \n"
FLAG     .FILL    	x0
INT      .FILL    	x0

.END