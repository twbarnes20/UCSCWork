#Trevor Barnes
#poly_least_squares.m

function [a, err] = poly_least_squares(x, y, M)

  a = zeros(M);
  psy = zeros(M);
  N = length(x);
  err = 0;

  x = x(:);
  y = y(:);

  V(:,M+1) = ones(length(x),1);
  for j = M:-1:1
    V(:,j) = x.*V(:,j+1);
  end

  [Q,R] = qr(V,0);
  a = R\(Q'*y);    
  r = y - V*a;
  a = a.';
  
  for k = 1:N
    err = err + (y(k) - polyval(a, (y(k))))^2;
  endfor
endfunction