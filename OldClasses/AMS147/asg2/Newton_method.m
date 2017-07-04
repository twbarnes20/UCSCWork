#Trevor Barnes 
#Newton method function

function [z0, iter, res, his] = Newton_method(fun, dfun, x0, tol, Nmax)
  his = zeros(Nmax, 1);
  his(1) = x0 - (1/(dfun(x0))) * fun(x0);
  his(2) = his(1) - (1/(dfun(his(1)))) * fun(his(1));
  iter = 2;
  
  while (abs(his(iter) - his(iter - 1)) >= tol && iter < Nmax)
   his(iter+1) = his(iter) - (1/(dfun(his(iter)))) * fun(his(iter));
   iter++;
  endwhile
  disp("\nNewton Method")
  z0 = his(iter)
  res = abs(fun(z0))
  iter
endfunction