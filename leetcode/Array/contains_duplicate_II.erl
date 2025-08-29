%% https://leetcode.com/problems/contains-duplicate-ii/

-module(contains_duplicate_II).

-compile(export_all).

-spec contains_nearby_duplicate(Nums :: [integer()], K :: integer()) -> boolean().
contains_nearby_duplicate(Nums, K) ->
  inner(Nums, K, 0, #{}).

inner([], _K, _Inx, _M = #{}) -> false;
inner([H | T], K, Inx, M = #{}) ->
    % io:format("~p~n", [{[H | T], K, Inx, M}]),
    case M of 
        #{H := LastInx} when (Inx - LastInx) =< K -> true;
        % #{H := WOW} -> io:format("~p~n", [{WOW, Inx - WOW}]), inner(T, K, Inx+1, M);
        _ -> inner(T, K, Inx+1, M#{H => Inx})
    end.
