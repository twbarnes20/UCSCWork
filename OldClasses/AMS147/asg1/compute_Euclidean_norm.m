#{
Trevor Barnes 

compute_Euclidean_norm

#}
function [z] = compute_Euclidean_norm(x)
  sum = 0
  for i = 1:length(x)
    sum = sum + x(i).^2;
  endfor
  
  z = sqrt(sum);
  
endfunction