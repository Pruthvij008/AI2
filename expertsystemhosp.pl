% Facts
flight(1, 'New York', 'London', 900).
flight(2, 'London', 'Paris', 200).
flight(3, 'Paris', 'Tokyo', 1500).
% Rules
route(X, Y, Distance) :- flight(_, X, Y, Distance).
route(X, Y, Distance) :- flight(_, X, Z, D1), route(Z, Y, D2), Distance is D1 + D2.
