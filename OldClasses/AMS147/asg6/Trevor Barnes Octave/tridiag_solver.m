#Trevor Barnes
#tridiag_solver.m

function x = tridiag_solver( e, a, c, b )

  n = length(e);
  temp = zeros(n,1);   
  x = zeros(n,1);
  m = e(1);
  x(1) = b(1)/m;
  
  for k = 2:n
    temp(k - 1) = c(k - 1) / m;
    m = e(k) - a(k) * temp(k - 1);
    x(k) = (b(k) - a(k) * x(k - 1)) / m;
  endfor
  
  for k = (n - 1):-1:1
    x(k) = x(k) - temp(k) * x(k + 1);
  endfor
  
endfunction