%% https://leetcode.com/problems/add-binary/
-module(add_binary).

-compile(export_all).

-spec add_binary(A :: unicode:unicode_binary(), B :: unicode:unicode_binary()) -> unicode:unicode_binary().
add_binary(A, B) ->
  list_to_binary(
            inner(lists:reverse(binary_to_list(A)), lists:reverse(binary_to_list(B)), "", 0)
). 

inner([], [], Res, Add) ->
    case Add of
        1 -> [$1 | Res];
        0 -> Res
    end;
inner([H1 | T1], [], Res, Add) ->
    % io:format("~p", [H1]), ""%  ,
    Sum = get_num(H1) + Add,
    case Sum of
        2 -> inner(T1, [], [$0 | Res], 1);
        _ -> inner(T1, [], [get_char(Sum) | Res], 0)
    end;
inner([], [H2 | T2], Res, Add) ->
    Sum = get_num(H2) + Add,
    case Sum of
        2 -> inner([], T2, ["0" | Res], 1);
        _ -> inner([], T2, [get_char(Sum) | Res], 0)
    end;
inner([H1 | T1], [H2 | T2], Res, Add) ->
    Sum = get_num(H1) + get_num(H2) + Add,
    case Sum of
        3 -> inner(T1, T2, ["1" | Res], 1);
        2 -> inner(T1, T2, ["0" | Res], 1);
        _ -> inner(T1, T2, [get_char(Sum) | Res], 0)
    end.

get_num($1) ->
    1;
get_num($0) ->
    0.

get_char(1) ->
    $1;
get_char(0) ->
    $0.
