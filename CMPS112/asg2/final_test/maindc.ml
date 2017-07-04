(* $Id: maindc.ml,v 1.5 2017-04-07 13:24:41-07 - - $ *)
(*
  Trevor Barnes trwbarnes@ucsc.edu
  Kevin Cai     kcai2@ucsc.edu
*)
include Scanner
include Bigint

open Bigint
open Printf
open Scanner

type stack_t = Bigint.bigint Stack.t
let push = Stack.push
let pop = Stack.pop

let ord thechar = int_of_char thechar
type binop_t = bigint -> bigint -> bigint

let print_number number = 
  let rec print_digit i just_newlined number = 
    if i = (String.length number)
      then printf "\n%!"
    else if (i > 0 && i mod 69 = 0 && not just_newlined)
      then (printf "\\\n%!" ; print_digit i true number) 
    else
      (printf "%c" (number.[i]) ; print_digit (i+1) false number) 
  in print_digit 0 false (string_of_bigint number)

let print_stackempty () = printf "dc: stack empty\n%!"

let memory = Hashtbl.create 128

let executereg (thestack: stack_t) (oper: char) (reg: int) =
  try match oper with
    | 's' ->
      Hashtbl.replace memory reg (pop thestack)
    
    | 'l' -> 
      if (Hashtbl.mem memory reg)
      then push (Hashtbl.find memory reg) thestack    

    | _   -> printf "0%o 0%o is unimplemented\n%!" (ord oper) reg
      with Stack.Empty -> print_stackempty()

let executebinop (thestack: stack_t) (oper: binop_t) =
    try let right = pop thestack
        in  try let left = pop thestack
                in  push (oper left right) thestack
            with Stack.Empty -> (print_stackempty ();
                                 push right thestack)
    with Stack.Empty -> print_stackempty ()

let execute (thestack: stack_t) (oper: char) =
    try match oper with
        | '+'  -> executebinop thestack Bigint.add
        | '-'  -> executebinop thestack Bigint.sub
        | '*'  -> executebinop thestack Bigint.mul
        | '/'  -> executebinop thestack Bigint.div
        | '%'  -> executebinop thestack Bigint.rem
        | '^'  -> executebinop thestack Bigint.pow
        | 'c'  -> Stack.clear thestack
        | 'd'  -> push (Stack.top thestack) thestack
        | 'f'  -> Stack.iter print_number thestack
        | 'l'  -> failwith "operator l scanned with no register"
        | 'p'  -> print_number (Stack.top thestack)
        | 'q'  -> raise End_of_file
        | 's'  -> failwith "operator s scanned with no register"
        | '\n' -> ()
        | ' '  -> ()
        | _    -> printf "0%o is unimplemented\n%!" (ord oper)
    with Stack.Empty -> print_stackempty()

let toploop (thestack: stack_t) inputchannel =
    let scanbuf = Lexing.from_channel inputchannel in
    let rec toploop () = 
        try  let nexttoken = Scanner.scanner scanbuf
             in  (match nexttoken with
                 | Number number       -> push number thestack
                 | Regoper (oper, reg) -> executereg thestack oper reg
                 | Operator oper       -> execute thestack oper
                 );
             toploop ()
        with End_of_file -> ()
    in  toploop ()

let readfiles () =
    let thestack : bigint Stack.t = Stack.create ()
    in  ((if Array.length Sys.argv > 1 
         then try  let thefile = open_in Sys.argv.(1)
                   in  toploop thestack thefile
              with Sys_error message -> (
                   printf "%s: %s\n%!" Sys.argv.(0) message;
                   exit 1));
        toploop thestack stdin)

let interact () =
    let thestack : bigint Stack.t = Stack.create ()
    in  toploop thestack stdin

let _ = if not !Sys.interactive then readfiles ()

