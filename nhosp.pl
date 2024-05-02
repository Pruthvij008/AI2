% Facts
patient(john, fever).
patient(emma, fracture).
patient(sam, cough).
patient(lisa, headache).
doctor(jane, fever, 'New York').
doctor(eric, fracture, 'Paris').
doctor(alice, cough, 'London').
doctor(michael, headache, 'Berlin').
treatment(fever, 'Rest and fluids').
treatment(fever, 'Antipyretics').
treatment(fracture, 'Cast').
treatment(fracture, 'Painkillers').
treatment(cough, 'Cough syrup').
treatment(cough, 'Antibiotics').
treatment(headache, 'Painkillers').
treatment(headache, 'Rest').
% Rules
assign_doctor(Patient, Doctor) :- patient(Patient, Condition), doctor(Doctor, Condition, _).
available_treatment(Condition, Treatment) :- treatment(Condition, Treatment).
