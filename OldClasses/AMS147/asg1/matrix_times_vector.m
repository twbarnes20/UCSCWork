#{
Trevor Barnes 

matrix_times_vector

#}

function [y] = matrix_times_vector(A, x)
  
  y = zeros(size(A), 1);

  for i = 1:rows(A)
    for j = 1:rows(x)
      y(i) = A(i, j) * x(j) + y(i);
    endfor
  endfor

endfunction