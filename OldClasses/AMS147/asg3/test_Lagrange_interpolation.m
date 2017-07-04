#Trevor Barnes
#test_Lagrange_interpolation.m

function test_Lagrange_interpolation()
  fx = inline("1/(1+(20*x^2))");
  x = linspace(-1, 1, 3000);
  
  #xi, yi, and L vectors for even graph with N = 8 
  xi_even_eight = zeros(9, 1);
  yi_even_eight = zeros(9, 1);
  L_even_eight = zeros(9, 1);
  
  #xi, yi, and L vectors for even graph with N = 20
  xi_even_twenty = zeros(21, 1);
  yi_even_twenty = zeros(21, 1);
  L_even_twenty = zeros(21, 1);
  
  #xi, yi, and L vectors for uneven graph with N = 8
  xi_uneven_eight = zeros(9, 1);
  yi_uneven_eight = zeros(9, 1);
  L_uneven_eight = zeros(9, 1);
  
  #xi, yi, and L vectors for uneven graph with N = 20
  xi_uneven_twenty = zeros(21, 1);
  yi_uneven_twenty = zeros(21, 1);
  L_uneven_twenty = zeros(21, 1);
  
  #Loop fills out values for all different graphs
  for i = 0:20
    if (i <= 8)
      xi_even_eight(i+1) = -1 + 2*(i/8);
      yi_even_eight(i+1) = fx(xi_even_eight(i+1));
      xi_uneven_eight(i+1) = cos((pi/8)*i);
      yi_uneven_eight(i+1) = fx(xi_uneven_eight(i+1));
    endif   
    xi_even_twenty(i+1) = -1 + 2*(i/20);
    yi_even_twenty(i+1) = fx(xi_even_twenty(i+1));
    xi_uneven_twenty(i+1) = cos((pi/20)*i);
    yi_uneven_twenty(i+1) = fx(xi_uneven_twenty(i+1));  
  endfor
  
  #Fill L vector with Lagrangian interpolant
  L_even_eight = Lagrange_interp(xi_even_eight, yi_even_eight, x);
  L_even_twenty = Lagrange_interp(xi_even_twenty, yi_even_twenty, x);
  L_uneven_eight = Lagrange_interp(xi_uneven_eight, yi_uneven_eight, x);
  L_uneven_twenty = Lagrange_interp(xi_uneven_twenty, yi_uneven_twenty, x);
  
  #Plots all four figures
  figure(1), clf, plot(x, L_even_eight, "r")
  hold, fplot(fx, [-1, 1], "b")
  
  figure(2), clf, plot(x, L_even_twenty, "r")
  hold, fplot(fx, [-1, 1], "b")
  
  figure(3), clf, plot(x, L_uneven_eight, "r")
  hold, fplot(fx, [-1, 1], "b")
  
  figure(4), clf, plot(x, L_uneven_twenty, "r")
  hold, fplot(fx, [-1, 1], "b")
  
endfunction