MACHINE 
   ExempleTD

VARIABLES
   xx, yy

INVARIANT
   xx: NATURAL & yy : NATURAL & xx > yy

INITIALISATION
   xx:=1 || yy:=0

OPERATIONS

incr = 
   CHOICE
      xx:=xx+1
   OR
      IF xx=yy+1 
          THEN yy:=yy
          ELSE yy:=yy+1
      END
   END ;

reset =
   ANY nx, ny WHERE 
       nx : NAT & ny : NAT & nx>ny
   THEN
       xx:=nx || 
       yy:=ny
   END
   
END
