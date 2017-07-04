#Trevor Barnes
#test_least_squares_finance.m

function test_least_squares_finance()
  data = load('Dow_Jones_2012_2017.dat');
  x = data(:, 1);
  y = data(:, 2);
  s1 = zeros(size(x));
  s2 = zeros(size(x));
  s4 = zeros(size(x));
  s8 = zeros(size(x));
 
  a1 = poly_least_squares(x, y, 1);
  a2 = poly_least_squares(x, y, 2);
  a4 = poly_least_squares(x, y, 4);
  a8 = poly_least_squares(x, y, 8);

  for i = 1:size(x)
    s1(i) = a1(2) + a1(1) * x(i);
    s2(i) = a2(3) + a2(2) * x(i) + a2(1) * x(i)^2;
    s4(i) = a4(5) + a4(4) * x(i) + a4(3)* x(i)^2 + a4(2)* x(i)^3 + a4(1) * x(i)^4;
    s8(i) = a8(9) + a8(8)*x(i) + a8(7)*x(i)^2 + a8(6)*x(i)^3 + a8(5)*x(i)^4 + ...
            a8(4)*x(i)^5 + a8(3)*x(i)^6 + a8(2)*x(i)^7 + a8(1) * x(i)^8;
  endfor
  
  figure(1), clf, plot(s1)
  hold, plot(1:size(x), y, "r")
  
  figure(2), clf, plot(s2)
  hold, plot(1:size(x), y, "r")
  
  figure(4), clf, plot(s4)
  hold, plot(1:size(x), y, "r")
  
  figure(8), clf, plot(s8)
  hold, plot(1:size(x), y, "r")
endfunction