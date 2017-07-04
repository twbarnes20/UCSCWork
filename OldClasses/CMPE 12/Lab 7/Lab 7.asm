;Trevor Barnes
;Lab 6
;Caesar Cipher
;1330240
;T-Th 1:00-3:00
;Sina Hassani

.ORIG x3000

;This program uses row major form
;Clears out all arrays before each run
START	JSR CLEAR_ARRAY
	AND R0, R0, 0
	AND R1, R1, 0
	AND R2, R2, 0
	AND R3, R3, 0
	AND R4, R4, 0
	AND R5, R5, 0
	AND R6, R6, 0
	AND R7, R7, 0

;Displays greeting message
	LEA R0, GREETING
	PUTS

;Takes in Encrypt or Decrypt, Cipher, and phrase
JSR	INPUT
	LD R4, EOD
	LD R5, D

;Takes user input to determine whether to decrypt or encrypt
	AND R6, R6, 0
	ADD R4, R4, R5
BRnp	OUTNEXT

	LEA R0, PHRASE
	PUTS

;Sets row number to 0 for output of phrase
	AND R6, R6, 0
	ST  R6, ROWNUM
JSR	OUTPUT

	LEA R0, DECRYPTED
	PUTS
JSR	DECRYPT

;Sets row number to 1 for output of of decrypted phrase
	AND R6, R6, 0
	ADD R6, R6, 1
	ST  R6, ROWNUM
JSR 	OUTPUT

BRnzp	START

OUTNEXT
	LEA R0, PHRASE
	PUTS

;Sets row number to 0 for output of phrase
	AND R6, R6, 0
	ST  R6, ROWNUM
JSR	OUTPUT

	LEA R0, ENCRYPTED
	PUTS
JSR	ENCRYPT

;Sets row number to 1 for output of of encrypted phrase
	AND R6, R6, 0
	ADD R6, R6, 1
	ST  R6, ROWNUM
JSR 	OUTPUT
BRnzp	START

AGAIN	BRnzp START
FINISH 	HALT

PHRASE		.STRINGZ	"Here is your phrase \n"
ENCRYPTED	.STRINGZ	"\n Here is your phrase encrypted \n"
DECRYPTED	.STRINGZ	"\n Here is your phrase decrypted \n"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	INPUT
;Input takes in user input for 
;encrypt/decrypt instructions,
;the cipher, and the phrase.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;INITIAL PRINTING/SINGLE VALUE GATHERING

	ST  R7, NEWSTORE
	LD  R1, XCHECK

;Loop asks for decrypt/encrpyt instruction
;Only takes in E or D

EODLP	LEA R0, ENTEOD
	PUTS
	GETC
	OUT

;D or -68 is loaded in R2 in order to check for
;D as input
	LD  R2, D
	ADD R3, R0, R2
BRz	EODOK

;Subtracts one from D in order to make it
;ASCII E. D is negative because it is used to
;check for D as input
	ADD R2, R2, -1
	ADD R3, R0, R2
BRz	EODOK
	ADD R2, R0, R1	
BRz	FINISH
	LEA R0, INVALID
	PUTS
BRnzp	EODLP

EODOK	ST R0, EOD

;Takes in the user's cipher
;Only allows numbers 1-25

CIPHLP	AND R1, R1, 0
	ADD R1, R1, 9

	AND R5, R5, 0
	AND R6, R6, 0

	LEA R0, ENTCIPHER
	PUTS
	GETC
	OUT
	
;Converts the number to its actual decimal value
	LD  R2, NEGOFFSET
	ADD R0, R0, R2

	ADD R5, R0, 0

;Moves the first digit to the 10s place
MULT	ADD R0, R0, R5
	ADD R1, R1, -1
BRnp	MULT

	ADD R6, R0, R6

	GETC
	OUT

;Converts the number to its actual decimal value
;and stores it along with the first digit in R6
	ADD R0, R0, R2
	ADD R6, R0, R6

;Checks if the cipher is between 1 and 25
;by making sure 1 <= cipher<= 25
	ADD R3, R6, -1
BRn	CIPHWRG
	
	LD  R2, TWENTYFIVE
	ADD R3, R6, R2
BRp	CIPHWRG

	ST R6, CIPHER

BRnzp	INNEXT

;Asks for cipher input again because
;the input was wrong

CIPHWRG	LEA R0, INVALID
	PUTS
BRnzp	CIPHLP

;because of the way the cipher is done it
;must always be entered in two digit form,
;if you want to  enter 1 it has to be 01

;INPUT  LOOP

;Displays asking for phrase message
INNEXT	LEA R0, ENTNUM
	PUTS
	AND R3, R3, 0

;The only check done on input is if it 
;is enter otherwise anything can be 
;put in
INLOOP	GETC
	OUT
	ADD R2, R0, -10
BRz 	INDONE
	
;Sets row number to one so STORE knows
;where to put the character
	AND R4, R4, 0
	ST  R4, ROWNUM
JSR	STORE

;R3 is used as a way to count how
;large the input is which is used
;in later functions
	ADD R3, R3, 1
BRnzp	INLOOP

INDONE	ADD R3, R3, -1
	ST  R3, NUMSIZE
	LD  R7, NEWSTORE
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

XCHECK		.FILL	-88
EOD		.FILL	0
NEWSTORE	.FILL   0	
TWENTYFIVE	.FILL	-25
NEGOFFSET	.FILL	-48
D		.FILL	-68
GREETING	.STRINGZ "\n Caesar Cipher Program \n"
ENTNUM		.STRINGZ "\n Enter a phrase to be converted. \n"
ROWNUM		.FILL	0
NUMSIZE 	.FILL 	0
CIPHER		.FILL   0
ENTEOD		.STRINGZ "Do you want to (E)NCRYPT or (D)ECRYPT, or X to quit \n"
INVALID		.STRINGZ "\n Invalid input please enter again \n"
ENTCIPHER	.STRINGZ "\n Enter your cipher. \n"
COLNUM		.FILL   200

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ENCRYPT
;Encrypt takes in a phrase character
;by character and adds the cipher 
;to it depending on if it is A-Z,
;a-z or, not.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	ST  R7, PCSTORE
	AND R4, R4, 0
	ST  R4, STORELOCATION
	LD  R5, NUMSIZE

ENCBEGIN
	LD  R4, CIPHER
	ST  R5, TEMPCOUNT
JSR 	LOAD

;These next two blocks check if
;the loaded character is
;between the ASCII values of A and Z.
;If they aren't they're sent to check
;for lowercase numbers
	LD  R1, A
	ADD R2, R6, R1
BRn	LOWERCHECK

	LD  R1, Z
	ADD R2, R6, R1
BRp	LOWERCHECK
	
;Checks if Cipher + character is within
;bounds if it is then it stores cipher + character.
;If it isn't then it stores cipher - 26.
;This changes the cipher to its complement for 
;the number 26 and subtracts if from the character.
	ADD R3, R4, R6
	ADD R2, R1, R3
BRnz	UPPEROKAY

	LD  R1, ALPHABET
	ADD R3, R4, R1
	ADD R0, R6, R3
BRnzp	ENCFIN

UPPEROKAY	
	AND R0, R0, 0
	ADD R0, R3, 0
BRnzp	ENCFIN

;These next two blocks check if
;the loaded character is
;between the ASCII values of a and z.
;If they aren't they're sent to 
;the special character block
LOWERCHECK
	LD  R1, a
	ADD R2, R6, R1
BRn	ENCALPHABET
	LD  R1, z
	ADD R2, R6, R1
BRp	ENCALPHABET
	
;Same check as above except uses lowercase
;values to test
	ADD R3, R4, R6
	ADD R2, R1, R3
BRnz	LOWEROKAY

	LD R1, ALPHABET
	ADD R3, R4, R1
	ADD R0, R6, R3
BRnzp	ENCFIN

LOWEROKAY
	AND R0, R0, 0
	ADD R0, R3, 0
BRnzp	ENCFIN

;If the number isn't between
;A-Z and a-z then it is stored
;with no modification
ENCALPHABET
	AND R0, R0, 0 
	ADD R0, R6, 0
	
;Row number is set to 1 which is where
;the modified phrase is put
ENCFIN	AND R5, R5, 0
	ADD R5, R5, 1
	ST  R5, ROWNUM
	JSR STORE
;Due to register restraint I had to use store
;my counting variable between each loop
	LD  R5, TEMPCOUNT
	ADD R5, R5, -1
BRnp	ENCBEGIN
	LD R7, PCSTORE
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
TEMPCOUNT	.FILL	0
PCSTORE		.FILL	0
ALPHABET	.FILL	-26
A		.FILL	-65
a		.FILL	-97
Z		.FILL	-90
z		.FILL	-122
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	DECRYPT
;Decrypt takes in a phrase character
;by character and adds the cipher 
;to it depending on if it is A-Z,
;a-z or, not.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Because I started running out of
;registers I had to use keep storing
;R5, which was being used as the
;variable to determine the number 
;of loops
	ST  R7, PCSTORE
	AND R5, R5, 0
	ST  R5, STORELOCATION
	LD  R5, NUMSIZE

DECBEGIN
	ST  R5, TEMPCOUNT
	LD  R4, CIPHER
;Cipher is made to be negative
	NOT R4, R4
	ADD R4, R4, 1

;Loads a character into R6

JSR 	LOAD

;These next two blocks check if
;the loaded character is
;between the ASCII values of A and Z.
;If they aren't they're sent to check
;for lowercase numbers
	LD  R1, A
	ADD R2, R6, R1
BRn	DECLOWER
	
	LD  R1, Z
	ADD R2, R6, R1
BRp	DECLOWER
	
;Checks to make sure character - cipher
;is within the bounds of a-z.
;if it isn't then the cipher is modified.
;The cipher becomes 26 - cipher. 
;So if the cipher - number is in bounds it is stored
;If it isn't in bounds then the Newcipher + number is
;stored
	LD  R1, A
	ADD R0, R6, R4
	ADD R2, R0, R1
BRzp	DECFIN

	LD  R1, ALPHABET
	NOT R1, R1
	ADD R1, R1, 1
	ADD R4, R1, R4
	ADD R0, R6, R4	
BRnzp	DECFIN

DECLOWER
	
;These next two blocks check if
;the loaded character is
;between the ASCII values of a and z.
;If they aren't they're sent to 
;the special character block
	LD  R1, a
	ADD R2, R6, R1
BRn	DECALPHABET
	
	LD  R1, z
	ADD R2, R6, R1
BRp	DECALPHABET

;Same check as above except uses lowercase
;values to test
	LD  R1, a
	ADD R0, R6, R4
	ADD R2, R0, R1
BRzp	DECFIN

	LD  R1, ALPHABET
	NOT R1, R1
	ADD R1, R1, 1
	ADD R4, R1, R4
	ADD R0, R6, R4	
BRnzp	DECFIN

;If the characters have reached this point
;then they aren't a-z or A-Z and are just stored
;without any modification
DECALPHABET
	AND R0, R0, 0
	ADD R0, R6, 0

;Sets row number to one since that is where
;the modified phrase is stored
DECFIN	AND R5, R5, 0
	ADD R5, R5, 1
	ST  R5, ROWNUM
JSR	STORE
	LD  R5, TEMPCOUNT
	ADD R5, R5, -1
BRnp	DECBEGIN
	LD  R7, PCSTORE
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	STORE
;Stores data in Row 0 or 1
;Uses data from R0 to store
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Stores data in row major form

;Makes R1 a pointer to the first location in storage
	LEA R1, STORAGE
;Loads the row number in R2
	LD  R2, ROWNUM
;This keeps track of the column number
	LD  R3, STORELOCATION
	
;Checks if it supposed to go in Row 0 or Row 1
	ADD R2, R2, -1
BRnp	STNEXT
;If it is Row 1 then it adds 200 to the pointer
	LD  R4, COLNUM
	ADD R1, R1, R4

;Regardless if it is Row 0 or 1 the function adds
;The column number to the pointer and stores the 
;data in that location
STNEXT	ADD R1, R1, R3
	STR R0, R1, 0

;Increments column counter by 1 and stores it
	ADD R3, R3, 1
	ST  R3, STORELOCATION
	
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	OUTPUT
;Outputs the phrase, encrypted,
;phrase, or decrypted phrase.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ST  R0, TEMPVAR0
	ST  R1, TEMPVAR1
	ST  R2, TEMPVAR2
	ST  R7, PCSTORE
	LEA R0, STORAGE
	LD  R1, COLNUM
	LD  R2, ROWNUM

;Checks if row 0 or 1 is being used as output
;If its row 1 then it adds 200 to the pointer
;Either way it can use PUTS for outputting the
;phrase since it is a string
	ADD R2, R2, -1
BRz	ROW1
	PUTS
BRnzp	OUTEND
	
ROW1	ADD R0, R0, R1
	PUTS
	
OUTEND	LD  R0, TEMPVAR0
	LD  R1, TEMPVAR1
	LD  R2, TEMPVAR2
	LD  R7, PCSTORE
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	LOAD
;Loads data from the first row
;in order to be encrypted or 
;decrypted
;Loads data into R6
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Pointer to STORAGE
	LEA R1, STORAGE
;R2 keeps track of column number
	LD  R2, LOADLOCATION

;Loads R6 for use in the rest of the program	
	ADD R1, R1, R2
	LDR R6, R1, 0
	
	ADD R2, R2, 1
	ST  R2, LOADLOCATION
	
	RET	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CLEAR_ARRAY
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Pointer to first place of storage
	LEA R0, STORAGE
;Clears R1 and R2
	AND R1, R1, 0
	AND R2, R2, 0
;Resets column counters for store and
;load so the program can properly run
;multiple times
	ST  R2, STORELOCATION
	ST  R2, LOADLOCATION
;Loads column offset into R3
	LD  R3, COLNUM

;Clears a row by setting each value to zero.
;This goes until the the loop hits a naturally
;occuring zero in the array
CLEAR0	LDR R1, R0, 0
	ADD R1, R1, 0
BRz	ROW_ZERO_CLEARED
	STR R2, R0, 0
	ADD R0, R0, 1
BRnzp	CLEAR0

;Does the same as above except it does
;it for the second row
ROW_ZERO_CLEARED
	LEA R0, STORAGE
	ADD R0, R0, R3
CLEAR1	LDR R1, R0, 0
	ADD R1, R1, 0
BRz	CLEARED
	STR R2, R0, 0
	ADD R0, R0, 1
BRnzp	CLEAR1

CLEARED	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
STORELOCATION	.FILL 	0
LOADLOCATION	.FILL 	0
NEWLINE		.FILL	10
TEMPVAR0	.FILL	0
TEMPVAR1	.FILL	0
TEMPVAR2	.FILL	0
STORAGE	.BLKW	400

		.END