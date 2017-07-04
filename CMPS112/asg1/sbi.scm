#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/racket/bin/mzscheme -qr

;;Kevin Cai (kcai2@ucsc.edu)
;;Trevor Barnes (trwbarne@ucsc.edu)

;; $Id: sbi.scm,v 1.3 2016-09-23 18:23:20-07 - - $
;;
;; NAME
;;    sbi.scm - silly basic interpreter
;;
;; SYNOPSIS
;;    sbi.scm filename.sbir
;;
;; DESCRIPTION
;;    The file mentioned in argv[1] is read and assumed to be an SBIR
;;    program, which is the executed.  Currently it is only printed.
;;

(define *stderr* (current-error-port))

(define *run-file*
    (let-values
        (((dirpath basepath root?)
            (split-path (find-system-path 'run-file))))
        (path->string basepath))
)

(define (die list)
    (for-each (lambda (item) (display item *stderr*)) list)
    (newline *stderr*)
    (exit 1)
)

(define (usage-exit)
    (die `("Usage: " ,*run-file* " filename"))
)

(define (readlist-from-inputfile filename)
    (let ((inputfile (open-input-file filename)))
         (if (not (input-port? inputfile))
             (die `(,*run-file* ": " ,filename ": open failed"))
             (let ((program (read inputfile)))
                  (close-input-port inputfile)
                         program))))

(define (write-program-by-line filename program)
    (printf "==================================================~n")
    (printf "~a: ~s~n" *run-file* filename)
    (printf "==================================================~n")
    (printf "(~n")
    (map (lambda (line) (printf "~s~n" line)) program)
    (printf ")~n"))

(define (main arglist)
    (if (or (null? arglist) (not (null? (cdr arglist))))
        (usage-exit)
        (let* ((sbprogfile (car arglist))
               (program (readlist-from-inputfile sbprogfile)))
        (hash-labels program)
        (statement-parse program 0))))


(define (label-hash program)
    (map (lambda(line)
            (when (or (=2 (length line))
                (and (=3 (length line))
                    (not (list? (cadr line)))
                )
            )
            (hash-set! *label-table* (cadr line) (car line))
         )
    )
    program
    )   
)

;Hash table for variables
(define *var-table* (make-hash)) 
(define (putsym! key value)
    (hash-set! *var-table* key value)
)


(define (let_func rest)
    (if (pair? (car rest))
        (begin (vector-set! (getvar! (caar rest))
                (- (inexact->exact (evalexpr (cadar rest))) 1)
                    (evalexpr (cadr rest)))
               (putvar! (caar rest) (getvar! (caar rest)))
        )
        (putvar! (car rest) (evalexpr (cadr rest)))
    )
)

(define (dim rest) 
   (putvar! (caar rest)
      (make-vector (inexact->exact (evalexpr(cadar rest))))
   )
)

;declaring variable table for vars
(define *variables* (make-hash))

;function to insert variables into the hash table
(define (putvar! key value)
    (hash-set! *variable-table* key value)
)

;function to retrieve variables from the hash table
(define (getvar! key)
    (hash-ref *variable-table* key)
)

(define *labels* (make-hash))

(define (labels! key value)
   (hash-set! *labels* key value)
)

(define (print-the-table table)
   (hash-for-each table (lambda (key value)
                           (printf "~s : ~s~n" key value))
   )
)

(define (put-in variable-list)
    (putvar! 'inputcount 0)
    (put-in-help variable-list)
)

(define (put-in-help variable-list)
    (putvar! (car variable-list) (read))
    (if (eof-object? (getvar! (car variable-list)))
        (when (= (getvar! 'inputcount) 0)
            (putvar! 'input (-1))
        )
        (begin (putvar! 'inputcount (+1 (getvar! 'inputcount)))
            (when (not(null? (cdr variable-list)))
                (put-in-help (cdr variable-list)))
        )
    )
)  

;function for when 'goto' is called
(define (onward label)
    (line-num(- (hash-ref *label-table* (car label)) 1))
)

;function for when 'if' is called
(define (perhaps rest)
    (when (evalexpr (car rest))
        (onward (cdr rest))
    )
)

(define (print_func item)
    (map (lambda(x)
        (display (evalexpr x))
    item)
    (newline))
)

;(define (length
;  (lambda (item)
;   (if (null? item)
;      0
;      (+ (length cdr(item)) 1))))
;)



(define (statement-run statement exec num) 
  (when (not (hash-has-key? n-hash (car statement)))
        (die "Error" (car statement)))
  (cond
        ((eq? (car statement) 'print)
         (if (null? (cdr statement))
           (newline)
           (print_func (cdr statement)))
           (statement-parse exec (+ num 1)))
        ((eq? (car statement) 'if)
         (if (evalexpr (car (cdr statement)))
            (statement-parse exec (hash-ref l-hash (cadr (cdr statement))))
           (statement-parse exec (+ num 1))))
        ((eq? (car statement) 'goto)
         (statement-parse exec (hash-ref l-hash (cadr statement))))
        (else
          ((hash-ref n-hash (car statement)) (cdr statement))
          (statement-parse exec (+ num 1)))))

(define *functions* (make-hash))
(define (get_func key)
   (hash-ref *functions* key))
(define (putsym! key value)
   (hash-set! *functions* key value))


(for-each
    (lambda (pair)
            (putsym! (car pair) (cadr pair)))
    `(

        (log10_2 0.301029995663981195213738894724493026768189881)
        (sqrt_2  1.414213562373095048801688724209698078569671875)
        (e       2.718281828459045235360287471352662497757247093)
        (pi      3.141592653589793238462643383279502884197169399)
        (div     ,(lambda (x y) (floor (/ x y))))
        (log10   ,(lambda (x) (/ (log x) (log 10.0))))
        (mod     ,(lambda (x y) (- x (* (div x y) y))))
        (quot    ,(lambda (x y) (truncate (/ x y))))
        (rem     ,(lambda (x y) (- x (* (quot x y) y))))
        (+       ,+)
        (^       ,expt)
        (round   ,round)
        (ceil    ,ceiling)
        (exp     ,exp)
        (floor   ,floor)
        (log     ,log)
        (sqrt    ,sqrt)
        (abs     ,abs)
        (<>      ,(lambda (x y) (not (= x y))))
        (log     ,log)
        (sqrt    ,sqrt)
        (sin     ,sin)
        (cos     ,cos)
        (tan     ,tan)
        (asin    ,asin)
        (acos    ,acos)
        (atan    ,atan)
        (+       ,+)
        (-       ,-)
        (*       ,*)
        (/       ,/)
        (<       ,<)
        (>       ,>)
        (=       ,=)
        (<=      ,<=)
        (>=      ,>=)
     ))

(for-each
    (lambda (pair)
        (hash-set! *functions* (car pair) (cadr pair)))
    `(
        (let     ,let_func)             
        (goto    ,onward)
        (if      ,perhaps)         
        (print   ,print_func)
        (input   ,put-in)        
        (dim     ,dim)
     )
)

(define (statement-parse exec num)
   (when (> (length exec) num)

    (let((to-check (list-ref exec num)))
    (cond
      ((and (= (length to-check) 2) (list? (cadr to-check)))
       (set! to-check (cdr to-check))
       (statement-run (car to-check) exec num))
      ((= (length to-check) 3)
       (set! to-check (cddr to-check))
       (statement-run (car to-check) exec num))
      (else 
        (statement-parse exec (+ num 1)))
    ))))



(define (evalexpr statement) ; 
  (cond
    ((hash-has-key? *var-table* statement)
      (hash-ref *var-table* statement))
    ((number? statement)
      statement)
    ((string? statement)
      statement)

    ((list? statement)
      (if (hash-has-key? *var-table* (car statement))
        (let((top (hash-ref *var-table*  (car statement))))
          (cond 
            ((procedure? top)
             (apply top (map (lambda (x) (evalexpr x)) (cdr statement))))
            ((vector? top)
             (vector-ref top (cadr statement)))
            ((number? top)
             top)
            (else
              (die "Fatal: Broken symbol table."))))
        (die (list "Fatal error: " 
                   (car statement) " not in symbol table!\n"))))))

