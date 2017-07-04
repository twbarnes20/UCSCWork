#Trevor Barnes
#test_least_squares_interp.m

function test_least_squares_interp()
  x = zeros(16, 1);
  y = zeros(16, 1);
  domain = linspace(0, 1, 1000);
  sum = size(x);
  
  for i = 1:16
   x(i) = -1 + 2*((i-1)/15);
   y(i) = 1/(2 + sin(20*(x(i))^2));
  endfor
  
  a = poly_least_squares(x, y, 15);
  
  for i = 1:size(x)
    sum(i) = polyval(a, x(i));
  endfor
  
  figure(1), clf, plot(sum, 'r')
  hold, plot(1:16, y, 'bo')
endfunction