#{
Trevor Barnes 

pi_series

also includes extra credit

#}
function  pi_series()
  e = [0,0,0,0,0,0,0,0,0,0];
  p = [0,0,0,0,0,0,0,0,0,0];
  
  e(1) = 1;
  #p(1) = ((4/1) - (2/4) - (1/5) - (1/6));
  p(1) = 3.14142;
  
  esum = 1;
  psum = p(1);
  
  for i = 2:10
    e(i) = e(i - 1) + ((1/i^2));
    p(i) = p(i - 1) + ((1/16^i) * ((4/(8*i+1)) - (2/(8*i+4)) - (1/(8*i+5)) - (1/(8*i+6))));
  endfor

  for i = 1:10
    e(i) = sqrt(6) * sqrt(e(i));
  endfor
  
  figure(1), clf, plot(p(1:10), 'r')
  hold, plot(e(1:10), 'b')

  i = 2;
  ptest = abs(pi - p(1));
  while(ptest > 10^(-5))
    psum +=((1/16^i) * ((4/(8*i+1)) - (2/(8*i+4)) - (1/(8*i+5)) - (1/(8*i+6))));
    ptest = abs(pi - psum);
    i++;
  endwhile
  
  i+1;
  disp(['The Plouffe method has an error less than 10^-5 when n = ' num2str(i+1)])
 
  i = 2;
  etest = abs(pi - e(1));
  while(etest > 10^-5)
    esum += (1/(i^2));
    etest = abs(pi - (sqrt(6)*sqrt(esum)));
    i ++;
  endwhile
  
  disp(['Euler method has an error less than 10^-5 when n = ' num2str(i)])
  
endfunction
