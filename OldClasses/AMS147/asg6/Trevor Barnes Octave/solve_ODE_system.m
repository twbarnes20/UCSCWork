#Trevor Barnes
#solve_ODE_system

function solve_ODE_system()
  
  T = 100000;
  IOSTEPS = 50;
  DT = 1e-3;
  y0 = [1 2 3]';
  
  [y,t] = AB3(@(y,t) hw(y,t), y0, DT, T, IOSTEPS);
  
  figure(1), clf
  plot(t, y(1,:), 'r')
  hold
  plot(t, y(2,:), 'b')
  plot(t, y(3,:), 'g')
  
  figure(2), clf
  plot3(y(1,:), y(2,:), y(3,:), 'r')
  grid
  
  function F = hw(y,t)
    F = zeros(3,1);
    F(1) = -y(1) + y(2) * y(3);;
    F(2) = -y(2) + (y(3)-2) * y(1);
    F(3) = 1 - y(1) * y(2);
  end
end