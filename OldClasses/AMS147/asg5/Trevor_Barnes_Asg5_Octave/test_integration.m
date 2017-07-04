#Trevor Barnes
#test_integration

function test_integration()
  fun = inline("(1/(1 + x^2)) * (cos((3/2) * e^(-x^2))) - (x ^ 3 / 30)");
  I = 1.6851344770476;
  a = -3;
  b = 1;
  n = 1:99;

  Im = zeros(99, 1);
  It = zeros(99, 1);
  Is = zeros(99, 1);
  
  int_midpoint_rule(fun, a, b, 2)
  
  for i = 2:100
    Im(i - 1) = abs(I - int_midpoint_rule(fun, a, b, i));
    It(i - 1) = abs(I - int_trapezoidal_rule(fun, a, b, i));
    Is(i - 1) = abs(I - int_Simpson_rule(fun, a, b, i));
    
  endfor
  
  figure(1), fplot(fun, [-3, 1])
  figure(2), clf, loglog(Im,  'b')
  hold, loglog(It, 'r'), loglog(Is, 'g')
  
endfunction