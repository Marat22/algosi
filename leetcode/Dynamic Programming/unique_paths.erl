%% https://leetcode.com/problems/unique-paths/

-module(unique_paths).

-spec unique_paths(M :: integer(), N :: integer()) -> integer().
unique_paths(M, N) ->
    unique_paths(M-1, N, lists:duplicate(N, 1)).

unique_paths(0, _, DP) -> lists:last(DP);
unique_paths(M, N, DP) -> 
    unique_paths(M-1, N, get_next_dp(DP)).

get_next_dp(DP) -> lists:reverse(get_next_dp(DP, [])).

get_next_dp(_DP = [], Res) -> Res;
get_next_dp(_DP = [H | T], []) ->
    get_next_dp(T, [H | []]);
get_next_dp(_DP = [H | T], Res = [LeftVal | _]) ->
    NextVal = LeftVal + H,
    get_next_dp(T, [NextVal | Res]).
