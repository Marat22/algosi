%% https://leetcode.com/problems/search-insert-position/
-module(search_insert_position).

-export([search_insert/2]).

-spec search_insert(Nums :: [integer()], Target :: integer()) -> integer().
search_insert(Nums, Target) -> search_insert(Nums, Target, 0, length(Nums), 0).

search_insert([First | _Others], Key, _Lower, _Upper, _Res) when First >= Key -> 0;
% search_insert([First | _Others], Key, _Lower, _Upper, _Res) when First >= Key -> 0;
search_insert(_, _Key, Lower, Upper, Res) when Lower > Upper -> Res;
search_insert(A, Key, Lower, Upper, Res) ->
    Mid = Lower + (Upper - Lower) div 2,
    Item = lists:nth(Mid+1, A),
    Last = lists:last(A),
    if
        Last < Key -> Upper;
        Key == Item -> Mid;
        Key < Item -> search_insert(A, Key, Lower, Mid - 1, Mid);
        Key > Item -> search_insert(A, Key, Mid + 1, Upper, Res)
    end.