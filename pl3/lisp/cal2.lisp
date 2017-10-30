Title:Lisp Programming
Class: TE'B'
Roll_No:17

(defvar a)
(defvar b)
(defvar c)

(write-line "enter the value of a and b")
(setf a(read))
(setf b(read))

(sb-thread:make-thread
	(lambda()
	  (progn 
		(sleep 0)
		(setf c(+ a b))
		(print "ADDITION in binary: ")
                (format t " ~b" c )
		(print "ADDITION in decimal: ")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	  (progn 
		(sleep 0)
		(setf c(- a b))
		(print "SUBTRCTION in binary: ")
                (format t " ~b" c )
		(print "SUBTRACTION in decimal: ")
		(print c))))
		(terpri)


(sb-thread:make-thread
	(lambda()
	  (progn 
		(sleep 0)
		(setf c(* a b))
		(print "MULTIPLICATION in binary: ")
                (format t " ~b" c )
		(print "MULTIPLICATION in decimal: ")
		(print c))))
		(terpri)

(sb-thread:make-thread	
	(lambda()
	(progn
		(sleep 0)
		(setf c(* a a))
		(print "SQUARE OF FRST in binary: ")
                (format t " ~b" c )
		(print "SQUARE OF FRST in decimal: ")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(* b b))
		(print "SQUARE OF second in binary:")
                (format t " ~b" c )
		(print "SQUARE OF second in decimal:")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(sin a))
		(print "sine of first number in decimal:")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(tan a))
		(print "tan of first number in decimal:")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(cos a))
		(print "cos of first number in decimal:")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(min a b))
		(print "minimum of a and b in binary: ")
                (format t " ~b" c )
		(print "minimum of a and b in decimal: ")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(max a b))
		(print "maximum of a and b in binary: ")
                (format t " ~b" c )
		(print "maximum of a and b in decimal: ")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(+ a 1))
		(print "increment of frst num in binary:")
		(format t "~b" c)
		(print "increment of first number in decimal:")
		(print c))))
		(terpri)

(sb-thread:make-thread
	(lambda()
	(progn
		(sleep 0)
		(setf c(- a 1))
		(print "decrement of frst num in binary:")
		(format t "~b" c)
		(print "decrement of first number in decimal:")
		(print c))))
		(terpri)		
		
		
Output:
* (load "cal2.lisp")
enter the value of a and b
1234567892536412
5421369874563214


"ADDITION in binary: "  1011110100101100011001000110010000010100110011101010
"ADDITION in decimal: " 
6655937767099626 

"SUBTRCTION in binary: "  -1110110111111101111111001100011000100011010000110010
"SUBTRACTION in decimal: " 
-4186801982026802 

1010100011110100110100010000101011010010101101110011010010000000011010100001110110000001101101100001000
"MULTIPLICATION in decimal: " 
6693049180699899385879090748168 

10011001111001101000111011001100100001101010011011000110000110100010001010010101111001100000100010000
"SQUARE OF FRST in decimal: " 
1524157881281797728454745833744 

"SQUARE OF second in binary:"  101110010111110000100000101000100100110000100010011010011000100110101000110101101101100010100111011000100
"SQUARE OF second in decimal:" 
29391251316821558700747282009796 

"sine of first number in decimal:" 
-0.93365854 

"tan of first number in decimal:" 
-2.6067877 

"cos of first number in decimal:" 
0.3581644 

100011000101101010100111100101011111000110001011100
"minimum of a and b in decimal: " 
1234567892536412 

00101011010100001001100100011100000010001110
"maximum of a and b in decimal: " 
5421369874563214 

"increment of frst num in binary:" 100011000101101010100111100101011111000110001011101
"increment of first number in decimal:" 
1234567892536413 

"decrement of frst n
01101010100111100101011111000110001011011
"decrement of first number in decimal:" 
1234567892536411  


