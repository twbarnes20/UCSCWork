;Trevor Barnes
;11/8/2015
;Lab 5 
;Intro to LC-3 Programming Environment
;T-Th 1:00-3:00
;Sina Hessani

.ORIG x3000

AND R1, R1, 0
ADD R1, R1, 5
LEA R0, HELLO

LOOP      TRAP x22
          ADD R1, R1, -1

BRp LOOP


HELLO     .Stringz "Hello World, this is Trevor!\n" 
          .END