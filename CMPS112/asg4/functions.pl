% Kevin Cai (kcai2@ucsc.edu)
% Trevor Barnes (trwbarne@ucsc.edu)

/*
 * Prolog - not
 */
not(X) :- X, !, fail.
not(_).

/*
 * Returns time in hours
 */
totalHours(time(Hours, Mins), HoursAir) :-
    HoursAir is Hours + Mins / 60.

/*
 * Converts to measurements we need
 * for formulas
 */
convert_radians(degmin(Degrees, Minutes), Rads) :-
    Degs is Degrees + Minutes / 60,
    Rads is Degs * pi / 180.
 
/*
 * Converts the flight miles into time.
 * Plane flies at the constant speed of 500mph
 * as stated in assignment specs
 */
miles2hours(Miles, Hours) :-
    Hours is Miles / 500.

/* Haversine formula used to compute
 * great circle distance between points
 * on a sphere, in this case Earth
 */
haversine(LatA, LonA, LatB, LonB, Distance) :-
    Dlon is LonB - LonA,
    Dlat is LatB - LatA,
    A is sin(Dlat / 2) ** 2 + cos(LatA) * cos(LatB) * sin(Dlon / 2) ** 2,
    Dist is 2 * atan2(sqrt(A), sqrt(1 - A)),
    Distance is Dist * 3961. 

/*
 * Gives distance between airports
 */
airportDist(Airport1, Airport2, Distance) :-
    airport(Airport1, _, LatA, LonA),
    airport(Airport2, _, LatB, LonB),
    %converts latA/latB & lonA/lonB to radians
    convert_radians(LatA, Lat1_float),
    convert_radians(LonA, Lon1_float),
    convert_radians(LatB, Lat2_float),
    convert_radians(LonB, Lon2_float),
    haversine(Lat1_float, Lon1_float, Lat2_float, Lon2_float, Distance).

/*
 * Finds a path between two airports.
 * Flights must take place in a single day
 * Each transfer or layover takes exactly 30
 * minutes. 
 */
flightPlan(Terminal, Terminal, _, [Terminal], _).
flightPlan(Previous, Terminal, BeenHere,
    [[Previous, FlightDepart, FlightArrival] | List], TimetoFlight) :-
    flight(Previous, Terminal, TimetoFlight),
    not(member(Terminal, BeenHere)),
    totalHours(TimetoFlight, FlightDepart),
    airportDist(Previous, Terminal, FDist),
    miles2hours(FDist, TimeDiff),
    FlightArrival is FlightDepart + TimeDiff,
    FlightArrival < 24.00,
    flightPlan(Terminal, Terminal, [Terminal | BeenHere], List, _).

flightPlan(Previous, Terminal, BeenHere, 
    [[Previous, FlightDepart, FlightArrival] | List], TimetoFlight) :-
    flight(Previous, Next, TimetoFlight),
    not(member(Next, BeenHere)),
    totalHours(TimetoFlight, FlightDepart),
    airportDist(Previous, Next, FDist),
    miles2hours(FDist, TimeDiff),
    FlightArrival is FlightDepart + TimeDiff,
    FlightArrival < 24.00,
    flight(Next, _, TimetoNextFlight),
    totalHours(TimetoNextFlight, NextFlightDepart),
    AdjTime is NextFlightDepart - FlightArrival - 0.5,
    AdjTime >= 0,
    flightPlan(Next, Terminal, [Next | BeenHere], 
                                        List, TimetoNextFlight).

/*
 * Prints out the flight path found previously
 */
flightPath([]) :-
    nl.

% connecting flight from X to Y then to Z
% & print out schedule
flightPath([[X, XDeparture, XArrival], Y | []]) :-
    airport(X, DepartX, _, _), airport(Y, ArriveX, _, _),
    write('   '), write('Depart from:  '), write(X), write('   '),
    write(DepartX), printTime(XDeparture), nl,
    write('   '), write('Arrive at:    '), write(Y), write('   '),
    write(ArriveX), printTime(XArrival), nl, !, true.

% from airport Y to Z
flightPath([[X, XDeparture, XArrival], [Y, YDeparture, YArrival] | Z]):-
    airport(X, DepartX, _, _), airport(Y, ArriveX, _, _),
    write('   '), write('Depart from:  '), write(X), write('   '),
    write(DepartX), printTime(XDeparture), nl,
    write('   '), write('Arrive at:    '), write(Y), write('   '),
    write(ArriveX), printTime(XArrival), nl,
    !, flightPath([[Y, YDeparture, YArrival] | Z]).

/*
 * Prints various pieces of data
 */
printDigit(Timedigits) :-
    Timedigits < 10, print(0), print(Timedigits).

printDigit(Timedigits) :-
    Timedigits >= 10, print(Timedigits).

printTime(HoursAir) :-
    AirMins is floor(HoursAir * 60),
    Hours is AirMins // 60,
    Mins is AirMins mod 60,
    %print time
    printDigit(Hours), print(':'), printDigit(Mins).

/*
 * Print statements for flights,
 * along with errors for flights that are invalid.
 */
% sometimes doesnt print correctly ???? 
% Same airport error
fly(Depart, Depart) :-
    write('Error: Departure and arrival are at the same airport! '),
    nl,
    !, fail.

% print the flights with depart & arrival time
fly(Depart, Arrive) :-
    airport(Depart, _, _, _ ),
    airport(Arrive, _, _, _ ),
    flightPlan(Depart, Arrive, [Depart], List, _), !, nl,
    flightPath(List),
    true.

% no flights error
fly(Depart, Arrive) :-
    airport(Depart, _, _, _),
    airport(Arrive, _, _, _),
    write('Error: We could not find you a flight. Try a bus?'),
    !, fail.

% no airport error
fly(_, _) :-
    write('Error: This airport does not exist.'), nl,
!, fail.
