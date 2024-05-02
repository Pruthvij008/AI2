greeting([hello, hi, hi]).

response(hello, ['hello', 'how are you?']).
response(hi, ['hi there', 'how do you do?']).
response(hi, ['hey', 'who']).

response('what is the date', [Date]) :-
    get_time(Time),
    format_time(atom(Date), '%D', Time).

response(_, ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']).

respond(Query, Response) :-
    (var(Query) -> 
        Response = ['I am not sure what you mean...', 'Could you please rephrase that?', 'I am just a simple chatbot...', 'I am not equipped to answer that.']
    ; response(Query, Response), !
    ).

chat :-
    write('Chatbot: Hello! How can I help you?'), nl,
    repeat,
    write('You: '),
    read_line_to_codes(user_input, Input),
    atom_codes(Query, Input),
    (Query = bye -> write('Chatbot: Goodbye!'); 
    (greeting(Query) -> random_member(Greeting, Query), write('Chatbot: '), write(Greeting), nl; 
    respond(Query, Response), random_member(Reply, Response), write('Chatbot: '), write(Reply), nl, fail)),
    Query = bye, !.
