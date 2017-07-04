#Trevor Barnes
#Composite Simpson Rule

function [I] = int_Simpson_rule(fun, a, b, n)
  x = zeros(n, 1);
  xbar = zeros(n, 1);
  I = 0;
  h = (b - a) / (n - 1);
  
  for i = 1:n
    x(i) = a + (i - 1) * h;
  endfor
  
  for i = 2:n      
    xbar(i) = (x(i) + x(i - 1)) / 2 ;
    I = I + (fun(x(i - 1)) + (4 * fun(xbar(i))) + fun(x(i)));
  endfor
  
  I = (h / 6) * I;
endfunction