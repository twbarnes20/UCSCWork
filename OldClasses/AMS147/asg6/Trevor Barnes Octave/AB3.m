#Trevor Barnes
#AB3.m

function [y, t] = AB3(fun, y0, DT, T, IOSTEP)
  
  y = y0;
  t0 = 0;
  t = 0;
  
  y1 = y0 + DT/2 * (fun(y0+DT*fun(y0,t0), t0 + DT) + fun(y0,t0));
  t1 = t0 + DT;
  
  y2 = y1 + DT/2 * (fun(y1+DT*fun(y1,t1), t1 + DT) + fun(y1,t1));
  t2 = t1 + DT;
  
  for i = 2:T
    y3 = y2 + DT/12 * (23 * fun(y2,t2) - 16 * fun(y1,t1) + 5 * fun(y0,t0));
    t3 = t2 + DT;
    
    y0 = y1;
    y1 = y2;
    y2 = y3;
    t0 = t1;
    t1 = t2;
    t2 = t3;
    
    if mod(i, IOSTEP) == 0
      y = [y y3];
      t = [t t3];
    end
  endfor
      