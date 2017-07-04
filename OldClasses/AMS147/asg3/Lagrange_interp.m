#Trevor Banres
#Lagrange_interp.m

function [y] = Lagrange_interp(xi, yi, x)
  n = length(xi);
  m = length(x);
  L = ones(n,m);
  y = 0;
  
  for i = 1:n
    for j = 1:n
      if (j != i)
        L(i,:) = (L(i,:).*(x - xi(j)))/(xi(i) - xi(j));
      endif
    endfor
  endfor
  
  for i=1:n
    y = y + yi(i)*L(i,:);
  end
endfunction