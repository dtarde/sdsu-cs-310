; p6.scm
; Four Scheme functions that parse through lists 
; Dalton Tarde
; CS-320 Section 1
; December 8th 2020 
; @author Dalton Tarde cssc2670 

; File has only be edited for documentation and function definitions.
; The rest of this file has been unchanged.

; Defined lists for use during unit tests 
(define list0 (list 'j 'k 'l 'm 'n 'o 'j) )
(define list1 (list 'a 'b 'c 'd 'e 'f 'g) )
(define list2 (list 's 't 'u 'v 'w 'x 'y 'z) )
(define list3 (list 'j 'k 'l 'm 'l 'k 'j) )
(define list4 (list 'n 'o 'p 'q 'q 'p 'o 'n) )
(define list5 '((a b) c (d e d) c (a b)) )
(define list6 '((h i) (j k) l (m n)) ) 
(define list7 '(f (a b) c (d e d) (b a) f) )

; Sebesta Chapter 15 Example Function 
(define (adder lis)
  (cond
      ((null lis) 0)
      	(else (+ (car lis) (adder (cdr lis))))
      ))

(define (evens lis)
  (if (or (null? lis)             ; case 1: check for non-existent or empty list 
          (null? (cdr lis))) '()  ; case 2: check for list of one element                          
      (cons (cadr lis)            ; build pairs
            (evens (cddr lis))))) ; recurse through list evenly 

(define (oddrev lis)
  (if (or (null? lis)             ; case 1: check for non-existent or empty list 
          (null? (cdr lis))) lis  ; case 2: check for list of one element (edge case)              
      (append (oddrev (cddr lis))
        (list (car lis)))))       ; recurse odds in reverse

(define (middle lis)
  (if (or (null? lis)               ; case 1: check for non-existent or empty list 
          (null? (cdr lis))) lis    ; case 2: check for list of one element             
      (let loop ((p1 lis)           ; code adapted from GitHub user: Chris Jester-Young 
                 (p2 (cdr lis)))
        (cond ((eq? p1 p2) #f)      ; case 3: boolean return
              ((null? p2) (list (car p1)))
              ((null? (cdr p2))'()) ; case 4: odd number of elements 
              (else (loop (cdr p1) (cddr p2)))))))

(define (bookends lis)
  (define (bookendshelper element lis)
    (if (null? (cdr lis))                     ; empty list condition
        (equal? element (car lis))
        (bookendshelper element (cdr lis))))
  (if (or (not (list? lis)) (null? lis))
  "()"                                        ; return () if empty, or #t/#f
  (bookendshelper (car lis) lis)))            ; recursion through helper function