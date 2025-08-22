%% https://leetcode.com/problems/pascals-triangle/

-module(pascals_triangle).

-compile(export_all).

-spec generate(NumRows :: integer()) -> [[integer()]].
generate(NumRows) ->
  lists:reverse(inner(NumRows-1, [[1]])).

inner(0, Res) -> Res;
inner(NumRows, [[1]]) -> inner(NumRows-1, [[1,1], [1]]);
inner(NumRows, Res = [H | _]) ->
    inner(NumRows-1, [get_next_arr(H, [1]) | Res]).


get_next_arr([], Res) ->
    Res;
get_next_arr([V1 | [ V2 | V3 ] ], Res ) ->
    get_next_arr([V2 | V3], [V1 + V2 | Res]);
get_next_arr([V1 | _], Res )->
    [V1 | Res].
