#Trevor Barnes
#Composite Trapezoidal Rule

function [I] = int_trapezoidal_rule(fun, a, b, n)
  x = zeros(n, 1);
  I = 0;
  h = (b - a) / (n - 1);
  
  for i = 1:n
    x(i) = a + (i - 1) * h;
  endfor
 
  for i = 2:n 
    I = I + ((fun(x(i - 1)) + fun(x(i))) / 2);  
  endfor
  
  I = h * I;
endfunction