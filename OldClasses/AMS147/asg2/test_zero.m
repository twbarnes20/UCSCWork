#Trevor Barnes 
#test zero function

function [zc, zn] = test_zero()
 warning('off','all');
  fx = inline("16*x^5 - 20*x^3 + 5*x");
  dx = inline("80*x^4 - 60*x^2 + 5");
  [zc_z0, zc_iter, zc_res, zc_his] = chord_method(fx, -0.99, -0.9, 10^(-15), 20000);
  [zn_z0, zn_iter, zn_res, zn_his] = Newton_method(fx, dx, -0.99, 10^(-15), 20000);

  figure(1), clf, plot(zc_his(1:zc_iter), 'r')
  hold, plot(zn_his(1:zn_iter), 'b')
  
  zc_error = zeros(zc_iter + 1, 1);
  zn_error = zeros(zn_iter + 1, 1);
  
  for i = 1:zc_iter
    zc_error(i) = abs(zc_his(i) - zc_z0);
  endfor
  
  for i = 1:zn_iter
    zn_error(i) = abs(zn_his(i) - zn_z0);
  endfor
  
  figure(2), clf, semilogy(zc_error(1:zc_iter), 'r')
  hold, semilogy(zn_error(1:zn_iter), 'b')
  
  figure(3), clf, loglog(zc_error(1:zn_iter - 1), zc_error(2:zn_iter))
  hold, loglog(zn_error(1:zn_iter), zn_error(2:zn_iter + 1))
endfunction