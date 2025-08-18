%% https://leetcode.com/problems/length-of-last-word/
    
-module(length_of_last_word).

-export([length_of_last_word/1]).

-spec length_of_last_word(S :: unicode:unicode_binary()) -> integer().
length_of_last_word(S) ->
  length(lists:last(string:tokens(binary_to_list(S), " "))).
