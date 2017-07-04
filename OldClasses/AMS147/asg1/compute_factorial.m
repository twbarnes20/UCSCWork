#{
Trevor Barnes 

compute_factorial

#}
function b = compute_factorial(n)
  if (n == 0)
    b = 1;
  else
    b = n * compute_factorial(n-1);
  endif
endfunction