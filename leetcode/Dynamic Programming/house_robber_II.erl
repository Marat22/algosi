%% https://leetcode.com/problems/house-robber-ii/

-module(house_robber_II).

-compile(export_all).

-spec rob(Nums :: [integer()]) -> integer().
rob(_Nums = [H | _]) when length(_Nums) == 1 ->
    H;
rob(_Nums = [H | T]) ->
    max(
        rob(T, []),
        rob(drop_last_element(T), [H])
    ).

drop_last_element(A) -> lists:reverse(tl(lists:reverse(A))).

rob([], [V1 | [V2 | _]]) ->
    max(V1, V2);
rob([], [V1 | _]) ->
    V1;
rob(_Nums = [H | T], Arr) ->
    NextVal = case Arr of
        [] -> H; %% empty arr
        [_ | [V1 | [V2 | _]]] -> H + max(V1, V2);  %% >3 elements in arr
        [_ | [V1 | _]] -> H + V1;  %% 2 elements in arr
        [_ | _] -> H  %% 1 element in arr
    end,
    rob(T, [NextVal | Arr]).
