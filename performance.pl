% Define facts about employees and their performance
employee(john).
employee(sarah).
employee(mike).

performance(john, excellent).
performance(sarah, good).
performance(mike, average).

% Define rules for evaluating performance

% Rule 1: Determine if an employee's performance is excellent
excellent_performance(Employee) :-
    performance(Employee, excellent).

% Rule 2: Determine if an employee's performance is good
good_performance(Employee) :-
    performance(Employee, good).

% Rule 3: Determine if an employee's performance is average
average_performance(Employee) :-
    performance(Employee, average).

% Rule 4: Recommend actions based on performance
recommend_action(Employee) :-
    performance(Employee, excellent),
    write('Excellent performance! Keep up the good work.').
recommend_action(Employee) :-
    performance(Employee, good),
    write('Good performance! Keep striving for improvement.').
recommend_action(Employee) :-
    performance(Employee, average),
    write('Average performance. Identify areas for improvement and set goals to enhance performance.').

% Example usage:
% ?- excellent_performance(john).
% ?- recommend_action(sarah).
