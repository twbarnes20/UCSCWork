#Trevor Barnes
#plot_Lebesque_function.m

function [L] = plot_Lebesgue_function(xi, num)
  x = linspace(min(xi), max(xi), 100);
  n = length(xi);  
  p = ones(n, length(x));
  leb_fun = zeros(n, 1);
  sum = 0;
  
  for i = 1:n
    for j = 1:n
      if j != i
        p(i,:) = p(i,:) .* (x - xi(j))/(xi(i) - xi(j));
      endif
    endfor
  endfor
 
  for i = 1:n
    for j = 1:length(x)
      sum = sum + p(i,j);
    endfor
    leb_fun(i) = sum;
    sum = 0; 
  endfor
  
  L = max(leb_fun);
  
  figure(num), clf, plot(leb_fun)
  
endfunction