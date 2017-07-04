#Trevor Barnes 
#chord method function

function [z0, iter, res, his] = chord_method(fun, a, b, tol, Nmax)
  his = zeros(Nmax, 1);
  q = (fun(b) - fun(a)) / (b-a);
  his(1) = a - fun(a)/(fun(b) - fun(a)) * (b-a);
  his(2) = his(1) - (1/q) * fun(his(1));
  iter = 2;
 
  while (abs(his(iter) - his(iter - 1)) >= tol && iter < Nmax)
   his(iter+1) = his(iter) - ((1/q) * fun(his(iter)));
   iter++;
  endwhile
  disp("\nChord Method")
  z0 = his(iter)
  res = abs(fun(z0))
  iter
endfunction