;Trevor Barnes
;Lab 6
;Decimal Converter
;1330240
;T-Th 1:00-3:00
;Sina Hassani

.ORIG x3000
     
BEGIN	;Clears all registers before each run
	AND R0, R0, 0
	AND R1, R1, 0
	AND R2, R2, 0
	AND R3, R3, 0
	AND R4, R4, 0
	AND R5, R5, 0	
        AND R6, R6, 0	
	AND R7, R7, 0
	
;Prints Greeting Message
	LEA R0, GREETING
	TRAP x22

;Sets first flag to 1 which
;is used to indicate whether
;or not the first number is
;being entered
	LD  R4, FIRSTFLG
	AND R4, R4, 0
	ADD R4, R4, 1
	ST  R4, FIRSTFLG

;Runs Input, Hex and Binary subroutines
JSR	INPUT
JSR	BINARY
	LD R0, NEWLINE
	OUT
JSR	HEX
	LD R0, NEWLINE
	OUT
;Resets negative flag between runs
	AND R5, R5, 0
	ST  R5, FLAG
;Continues until X is entered
BRnzp 	BEGIN
END	LEA R0, GOODBYE
	TRAP x22

	HALT

;;;;;;;;;;;;;;;;;;;;;;;;

;Stores PC so TRAPs can be used
INPUT	ST R7, PCSTORE

;Gets a character checks for the correct input then prints it back
LOOP	GETC
JSR	CORRECTIN
	OUT

;Checks if ENTER is pressed
	ADD R1, R0, -10
BRz	ENDLOOP

;Checks for negative number and sets flag accordingly	
	LD R3, NEGCHK
	ADD R1, R0, R3
BRz	NEGLP
BRnzp	ENDCHK		
NEGLP	AND R5, R5, 0													
	ADD R5, R5, 1
	ST R5, FLAG
BRnzp	LOOP

ENDCHK	LD R5, X
	ADD R1, R5, R0
BRnp	CONT
BRnzp	END


;Multiplication function that adds a number to itself 9 times
;which is the equivalent of multiplying by 10
CONT	AND R1, R1, 0
	ADD R1, R1, 9
	AND R4, R4, 0
	ADD R4, R4, R6
MULTLP	ADD R6, R6, R4
	ADD R1, R1, -1
BRnp	MULTLP

;Subtracts 48 to turn from ASCII value to actual number
;then stores in R6
	LD R2, OFFSET
	ADD R0, R0, R2
	ADD R6, R6, R0
BRnzp 	LOOP	
ENDLOOP	
	ST R6, NUM
	LD R7, PCSTORE
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;
BINARY	ST R7, PCSTORE

;Sets R1 as a counter variable of 16
	AND R1, R1, 0
	ADD R1, R1, 15
	ADD R1, R1, 1

;Sets R2 as positive offset of 48
;Sets R3 to a MASK pointer
;Loads the number into R6
	LD  R2, PLUS	
	LEA R3, MASK0
	LD  R6, NUM

;Checks for a negative number
	LD  R5, FLAG
	ADD R5, R5, -1

;Turns number to two's complement if flag is 1
BRnp	BINLP
	NOT R6, R6
	ADD R6, R6, 1

;Loads the contents of the memory address R3 is pointing to, into R4
BINLP	LDR R4, R3, 0
	AND R5, R4, R6

;Prints 1 or 0 depending on what the number ANDed with the mask is
BRnp	PRINT1
	AND R0, R2, R2
	OUT
BRnzp	PRINT0
PRINT1	AND R0, R0, 0
	ADD R0, R2, 1
	OUT	
PRINT0	ADD R3, R3, 1
	ADD R1, R1, -1
BRnp	BINLP

;Goes until R1 is 0	
	LD R7, PCSTORE
	AND R6, R6, 0
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;
CORRECTIN
;Checks if this is the first digit in the number being entered
;If it is, it allows a negative sign as an input otherwise
;it doesn't
	LD  R4, FIRSTFLG
	ADD R4, R4, -1
BRnp	CONTIN
	LD  R3, NEGCHK
	ADD R2, R0, R3
BRz	DONE

;Checks for ENTER and X inputs
CONTIN	ADD R2, R0, -10
BRz	DONE
	LD  R3, X
	ADD R2, R0, R3
BRz	DONE

;Checks if (num>=0 and num<=9)
	LD  R1, ZERO
	ADD R2, R0, R1
	BRn INVALID

	LD  R1, NINE
	ADD R2, R0, R1
	BRp INVALID
	BRnzp DONE

;Prints message that input is invalid then restarts input process
INVALID	OUT
	LEA R0, WRONG
	TRAP x22
	LD R6, VARSAVE
BRnzp	BEGIN

DONE	AND R4, R4, 0
	ST  R4, FIRSTFLG
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;
HEX	ST R7, PCSTORE
	AND R1, R1, 0

;Loads the address of MASK0 into R5 and the number in NUM to R6
	LD R6, NUM	
	LEA R5, MASK0

;Checks for negative number then uses two's complement if it is applicable
	LD  R0, FLAG
	ADD R2, R0, -1
BRnp	HEXLP
	NOT R6, R6
	ADD R6, R6, 1 


HEXLP	

;Resets sum before every iteration of the loop
	AND R0, R0, 0
;When R1 is 4 then the conversion process ends
	ADD R2, R1, -4
BRz	HEXFIN
	
;Loads contents of memory location R5 is pointing to into R4
	LDR R4, R5, 0
	AND R2, R4, R6
;Checks each mask one by one anding it with the value,
;if the value is 1 then it adds the corresponding 1, 2, 4, or 8
;to the SUM. If the ANDed value is 0 then it skips over adding
;nothing to the SUM.
BRz	ENEXT
	ADD R0, R0, 8

ENEXT	ADD R5, R5, 1
	LDR R4, R5, 0
	AND R2, R6, R4
BRz	FNEXT
	ADD R0, R0, 4

FNEXT	ADD R5, R5, 1
	LDR R4, R5, 0
	AND R2, R6, R4
BRz	TNEXT
	ADD R0, R0, 2
	
TNEXT	ADD R5, R5, 1
	LDR R4, R5, 0
	AND R2, R6, R4
BRz	ONEXT
	ADD R0, R0, 1

ONEXT	ADD R5, R5, 1 	
	ADD R1, R1, 1

;Checks if the number is 0-9 or A-F
;then adds appropriate ASCII offset so 
;it is printed properly repeats four times
;since 1 hex value is worth 4 binary values
	ADD R2, R0, -9
BRp	NUMTOHEX
	LD  R2, PLUS 
	ADD R0, R0, R2
	OUT

BRnzp	HEXLP

NUMTOHEX
	LD  R4, NUMOFF
	ADD R0, R0, R4
	OUT
BRnzp	HEXLP
	
HEXFIN	LD R7, PCSTORE
	RET	
;;;;;;;;;;;;;;;;;;;;;;;;;

NEWLINE	 .STRINGZ	"\n"
NEGCHK   .FILL		-45
PCSTORE	 .FILL		0
FIRSTFLG .FILL		1
X	 .FILL		-88
FLAG     .FILL    	0
GREETING .STRINGZ	"\n Enter a number to be converted, or X to end. \n"
GOODBYE	 .STRINGZ	"\n Goodbye."
WRONG	 .STRINGZ	"\n Incorrect input, enter again \n"
INT      .FILL    	0
OFFSET	 .FILL		-48
PLUS	 .FILL		48
NEWPC 	 .FILL		0
NUM	 .FILL		0
VARSAVE	 .FILL		0
NUMOFF	 .FILL 		55
MASK0	 .FILL		x8000
MASK1	 .FILL		x4000
MASK2	 .FILL		x2000
MASK3	 .FILL		x1000
MASK4	 .FILL		x0800
MASK5	 .FILL		x0400
MASK6	 .FILL		x0200
MASK7	 .FILL		x0100
MASK8	 .FILL		x0080
MASK9	 .FILL		x0040
MASKA	 .FILL		x0020
MASKB	 .FILL		x0010
MASKC	 .FILL		x0008
MASKD	 .FILL		x0004
MASKE	 .FILL		x0002
MASKF	 .FILL		x0001
ZERO	 .FILL		-48
;ONE	 .FILL		-49
;TWO	 .FILL		-50
;THREE	 .FILL		-51
;FOUR	 .FILL		-52
;FIVE	 .FILL		-53
;SIX	 .FILL		-54
;SEVEN	 .FILL		-55
;EIGHT	 .FILL		-56
NINE	 .FILL		-57

	 .END