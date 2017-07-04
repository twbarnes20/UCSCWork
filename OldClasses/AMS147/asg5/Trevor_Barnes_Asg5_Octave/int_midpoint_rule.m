#Trevor Barnes
#Composite Midpoint Rule

function [I] = int_midpoint_rule(fun, a, b, n)
  x = zeros(n, 1);
  xbar = zeros(n, 1);
  I = 0;
  h = (b - a) / (n - 1);
  
  for i = 1:n
    x(i) = a + (i - 1) * h;
  endfor
  
  for i = 2:n
    xbar(i) = (x(i) + x(i - 1)) / 2 ;
    I = I + fun(xbar(i));
  endfor
  
  I = h * I;

endfunction