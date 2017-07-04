#Trevor Barnes
#test_Lebesgue_function

function [L1, L2, L3, L4] = test_Lebesgue_function()
  fx = inline("1/(1+(20*x^2))");
  x = linspace(-1, 1, 3000);
  
  #xi and L vectors for even graph with N = 8 
  xi_even_eight = zeros(9, 1);
  L_even_eight = zeros(9, 1);
  
  #xi and L vectors for even graph with N = 20
  xi_even_twenty = zeros(21, 1);
  L_even_twenty = zeros(21, 1);
  
  #xi and L vectors for uneven graph with N = 8
  xi_uneven_eight = zeros(9, 1);
  L_uneven_eight = zeros(9, 1);
  
  #xi and L vectors for uneven graph with N = 20
  xi_uneven_twenty = zeros(21, 1);
  L_uneven_twenty = zeros(21, 1);
  
  #Loop fills out xi for all different graphs
  for i = 0:20
    if (i <= 8)
      xi_even_eight(i+1) = -1 + 2*(i/8);
      xi_uneven_eight(i+1) = cos((pi/8)*i);
    endif   
    xi_even_twenty(i+1) = -1 + 2*(i/20);
    xi_uneven_twenty(i+1) = cos((pi/20)*i);
  endfor
  
  #Plots and constants for each graph
  leb_even_8 = plot_Lebesgue_function(xi_even_eight, 1)
  leb_even_20 = plot_Lebesgue_function(xi_even_twenty, 2)
  leb_uneven_8 = plot_Lebesgue_function(xi_uneven_eight, 3)
  leb_uneven_20 = plot_Lebesgue_function(xi_uneven_twenty, 4)
endfunction